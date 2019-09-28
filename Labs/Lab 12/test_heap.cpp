#include "heap.h"
#include <iostream>

using namespace std;

int main ()
{
  heap<int> h;
  h.insert (34);
  h.insert (23);
  h.insert (55);
  h.insert (11);
  h.insert (2);
  h.insert (38);
  h.insert (42);
  h.insert (60);
  h.insert (52);

  while (!h.is_empty())
  {
    cout << h.max() << endl;
    h.remove();
  }
}
