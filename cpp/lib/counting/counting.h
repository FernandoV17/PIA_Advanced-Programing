#ifndef COUNTING_H
#define COUNTING_H

#include <vector>
#include <map>
#include <string>
using namespace std;


struct CountResult {
    int total;
   map<char, int> counts;
    const map<char,string> names = {
        {'A', "Adenina"}, {'T', "Timina"},
        {'C', "Citosina"}, {'G', "Guanina"},
        {'U', "Uracilo"}
    };

   string getCountsAsString() const;

   string getFormattedCounts() const;
};

CountResult countNucleotidos(const vector<char>& sequence);

#endif
