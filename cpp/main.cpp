#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "./lib/merge_sort/merge_sort.h"
#include "./lib/counting/counting.h"
using namespace std;

void leersequenceADN(const string& ruta, vector<char>& sequence) {
    ifstream archivo(ruta, ios::binary);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + ruta);
    }

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

void guardarsequenceOrdenada(const string& ruta, const vector<char>& sequence) {
    ofstream archivo(ruta, ios::binary);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo crear el archivo: " + ruta);
    }

    const size_t bloque_size = 4096;
    size_t pos = 0;
    while (pos < sequence.size()) {
        size_t bloque_actual = min(bloque_size, sequence.size() - pos);
        archivo.write(&sequence[pos], bloque_actual);
        pos += bloque_actual;
    }
    archivo.close();
}

void mostrarConteo(const CountResult& resultado) {
    cout << "\n=== CONTEO DE NUCLEÓTIDOS ===\n";
    cout << "TOTAL: " << resultado.total << "\n";

    const vector<char> orden = {'A', 'T', 'C', 'G', 'U'};
    for (char base : orden) {
        if (resultado.counts.find(base) != resultado.counts.end()) {
            cout << base << " (" << resultado.names.at(base) << "): "
                      << resultado.counts.at(base) << "\n";
        }
    }
}

int main() {
    const string archivo_entrada = "data/input/data.txt";
    const string archivo_salida = "data/output/data_sorted.txt";

    vector<char> sequence;

    try {
        leersequenceADN(archivo_entrada, sequence);

        cout << "sequence leída (" << sequence.size() << " nucleótidos)\n";
        cout << "Primeros 10 caracteres: ";
        for (int i = 0; i < min(10, (int)sequence.size()); ++i) {
            cout << sequence[i];
        }
        cout << "\n...\n";

        CountResult conteo = countNucleotidos(sequence);
        mostrarConteo(conteo);

        mergeSort(sequence);

        guardarsequenceOrdenada(archivo_salida, sequence);

        cout << "\nsequence ordenada guardada en: " << archivo_salida << "\n";
        cout << "Primeros 10 caracteres ordenados: ";
        for (int i = 0; i < min(10, (int)sequence.size()); ++i) {
            cout << sequence[i];
        }
        cout << "\n";

        CountResult conteoOrdenado = countNucleotidos(sequence);
        mostrarConteo(conteoOrdenado);

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
