#ifndef COUNTING_H
#define COUNTING_H

#include <vector>
#include <map>
#include <string>

struct CountResult {
    int total;
    std::map<char, int> counts;
    std::map<char, std::string> names = {
        {'A', "Adenina"}, {'T', "Timina"},
        {'C', "Citosina"}, {'G', "Guanina"},
        {'U', "Uracilo"}
    };
};

CountResult countNucleotidos(const std::vector<char>& secuencia);

#endif
