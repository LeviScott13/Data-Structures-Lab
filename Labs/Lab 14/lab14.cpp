#include <cstdlib>
#include <cassert>
#include <ctime>  // used in initialization of random number generator

using namespace std;

template <typename T>
bool is_sorted (T* a, size_t size);
// precondition: a is not NULL
// returns: whether array a is sorted

template <typename T>
void shell_sort (T* a, size_t size);
// precondition: a is not NULL
// postcondition: a is sorted in non-decreasing order

int* create_array (size_t size);
// returns an array with size random integers

int main ()
{
  size_t size = 1000;
  int* a = create_array (size);
  shell_sort (a, size);
  assert (is_sorted (a, size));
  delete a;
  return EXIT_SUCCESS;
}

