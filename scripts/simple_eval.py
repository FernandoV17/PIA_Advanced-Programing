import os
import time
import subprocess
from random_string_gen import main as string_gen

FILE_PATH = "./data/input/data.txt"
EXECUTABLE_PATH = "./builds/main"

def main():
    print("\n¿Qué archivo de datos desea usar?")
    print("1. Usar archivo existente (data.txt)")
    print("2. Generar nuevo archivo de datos")

    while True:
        opcion = input("Seleccione (1/2): ").strip()
        if opcion in ['1', '2']:
            break
        print("Opción no válida. Ingrese 1 o 2.")

    if opcion == '2':
        print("\nGenerando nuevo archivo de datos...")
        print("\n")
        string_gen()

    if not os.path.exists(FILE_PATH):
        print(f"\nError: No se encontró {FILE_PATH}")
        return

    if not os.path.exists(EXECUTABLE_PATH):
        print(f"\nError: No se encontró {EXECUTABLE_PATH}")
        return

    print(f"\nArchivo de datos: {os.path.abspath(FILE_PATH)}")
    print(f"Tamaño: {os.path.getsize(FILE_PATH)} bytes")
    print(f"Ejecutando: {os.path.abspath(EXECUTABLE_PATH)}")

    try:
        inicio = time.perf_counter()
        subprocess.run(
            [EXECUTABLE_PATH],
            check=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        tiempo = time.perf_counter() - inicio

        print(f"\nTiempo de ejecución: {tiempo:.6f} segundos")

    except subprocess.CalledProcessError as e:
        print(f"\nError en ejecución (código {e.returncode}):")
        if e.stderr:
            print(e.stderr)
    except Exception as e:
        print(f"\nError inesperado: {str(e)}")

if __name__ == "__main__":
    main()
