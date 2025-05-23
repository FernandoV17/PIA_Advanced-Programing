#include "counting.h"
#include <sstream>
#include <vector>
using namespace std;


string CountResult::getCountsAsString() const {
   ostringstream oss;
   oss << "\n=== CONTEO SIMPLE ===\n";
    const vector<char> order = {'A', 'C', 'G', 'T', 'U'};
    bool first = true;

    for (char n : order) {
        auto it = counts.find(n);
        if (it != counts.end() && (n != 'U' || it->second > 0)) {
            if (!first) oss << " ";
            oss << it->second;
            first = false;
        }
    }
    return oss.str();
}

string CountResult::getFormattedCounts() const {
   ostringstream oss;
    oss << "\n=== CONTEO DETALLADO ===\n";
    oss << "TOTAL: " << total << "\n";

    const vector<char> order = {'A', 'T', 'C', 'G', 'U'};
    for (char base : order) {
        auto it = counts.find(base);
        if (it != counts.end() && it->second > 0) {
            oss << base << " (" << names.at(base) << "): "
                << it->second << "\n";
        }
    }
    return oss.str();
}

CountResult countNucleotidos(const vector<char>& sequence) {
    CountResult result;
    result.total = sequence.size();

    for (char n : {'A', 'T', 'C', 'G', 'U'}) {
        result.counts[n] = 0;
    }

    for (char c : sequence) {
        c = toupper(c);
        if (result.counts.find(c) != result.counts.end()) {
            result.counts[c]++;
        }
    }

    return result;
}
