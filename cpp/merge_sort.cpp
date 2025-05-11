#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ostringstream getFileContent(string path);
void merge(vector<int>& vec, int left, int mid, int right);
void mergeSort(vector<int>& vec, int left, int right);

int main(int argc, char *argv[]) {
   ostringstream data;
   // default path
   char defaultPath[15] = "./textFile.txt";
   if (argc == 1) {
      data = getFileContent(defaultPath);
   }
   else if (argc == 2) {
      data = getFileContent(argv[1]);
   } else {
      throw runtime_error("It can only have one argument (Path to file)");
   }

   string content = data.str();
   vector<char> dataVec(content.begin(), content.end());
   vector<int> dataInt;
   for(int c: dataVec) dataInt.push_back((int)c);

   mergeSort(dataInt, 0, (dataInt.size()-1));

   for(char c: dataInt) cout << c;
}

ostringstream getFileContent(string path) {
   ifstream in(path, ios::binary);
   if(!in) {
      throw runtime_error("Failed to open file: " + path);
   }

   ostringstream buffer;
   buffer << in.rdbuf();
   return buffer;
}

void merge(vector<int>& vec, int left, int mid, int right) {
   int i, j, k;
   int n1 = mid - left + 1;
   int n2 = right - mid;

   // Create temporary vectors
   vector<int> leftVec(n1), rightVec(n2);

   // Copy data to temporary vectors
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

   // Copy the remaining elements of leftVec[], if any
   while (i < n1) {
      vec[k] = leftVec[i];
      i++;
      k++;
   }

   // Copy the remaining elements of rightVec[], if any
   while (j < n2) {
      vec[k] = rightVec[j];
      j++;
      k++;
   }
}

// The subarray to be sorted is in the index range [left..right]
void mergeSort(vector<int>& vec, int left, int right) {
   if (left < right) {

      // Calculate the midpoint
      int mid = left + (right - left) / 2;

      // Sort first and second halves
      mergeSort(vec, left, mid);
      mergeSort(vec, mid + 1, right);

      // Merge the sorted halves
      merge(vec, left, mid, right);
   }
}
