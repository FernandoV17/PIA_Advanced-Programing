#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "./lib/merge_sort/merge_sort.h"
#include "./lib/counting/counting.h"

void leerSecuenciaADN(const std::string& ruta, std::vector<char>& secuencia) {
    std::ifstream archivo(ruta, std::ios::binary);
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + ruta);
    }

    std::string contenido((std::istreambuf_iterator<char>(archivo)),
                         std::istreambuf_iterator<char>());

    for (char c : contenido) {
        c = toupper(c);
        if (isalpha(c)) {
            secuencia.push_back(c);
        }
    }
    archivo.close();
}

void guardarSecuenciaOrdenada(const std::string& ruta, const std::vector<char>& secuencia) {
    std::ofstream archivo(ruta, std::ios::binary);
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo crear el archivo: " + ruta);
    }

    const size_t bloque_size = 4096;
    size_t pos = 0;
    while (pos < secuencia.size()) {
        size_t bloque_actual = std::min(bloque_size, secuencia.size() - pos);
        archivo.write(&secuencia[pos], bloque_actual);
        pos += bloque_actual;
    }
    archivo.close();
}

void mostrarConteo(const CountResult& resultado) {
    std::cout << "\n=== CONTEO DE NUCLEÓTIDOS ===\n";
    std::cout << "TOTAL: " << resultado.total << "\n";

    const std::vector<char> orden = {'A', 'T', 'C', 'G', 'U'};
    for (char base : orden) {
        if (resultado.counts.find(base) != resultado.counts.end()) {
            std::cout << base << " (" << resultado.names.at(base) << "): "
                      << resultado.counts.at(base) << "\n";
        }
    }
}

int main() {
    const std::string archivo_entrada = "data/input/data.txt";
    const std::string archivo_salida = "data/output/data_sorted.txt";

    std::vector<char> secuencia;

    try {
        leerSecuenciaADN(archivo_entrada, secuencia);

        std::cout << "Secuencia leída (" << secuencia.size() << " nucleótidos)\n";
        std::cout << "Primeros 10 caracteres: ";
        for (int i = 0; i < std::min(10, (int)secuencia.size()); ++i) {
            std::cout << secuencia[i];
        }
        std::cout << "\n...\n";

        CountResult conteo = countNucleotidos(secuencia);
        mostrarConteo(conteo);

        mergeSort(secuencia);

        guardarSecuenciaOrdenada(archivo_salida, secuencia);

        std::cout << "\nSecuencia ordenada guardada en: " << archivo_salida << "\n";
        std::cout << "Primeros 10 caracteres ordenados: ";
        for (int i = 0; i < std::min(10, (int)secuencia.size()); ++i) {
            std::cout << secuencia[i];
        }
        std::cout << "\n";

        CountResult conteoOrdenado = countNucleotidos(secuencia);
        mostrarConteo(conteoOrdenado);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
