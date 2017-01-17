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
	if (index > this->size() - 1) {
		cout << "out of bounds exception with removing a node" << endl;
		return;
	} else {
		int i = 0;
		Node* c = start;
		while(i != index) {
			i++;
			c = c->right;
		}
		c->left->right = c->right;
		delete(c);
	}//else
}//remove

int Dll::size() {
	int size = 0;
	Node* c = start;
	if(!start) return 0;
	else {
		size = 1;
		while(c->right != start) {
			c = c->right;
			size++;
		}//while
	}//else
	return size;
}//size()

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
			cout << c->data;
		}//else
		cout << endl;
	}//else
}//print

bool Dll::isEmpty() {
	if(start) return false;
	else return true;
}


int main() {
	Dll dll = Dll(1);
	dll.insert(3);
	dll.insert(5);
	dll.insert(7);
	dll.insert(9);
	dll.remove(2);
	dll.print();
	cout << "size of list: " << dll.size() << endl;
	cout << "list empty? " << dll.isEmpty() << endl;
	return 0;
}