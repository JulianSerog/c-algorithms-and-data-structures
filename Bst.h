#include "Node.h"

class Bst {
private:
	int size;
	void insertHelper(Node* r, int data);
	void preHelper(Node* r);
	void inHelper(Node* r);
	void postHelper(Node* r);
	void removeHelper(Node *r, int data);
	Node* root = NULL;
public:
	Bst(void);
	Bst(int data);
	void insert(int data);
	void remove(int data);
	void preOrder();
	void inOrder();
	void postOrder();
};