#include "intMinHeap.h"

// Constructor for the intMinHeap class                                                                                                                                                                                                                                                                                                                                                                                                                           
intMinHeap::intMinHeap(int cap) {
  capacity = cap;
  size = 0;
  A = new int[capacity];
}

// Modified original version, which created a copy of the heap before sorting                                                                                                                                                                                                                                                                                                                                                                                     
// Now, no new heap is created, instead just a new array                                                                                                                                                                                                                                                                                                                                                                                                          
std::pair<int *, int> intMinHeap::heapsort() {
  int* sortedArray = new int[size];
  for (int i = 0; i < size; ++i) {
    sortedArray[i] = A[i];  // Copy each item over, in order                                                                                                                                                                                                                                                                                                                                                                                                      
  }
  int* origHeap = A;
  int origSize = size;
  A = sortedArray;
  // Now use the sorting algorithm                                                                                                                                                                                                                                                                                                                                                                                                                                
  for (int i = size - 1; i > 0; i--) {
    swap(0, i);
    size--;
    heapify(0);
  }
  size = origSize;
  A = origHeap;
  return std::make_pair(sortedArray, size);  // Sorted array size = size of heap                                                                                                                                                                                                                                                                                                                                                                                  
}


std::string intMinHeap::toString() {
  std::string output = "heap size ";
  if (size == 0) {
    output += "0:\n";
    return output;
  }
  output = output + std::to_string(size) + ": ";
  for (int i = 0; i < size; i++) {
    output += std::to_string(A[i]);
    if (i == size - 1) {
      output += "\n";
      return output;
    }
    output += ", ";
  }
  return output;  // This will not be reached, but allows the program to compile                                                                                                                                                                                                                                                                                                                                                                                  
}

bool intMinHeap::heapinsert(int k) {
  // Bounds check; can't insert more integers than the heap's capacity                                                                                                                                                                                                                                                                                                                                                                                            
  if (size == capacity) {
    return false;  // Return false if we can't insert a new integer                                                                                                                                                                                                                                                                                                                                                                                               
  }
  size++;
  A[size - 1] = k + 1;
  decreasekey(size - 1, k);
  return true;  // True if insertion is unsuccessful                                                                                                                                                                                                                                                                                                                                                                                                              
}

int intMinHeap::minimum() {
  if (isEmpty()) {
    return 0;  // Return 0 for an empty heap                                                                                                                                                                                                                                                                                                                                                                                                                      
  }
  return A[0];  // If heap is not empty, return the root                                                                                                                                                                                                                                                                                                                                                                                                          
}

int intMinHeap::extractmin() {
  if (isEmpty()) {
    return 0;
  }
  int min = A[0];
  A[0] = A[size - 1];
  size--;
  heapify(0);
  return min;
}

void intMinHeap::decreasekey(int i, int k) {
  // Bounds check as suggested in class                                                                                                                                                                                                                                                                                                                                                                                                                           
  if (i < 0 || i >= size || A[i] <= k) return;
  A[i] = k;
  while (i > 0 && A[parent(i)] > A[i]) {
    swap(i, parent(i));
    i = parent(i);
  }
}


bool intMinHeap::isEmpty() {
  return size == 0;
}

bool intMinHeap::isFull() {
  return size == capacity;
}

int intMinHeap::minOf3(int i, int j, int k) {
  int minIndex = i;
  if (j < size && j >= 0 && A[j] < A[minIndex]) {
    minIndex = j;
  }
  if (k < size && k >= 0 && A[k] < A[minIndex]) {
    minIndex = k;
  }
  return minIndex;
}

void intMinHeap::buildheap() {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(i);
  }
}

void intMinHeap::heapify(int i) {
  if (left(i) >= size && right(i) >= size) return; // Left and right are both out of bounds                                                                                                                                                                                                                                                                                                                                                                       
  int n = minOf3(i, left(i), right(i));
  if (n != i && n < size) { // Make sure 'n' is valid                                                                                                                                                                                                                                                                                                                                                                                                             
    swap(i, n);
    heapify(n);
  }
}

// Swap function comes in handy multiple times in the program                                                                                                                                                                                                                                                                                                                                                                                                     
void intMinHeap::swap(int i, int j) {
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

intMinHeap::~intMinHeap() {
  delete[] A;  // Destructor deletes the array                                                                                                                                                                                                                                                                                                                                                                                                                    
}
