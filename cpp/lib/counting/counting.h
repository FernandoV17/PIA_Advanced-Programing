#ifndef COUNTING_H
#define COUNTING_H

#include <vector>
#include <map>
#include <string>
using namespace std;

struct CountResult {
    int total;
    map<char, int> counts;
    map<char, std::string> names = {
        {'A', "Adenina"}, {'T', "Timina"},
        {'C', "Citosina"}, {'G', "Guanina"},
        {'U', "Uracilo"}
    };
};

CountResult countNucleotidos(const std::vector<char>& sequence);

#endif
