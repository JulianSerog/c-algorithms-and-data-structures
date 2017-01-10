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
	int size;
public:
	//constructor
	Sll() {
		//nothing happens
		cout << "created an empty sll" << endl;
		size = 0;
	}
	//insert method
	void insert(int data) {
		cout << "INSERTING " << data << " INTO NEW NODE\n" << endl;
		size++;
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

	//print method
	void print() {
		Node *c = start;
		while(c != NULL) {
			cout << c->data << " ";
			c = c->next;
		}//while
		cout << endl;
	}//print
};//SLL


int main() {
	cout << "main function beginning...\n" << endl;
	//begin function
	Sll sll = Sll();
	sll.insert(1);
	sll.insert(3);
	sll.insert(5);
	sll.insert(9);
	cout << "printed list: " << endl;
	sll.print();

	return 0;
}