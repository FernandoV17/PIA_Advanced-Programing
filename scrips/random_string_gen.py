import random
from pathlib import Path
import time
import shutil
from tqdm import tqdm

def remove_pycache():
    pycache_path = Path("scrips/__pycache__")
    try:
        if pycache_path.exists():
            shutil.rmtree(pycache_path)
            print("\nDirectorio __pycache__ eliminado")
    except Exception as e:
        print(f"\nError al limpiar __pycache__: {e}")

def dna_gen(longitud, chunk_size=1_000_000):
    bases = ('A', 'T', 'C', 'G')
    remaining = longitud
    while remaining > 0:
        current_chunk = min(remaining, chunk_size)
        yield ''.join(random.choices(bases, k=current_chunk))
        remaining -= current_chunk

def main():
    print("Generador de secuencias aleatorias de ADN")
    while True:
        try:
            longitud = int(input("¿Cuántos caracteres debe tener la secuencia? "))
            if longitud <= 0:
                print("Por favor ingrese un número positivo.")
                continue
            break
        except ValueError:
            print("Por favor ingrese un número válido.")
        except KeyboardInterrupt:
            print("\nEntrada cancelada por el usuario.")
            remove_pycache()
            return

    directorio = Path("./data/input/")
    directorio.mkdir(parents=True, exist_ok=True)
    archivo = directorio / "data.txt"

    pbar = tqdm(total=longitud, unit='bases', unit_scale=True,
                desc="Generando secuencia", leave=True)

    try:
        with open(archivo, 'w') as f:
            start_time = time.time()

            for chunk in dna_gen(longitud):
                f.write(chunk)
                pbar.update(len(chunk))
                time.sleep(0.001)

        tiempo_total = time.time() - start_time
        pbar.close()

        print(f"\nSecuencia de {longitud:,} caracteres generada en {tiempo_total:.2f} segundos")
        print(f"Guardada en: {archivo.resolve()}")

    except KeyboardInterrupt:
        pbar.close()
        print("\n\nGeneración interrumpida por el usuario.")
        print(f"Se escribieron {pbar.n:,} caracteres antes de la interrupción.")

        try:
            respuesta = input("¿Desea conservar el archivo parcial? (s/n): ").lower()
            if respuesta != 's':
                archivo.unlink()
                print("Archivo parcial eliminado.")
        except:
            pass
    finally:
        remove_pycache()

if __name__ == "__main__":
    main()
