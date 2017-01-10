#include "Dll.h"
#include <iostream>

using namespace std;

Dll::Dll() {
	cout << "created new dll" << endl;
}

Dll::Dll(int data) {
	start = new Node(data);
	start->right = start;
	start->left = start;
	end = start;
}

void Dll::insert(int data) {
	if (start == NULL){
		//create new node if first in list
		start = new Node(data);
		start->right = start;
		start->left = start;
		end = start;
	} else {
		Node* c = start;
		while(c->right != start) {
			c = c->right;
		}
		c->right = new Node(data);
		end = c->right;
		c->right->left = c;
		end->right = start;
	}//else
}//insert

void Dll::remove(int index) {

}

void Dll::print() {
	if (start == NULL) {
		cout << "list is empty..." << endl;
	} else {
		Node* c = start;
		if (start->right == start) {
			cout << c->data;
		} else {
			while(c->right != start) {
				cout << c->data << " ";
				c = c->right;
			}//while
		}//else
		cout << endl;
	}//else
}//print


int main() {
	Dll dll = Dll(1);
	dll.insert(3);
	dll.insert(5);
	dll.insert(7);
	dll.insert(9);
	dll.print();
	return 0;
}