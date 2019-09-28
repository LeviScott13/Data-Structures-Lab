//*************************************
//
//  Name: Levi Sutton
//  Lab: 11
//
//*************************************

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node
{
string leafs;
struct Node *left, *right;
};

void printBinaryTree(Node *root)
{

    if (root == NULL) return;
    queue<Node *> q;

    q.push(root);

    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
        break;
        
        while (nodeCount > 0)
        {
            Node *node = q.front();
            q.pop();

            if (!node) {
                cout << "null" << " ";
            }
            else {
                cout << node->leafs << " ";
                q.push(node->left);
                q.push(node->right);
            }
            nodeCount--;
        }
        cout << endl;
    }
}
Node* newNode(string leafs)
{
    Node *temp = new Node;
    temp->leafs = leafs;
    temp->left = temp->right = NULL;
    return temp;
}
int main()
{
    Node *root = newNode("M");
    root->left = newNode("H");
    root->right = newNode("T");
    root->left->left = newNode("E");
    root->right->left = newNode("P");
    root->right->right = newNode("W");
    root->left->left->left = newNode("A");
    root->right->left->right = newNode("Q");

    cout << "\n\n Binary tree is: \n\n";
    printBinaryTree(root);
    return 0;
}