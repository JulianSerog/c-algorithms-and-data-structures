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

string reverse(string s) {
	for (int start = 0, end = s.length()-1; start < end; start++, end--) {
		char temp = s[start];
		s[start] = s[end];
		s[end] = temp;
	}
	return s;
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

	//in C++ int arrays have default values of 0
	/*
	int x[4];
	x[1]++;
	x[2] += 2;
	x[3] += 3;
	for (int i = 0; i < 4; ++i) {
		cout << "index: " << x[i] << endl;
	}*/

	//reverse a string in place
	string s = "hello world";
	cout << "reversing string: " << s << endl;
	cout << reverse(s) << endl;
	cout << endl;

	return 0;
}