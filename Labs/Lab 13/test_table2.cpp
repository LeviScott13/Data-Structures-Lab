#include "table2.h"
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace main_savitch_12B;

// Struct definition for the test_record_type, which has a key, string
// and a double.
typedef struct struct_test_record_type
{
  int key;
  string s;
  double data;
} test_record_type;

ostream& operator << (ostream& out, const test_record_type& r);
// postcondition: r has been displayed on out

int main ()
{
  table<test_record_type> t;
  test_record_type item1 {34, "abc", 26.1};
  t.insert (item1);
  test_record_type item2 {34, "hhh", 127};
  t.insert (item2);
  test_record_type item3 {44, "xyz", -14.5};
  t.insert (item3);
  test_record_type item4 {28, "bcd", 0.1};
  t.insert (item4);
  test_record_type item5 {8, "cde", -5.66};
  t.insert (item5);
  test_record_type item6 {17, "efg", 2.5};
  t.insert (item6);
  test_record_type item7 {87, "fgh", 78.3};
  t.insert (item7);
  test_record_type item8 {1, "ghi", 333.78};
  t.insert (item8);
  test_record_type item9 {6, "hij", 34.22};
  t.insert (item9);
  test_record_type item10 {84, "ijk", 116};
  t.insert (item10);
  cout << t << endl;
  t.remove (44);
  cout << t << endl;
  t.remove (17);
  cout << t << endl;
  t.remove (99);
  cout << t << endl;
  return EXIT_SUCCESS;
}

ostream& operator << (ostream& out, const test_record_type& r)
{
  out << "key: " << r.key << " s: " << r.s << " data: " << r.data << endl;
  return out;
}
