//***********************************
//
//Name: Levi Sutton
//Lab 10
//
//***********************************
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

class TreeNode {
public:
	char val;

	TreeNode *left, *right;

	TreeNode(char val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

class NodeStack {
public:
	TreeNode *nodeFromTree;
	NodeStack *nextNode;

	NodeStack(TreeNode *nodeFromTree) {
		this->nodeFromTree = nodeFromTree;
		nextNode = NULL;
	}
};

class ExpressionTree {
private:
	NodeStack * topNode;
public:
	ExpressionTree() {
		topNode = NULL;
	}

	void clear() {
		topNode = NULL;
	}
	void push(TreeNode *ptrNode) {
		if (topNode == NULL) {
			topNode = new NodeStack(ptrNode);
		}
		else {
			NodeStack *newPtrNode = new NodeStack(ptrNode);
			newPtrNode-> nextNode = topNode;
			topNode = newPtrNode;
		}
	}

	TreeNode *pop() {
		if (topNode = NULL) {
			cout << "Error" << endl;
		}
		else {
			TreeNode *ptrNode = topNode->nodeFromTree;
			topNode = topNode->nextNode;
			return ptrNode;
		}
	}

	TreeNode *peek() {
		return topNode->nodeFromTree;
	}

	void insert(char val) {
		if (isDigit(val)) {
			TreeNode *newPtrNode = new TreeNode(val);
			push(newPtrNode);
		}
		else if(isOperator(val))
		{
			TreeNode *newPtrNode = new TreeNode(val);
			newPtrNode->left = pop();
			newPtrNode->right = pop();
			push(newPtrNode);
		}
		else {
			cout << "The Expression is not an expression" << endl;
			return;
		}
	}

	bool isDigit(char val) {
		return val >= '0' && val <= '9';
	}

	bool isOperator(char val) {
		return val == '+' || val == '-' || val == '*' || val == '/';
	}
	
	int charToDigit(char val) {
		return val - '0';
	}

	void composeTree(string exp) {
		for (int i = exp.length() - 1; i >= 0; i--) {
			insert(exp[i]);
		}
	}

	double evaluateTree() {
		return evaluate(peek());
	}

	double evaluate(TreeNode *ptrNode) {

		if (ptrNode->left == NULL && ptrNode->right == NULL)
			return charToDigit(ptrNode->val);
		else {
			double results = 0.0;
			double left = evaluate(ptrNode->left);
			double right = evaluate(ptrNode->right);
			char operatorVal = ptrNode->val;

			switch (operatorVal)
			{
				case '+':
					results = left + right;
					break;

				case '-':
					results = left - right;
					break;
				
				case '*':
					results = left * right;
					break;
				
				case '/':
					results = left / right;
					break;

				default:
					results = left + right;
					break;
			}
			return results;
		}
	}

	void postfix() {
		postOrder(peek());
	}

	void postOrder(TreeNode *ptrNode) {
		if (ptrNode != NULL) {
			postOrder(ptrNode->left);
			postOrder(ptrNode->right);
			cout << ptrNode->val;
		}
	}

	void infix() {
		inOrder(peek());
	}

	void inOrder(TreeNode *ptrNode) {
		if (ptrNode != NULL) {
			inOrder(ptrNode->left);
			cout << ptrNode->val;
			inOrder(ptrNode->right);
		}
	}

	void prefix() {
		preOrder(peek());
	}

	void preOrder(TreeNode *ptrNode) {
		if (ptrNode != NULL) {
			cout << ptrNode->val;
			preOrder(ptrNode->left);
			preOrder(ptrNode->right);
		}
	}
};

int main() {
	
	string expression;
	cout << "Expression Tree" << endl;

	ExpressionTree et;
	cout << "\n\nEnter an expression in Prefix form: ";
	cin >> expression;
	et.composeTree(expression);
	cout << "\n\nPrefix Form: ";
	et.prefix();
	cout << "\n\nInfix Form: ";
	et.infix();
	cout << "\n\nPostfix Form: ";
	et.postfix();
	cout << "\n\nCalculated Expression: " << et.evaluateTree();
	return 0;
}


