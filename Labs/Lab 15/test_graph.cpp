#include "graph.h"
#include <string>
#include <iostream>

using namespace main_savitch_15;
using namespace std;

template <class Item>
ostream& operator << (ostream& output, const set<Item>& s);

int main ()
{
  graph<std::string> g;
  g.add_vertex ("A");
  g.add_vertex ("B");
  g.add_vertex ("C");
  g.add_vertex ("D");
  g.add_vertex ("E");
  g.add_edge (0, 1);
  g.add_edge (0, 3);
  g.add_edge (2, 0);
  g.add_edge (3, 2);
  g.add_edge (4, 3);
  for (size_t i = 0; i < g.size(); ++i)
    cout << g[i] << ": " << g.neighbors (i) << endl;
  return 0;
}

template <class Item>
ostream& operator << (ostream& output, const set<Item>& s)
{
  typename set<Item>::iterator itr = s.begin();
  while (itr != s.end())
  {
    output << *itr << " ";
    ++itr;
  }
  return output;
}
