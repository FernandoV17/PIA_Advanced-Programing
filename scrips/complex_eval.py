import random
import os
import time
import subprocess
import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
from tqdm import tqdm

N_ITERATIONS = 1_000
FILE_PATH = "./data/input/data.txt"
EXECUTABLE_PATH = "./builds/main"
BASES = ('A', 'T', 'C', 'G')    # Tupla inmutable

os.makedirs(os.path.dirname(FILE_PATH), exist_ok=True)

if not os.path.exists(EXECUTABLE_PATH):
    raise FileNotFoundError(f"El ejecutable '{EXECUTABLE_PATH}' no existe.")

plt.ion()
fig, ax = plt.subplots(figsize=(10, 6))
ax.set_xlabel("Tamaño del archivo (caracteres)")
ax.set_ylabel("Tiempo de ejecución (s)")
ax.set_title("Tiempo de ejecución vs Tamaño del archivo")
ax.grid(True)
line, = ax.plot([], [], 'b-')
fig.show()

# Pre-allocación de arrays numpy para mejor performance
x_data = np.zeros(N_ITERATIONS, dtype=np.int32)
y_data = np.zeros(N_ITERATIONS, dtype=np.float32)

total_time = 0.0
random_choices = random.choices  # Cachear método

try:
    with tqdm(range(1, N_ITERATIONS + 1), desc="Progreso", unit="iter") as pbar:
        for i, n in enumerate(pbar):
            random_sequence = ''.join(random_choices(BASES, k=n))

            with open(FILE_PATH, 'w') as f:
                f.write(random_sequence)

            start_time = time.perf_counter()
            subprocess.run(
                [EXECUTABLE_PATH],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                check=True
            )
            elapsed_time = time.perf_counter() - start_time
            total_time += elapsed_time

            x_data[i] = n
            y_data[i] = elapsed_time

            if i % 100 == 0 or i == N_ITERATIONS - 1:
                line.set_data(x_data[:i+1], y_data[:i+1])
                ax.relim()
                ax.autoscale_view()
                fig.canvas.draw()
                fig.canvas.flush_events()
                pbar.set_postfix_str(f"Último: {elapsed_time:.6f}s")

except KeyboardInterrupt:
    print("\nEjecución interrumpida por el usuario.")
except subprocess.CalledProcessError as e:
    print(f"\nError al ejecutar el programa: {e}")
finally:
    plt.ioff()
    fig.savefig('scrips/output/final_plot.png')
    np.savez('execution_data.npz', x_data=x_data, y_data=y_data)

    plt.title("Resultado Final - Tiempo vs Tamaño")
    plt.show(block=True)
    print(f"¡Ejecución completada! Tiempo total: {total_time:.2f}s")
