#include "bst.h"
#include <iostream>

using namespace std;


Bst::Bst(void) {
	cout << "created an empty binary search tree" << endl;
}

Bst::Bst(int data) {
	this->root = new Node(data);
}

//does not take in root for parameter b/c user should not have to enter the root every time this method is called
void Bst::insert(int data) {
	if (root) {
		insertHelper(this->root, data);
	} else {
		root = new Node(data);
	}
}

void Bst::insertHelper(Node* r, int data) {
	//TODO: implement
	if ( data > r->data) {
		if (r->right == NULL) {
			r->right = new Node(data);
		} else {
			insertHelper(r->right, data);
		}//else
	} else if(data < r->data) {
		if (r->left == NULL) {
			r->left = new Node(data);
		} else {
			insertHelper(r->left, data);
		}//else
	}//else if
}//insert

//does not take in root for parameter b/c user should not have to enter the root every time this method is called
void Bst::remove(int data) {
	this->removeHelper(this->root, data);
}

void Bst::removeHelper(Node *r, int data) {
	if (r->data == data) {
		//cout << "removing node: " << r->data << endl;
		if (r->isLeafNode()) {
			cout << "deleting node with value: " << r->data << " that has no children nodes" << endl;

			delete r;
		}
		//TODO: implement other cases
	} else if(data > r->data) {
		//traverse right
		removeHelper(r->right, data);
	} else {
		removeHelper(r->left, data);
	}
}

void Bst::preOrder() {
	if (!root) cout << "tree is empty...";
	else preHelper(this->root);
	cout << endl;
}

void Bst::preHelper(Node* r) {
	if (!r) return;
	cout << r->data << " ";
	preHelper(r->left);
	preHelper(r->right);
}

void Bst::inOrder() {
	if (!root) cout << "tree is empty...";
	else inHelper(this->root);
	cout << endl;
}

void Bst::inHelper(Node* r) {
	if (!r) return;
	inHelper(r->left);
	cout << r->data << " ";
	inHelper(r->right);
}

void Bst::postOrder() {
	if (!root) cout << "tree is empty...";
	else postHelper(this->root);
	cout << endl;
}

void Bst::postHelper(Node* r) {
	if (!r) return;
	postHelper(r->left);
	postHelper(r->right);
	cout << r->data << " ";
}



int main(int argc, char const *argv[]) {
	Bst bst = Bst(5);
	bst.insert(3);
	bst.insert(1);
	cout << "preOrder: ";
	bst.preOrder();
	cout << "inOrder: ";
	bst.inOrder();
	cout << "postOrder: ";
	bst.postOrder();


	cout << "new tree from no nodes" << endl;
	Bst a = Bst();
	a.insert(50);
	a.insert(49);
	a.insert(39);
	a.insert(5);

	a.postOrder();

	a.remove(5);
	a.postOrder();

	return 0;
}
