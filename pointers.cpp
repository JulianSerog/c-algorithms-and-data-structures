#include <iostream>
using namespace std;
/*
class Node {
private:
	Node *next;
	int data;
public:
	Node(int data) {
		this.data = data;
	}
	void insert(int data) {
		Node *c;
		while (next != NULL) {

		}
	}
};*/

//pass by reference with normal ints
void change(int &c) {
	c = 50;
}

int main() {

	//pass by reference with normal data type
	int i = 42;
	change(i);
	cout << "i: " << i << endl;


	//pass by reference with pointers
	int *ip;
	ip = new int(5);
	//use * to get value of ip
	change(*ip);
	cout << "ip: " << *ip << endl;

	

	int *arr = (int *) malloc(1024 * 100);

	//free memory
	free(ip);
	free(arr);
	return 0;
}