#include <iostream>
using namespace std;

class Node {
	friend class Dll;
	friend class Bst;
private:
	Node* right = NULL;
	Node* left = NULL;
	int data;
	bool isLeafNode() {
		if(!right && !left) return true;
		else return false;
	}

public:
	Node(int data) {
		this->data = data;
		this->right = NULL;
		this->left = NULL;
	}
};