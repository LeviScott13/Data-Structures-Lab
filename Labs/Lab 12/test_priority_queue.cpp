#include "priority_queue.h"
#include <iostream>

using namespace std;
int main ()
{
  priority_queue<int> q;
  q.push (34);
  q.push (23);
  q.push (55);
  q.push (11);
  q.push (2);
  q.push (38);
  q.push (42);
  q.push (60);
  q.push (52);

  while (!q.empty())
  {
    cout << q.top() << endl;
    q.pop();
  }
 return 0;
}
