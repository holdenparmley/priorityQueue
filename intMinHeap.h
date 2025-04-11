#include <string>

class intMinHeap{
public:
  intMinHeap(int);  // empty heap wth this capacity                                                 
  ~intMinHeap();  // clean up allocated memory                                                      
  std::pair<int *, int> heapsort();  // return sorted array and size from heap                      
  std::string toString();
  bool heapinsert(int); // add element to heap; return success                                      
  // min functions should return 0 in empty heaps                                                   
  int minimum();  // return value of A[root]                                                        
  int extractmin(); // return and remove A[root]                                                    
  void decreasekey(int i, int k);  // A[i] decreased to k                                           
  bool isEmpty();
  bool isFull();
private:
  int minOf3(int, int, int); // with bounds check!                                                  
  inline int left(int i) { return 2 * i + 1; }
  inline int right(int i) { return 2 * i + 2; }
  inline int parent(int i) { return (i - 1) / 2; }
  void buildheap();  // convert array to a heap                                                     
  void heapify(int i);  // heapify at position i                                                    
  void swap(int i, int j);
  int *A;  // array of integers - data                                                              
  int capacity; // size of array A                                                                  
  int size; // data size in array                                                                   
 };

