import random
from pathlib import Path

def generar_secuencia_adn(longitud):
    bases = ['A', 'T', 'C', 'G']
    return ''.join(random.choices(bases, k=longitud))

def main():
    print("Generador de secuencias aleatorias de ADN")
    print("---------------------------------------")

    while True:
        try:
            longitud = int(input("¿Cuántos caracteres debe tener la secuencia? "))
            if longitud <= 0:
                print("Por favor ingrese un número positivo.")
                continue
            break
        except ValueError:
            print("Por favor ingrese un número válido.")

    secuencia = generar_secuencia_adn(longitud)

    directorio = Path("./data/input/")
    directorio.mkdir(parents=True, exist_ok=True)

    archivo = directorio / "data.txt"
    with open(archivo, 'w') as f:
        f.write(secuencia)

    print(f"\nSecuencia de {longitud} caracteres generada y guardada en:")
    print(f"{archivo.resolve()}")

if __name__ == "__main__":
    main()
