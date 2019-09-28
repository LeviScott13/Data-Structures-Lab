#include "expression_tree.h"
#include <cassert>
#include <sstream>
#include <cctype>

expression_tree::expression_tree (const std::string& op,
				  const expression_tree& left,
				  const expression_tree& right)
{
  assert ((op == "+") || (op == "*"));
  node = new binary_tree_node<std::string> (op, left.node,
					    right.node);
}

bool all_digits (const string& s)
// return whether all characters is s are digits
{
  size_t i = 0;
  while (i < s.length() && isdigit (s[i]))
    i++;
  return i == s.length();
}

expression_tree::expression_tree (const std::string& value)
{
  	
  node = new binary_tree_node<std::string>(value);
}



int expression_tree::evaluate() const
{
  // to be implemented
}
