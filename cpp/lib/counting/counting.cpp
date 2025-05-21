#include "counting.h"
#include <cctype>
using namespace std;


CountResult countNucleotidos(const vector<char>& sequence) {
    CountResult result;
    result.total = sequence.size();

    const string nucleotidos = "ATCGU";
    for (char n : nucleotidos) {
        result.counts[n] = 0;
    }

    for (char c : sequence) {
        if (result.counts.find(c) != result.counts.end()) {
            result.counts[c]++;
        }
    }

    return result;
}
