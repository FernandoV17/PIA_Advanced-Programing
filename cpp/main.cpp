#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "./lib/merge_sort/merge_sort.h"
#include "./lib/counting/counting.h"
using namespace std;

void leerSequenceADN(const string& ruta, vector<char>& sequence) {
    ifstream archivo(ruta, ios::binary | ios::ate);  // Abre y va al final
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + ruta);
    }

    size_t size = archivo.tellg();
    archivo.seekg(0);
    sequence.reserve(size);

    string contenido((istreambuf_iterator<char>(archivo)),
                    istreambuf_iterator<char>());

    for (char c : contenido) {
        c = toupper(c);
        if (isalpha(c)) {
            sequence.push_back(c);
        }
    }
    archivo.close();
}

void guardarSequenceOrdenada(const string& ruta, const vector<char>& sequence) {
    ofstream archivo(ruta, ios::binary);
    if (!archivo.is_open()) throw runtime_error("Error al crear: " + ruta);
    archivo.write(sequence.data(), sequence.size());
}

int main() {
    const string archivo_entrada = "data/input/data.txt";
    const string archivo_salida = "data/output/data_sorted.txt";

    vector<char> sequence;

    try {
        cout << "Iniciando procesamiento...\n";

        leerSequenceADN(archivo_entrada, sequence);
        cout << "Secuencia leida (" << sequence.size() << " nucleotidos)\n";

        cout << "Ordenando secuencia...\n";
        mergeSort(sequence);

        guardarSequenceOrdenada(archivo_salida, sequence);

        CountResult conteoOrdenado = countNucleotidos(sequence);
        cout << conteoOrdenado.getFormattedCounts();
        cout << conteoOrdenado.getCountsAsString() << "\n";

        cout << "\nProceso completado exitosamente!\n";

    } catch (const exception& e) {
        cerr << "\nERROR: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
