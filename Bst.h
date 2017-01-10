#include "Node.h"

class Bst {
private:
	int size;
	void insertHelper(Node* r, int data);
	void preHelper(Node* r);
	void inHelper(Node* r);
	void postHelper(Node* r);
	Node* root = NULL;
public:
	Bst(void);
	Bst(int data);
	void insert(int data);
	void remove(Node* r, int data);
	void preOrder();
	void inOrder();
	void postOrder();
};