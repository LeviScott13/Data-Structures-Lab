#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

int* create_int_array (int n);
// precondition: n > 0
// return: pointer to an array of integers of size n

void display_int_array (const int* a, int n);
// precondition: a is not null and n > 0)
// postcondition: contents of a have been displayed on standard output

int main (int argc, char** argv)
{
  const int size = 10;
  int* a = create_int_array (size);
  display_int_array (a, size);
  delete [] a;
  return EXIT_SUCCESS;
}

int* create_int_array (int n)
{
  assert (n > 0);
  int * a = new int [n];
  for (int i = 0; i < n; i++)
    a[i] = i;
  return a;
}


void display_int_array (const int* a, int n)
{
  assert (a != NULL);
  assert (n > 0);
  for (int i = 0; i < n; i++)
    cout << a[i] << endl;
}