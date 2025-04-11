#include <iostream>
#include "intMinHeap.h"
                                                           
std::string printSortedArray(int *sortedArray, int size) {
  std::string output = "";
  output += "sorted array: [";
  if (size == 0) {
    output += "]\n";
  }
  for (int i = 0; i < size; ++i) {
    if (i == size - 1) {
      output += std::to_string(sortedArray[i]);
      output += "]";
      output += "\n";
      return output;
    }
    output += std::to_string(sortedArray[i]);
    output += ", ";
  }
  return output;
}


int main() {
  intMinHeap myHeap(2400000);  // heap with capacity of 2,400,000                                                               
  std::string line;
  while (std::getline(std::cin, line)) {  // Read until EOF                                                                     
    int i = std::stoi(line);  // Assume input is an integer                                                                     
    if (i == 0) {
      std::cout << myHeap.toString();
    } else if (i == -1) {
      std::cout << "extract min: " << std::to_string(myHeap.extractmin()) << std::endl;
    } else if (i == -2) {
      std::pair<int*, int> heapSortReturn = myHeap.heapsort();
      int* returnArray = heapSortReturn.first;
      int returnSize = heapSortReturn.second;
      std::cout << printSortedArray(returnArray, returnSize);
      delete[] returnArray;  // Clean up memory                                                                                 
    } else if (i > 0) {  // In our implementation, we only insert positive integers                                             
      if (myHeap.heapinsert(i)) {
        std::cout << "insert: " << std::to_string(i) << std::endl;
      }
    }
  }
}
