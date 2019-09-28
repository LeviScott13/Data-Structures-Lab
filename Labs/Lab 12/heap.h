#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <vector>

// This class implements an unbounded max heap.

// class invariant: heap property is satisfied for a max heap

template <typename T>
class heap
{
public:
  heap();
  // postcondition: empty heap has been created
  size_t size() const;
  // returned: number of elements in the heap
  bool is_empty() const;
  // returned: whether the heap is empty
  void insert (const T& item);
  // postcondition: item has been added
  void remove();
  // precondition: heap is not empty
  // postcondition: largest item has been removed from the heap
  T max() const;
  // precondition: heap is not empty
  // returned: copy of largest element in the heap
  T& max();
  // precondition: heap is not empty
  // returned: access to largest element in the heap
private:    
  std::vector<T> v;
  size_t max_child (size_t index) const;
  // precondition: element at index has children
  // returned: index of the larger child - if there is only 1 child
  //           index of that child has been returned
  size_t parent (size_t index);
  // precondition: index > 0
  // returned: location of parent of element at index
};

#include "heap.template"

#endif // _HEAP_H_
