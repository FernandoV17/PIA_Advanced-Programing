#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ostringstream getFileContent(string path);
void merge(vector<char>& vec, int left, int mid, int right);
void mergeSort(vector<char>& vec, int left, int right);

// Función auxiliar original (sin main)
ostringstream getFileContent(string path) {
   ifstream in(path, ios::binary);
   if(!in) {
      throw runtime_error("Failed to open file: " + path);
   }

   ostringstream buffer;
   buffer << in.rdbuf();
   return buffer;
}

void merge(vector<char>& vec, int left, int mid, int right) {
   int i, j, k;
   int n1 = mid - left + 1;
   int n2 = right - mid;

   vector<char> leftVec(n1), rightVec(n2);

   for (i = 0; i < n1; i++)
      leftVec[i] = vec[left + i];
   for (j = 0; j < n2; j++)
      rightVec[j] = vec[mid + 1 + j];

   i = 0;
   j = 0;
   k = left;
   while (i < n1 && j < n2) {
      if (leftVec[i] <= rightVec[j]) {
         vec[k] = leftVec[i];
         i++;
      } else {
         vec[k] = rightVec[j];
         j++;
      }
      k++;
   }

   while (i < n1) {
      vec[k] = leftVec[i];
      i++;
      k++;
   }

   while (j < n2) {
      vec[k] = rightVec[j];
      j++;
      k++;
   }
}

void mergeSort(vector<char>& vec, int left, int right) {
   if (left < right) {
      int mid = left + (right - left) / 2;
      mergeSort(vec, left, mid);
      mergeSort(vec, mid + 1, right);
      merge(vec, left, mid, right);
   }
}

void mergeSort(vector<char>& vec) {
    if (!vec.empty()) {
        mergeSort(vec, 0, vec.size() - 1);
    }
}
