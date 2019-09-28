#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct Node
{
int data;
struct Node *left, *right;
};

// Iterative method to find height of Bianry Tree

void printLevelOrder(Node *root)
{
// Base Case
if (root == NULL) return;

// Create an empty queue for level order tarversal
queue<Node *> q;

// Enqueue Root and initialize height
q.push(root);

while (1)
{
// nodeCount (queue size) indicates number of nodes
// at current lelvel.
int nodeCount = q.size();
if (nodeCount == 0)
break;

// Dequeue all nodes of current level and Enqueue all
// nodes of next level
while (nodeCount > 0)
{
Node *node = q.front();
q.pop();

if (!node) {
cout << "null" << " ";
} else {
cout << node->data << " ";
q.push(node->left);
q.push(node->right);
}

nodeCount--;
}
cout << endl;
}
}

// Utility function to create a new tree node
Node* newNode(int data)
{
Node *temp = new Node;
temp->data = data;
temp->left = temp->right = NULL;
return temp;
}

// Driver program to test above functions
int main()
{
// Let us create binary tree shown in above diagram
Node *root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);

cout << "Level Order traversal of binary tree is \n";
printLevelOrder(root);
return 0;
}