#include "counting.h"
#include <cctype>

CountResult countNucleotidos(const std::vector<char>& secuencia) {
    CountResult result;
    result.total = secuencia.size();

    const std::string nucleotidos = "ATCGU";
    for (char n : nucleotidos) {
        result.counts[n] = 0;
    }

    for (char c : secuencia) {
        char upper = toupper(c);
        if (result.counts.find(upper) != result.counts.end()) {
            result.counts[upper]++;
        }
    }

    return result;
}
