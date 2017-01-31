#include <iostream>
#include <unistd.h>
using namespace std;

class Node {
	friend class Sll;
private:
	Node *next;
	int data;
	//constructor
	Node(int data) {
		this->data = data;
		next = NULL;
	}//constructor
};//Node

class Sll {
private:
	Node *start = NULL;
public:
	//constructor
	Sll() {
		//nothing happens
		cout << "created an empty sll" << endl;
	}
	//insert method
	void insert(int data) {
		if (start == NULL) { 
			start = new Node(data); 
		} else {
			Node *c = start;
			//loop through elements
			while(c->next != NULL) {
				c = c->next; 
			}//while
			c->next = new Node(data);
		}//else
	}//insert

	/**
	*
	* removes element at index
	*/
	void remove(int index) {
		Node* n = this->start;
		for (int i = 0; i < index; ++i){
			if (i+1 == index && n != NULL) {
				Node* temp = n->next->next;
				n->next = n->next->next;
				free(temp);
			}
			n = n->next;
		}//for
	}//remove

	/**
	*
	* prints list
	*/
	void print() {
		Node *c = start;
		if (!c){
			cout << "list is empty" << endl;
		} else {
			while(c != NULL) {
				cout << c->data;
				if (c->next == NULL) cout << endl;
				else cout << " -> ";
				c = c->next;
			}//while
		}//else
	}//print

	/**
	*
	* returns size of list
	*/
	int size() {
		int counter = 0;
		if (!start) {
			return counter;
		} else {
			Node* c = start;
			while(c) {
				counter++;
				c = c->next;
			}//while
			return counter;
		}//else
	}//size
};//SLL


int main() {
	//begin function
	Sll sll = Sll();
	sll.insert(1);
	sll.insert(3);
	sll.insert(5);
	sll.insert(9);
	sll.remove(2);
	cout << "printed sll: ";
	sll.print();
	//create an empty list
	cout << "empty list: ";
	Sll empty = Sll();
	empty.print();

	cout << "empty size: " << empty.size() << ", sll1 size: " << sll.size() << endl;
	//end line for make run
	cout << endl;
	

	return 0;
}