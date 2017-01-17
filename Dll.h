#include "Node.h"

class Dll {
private:
	Node* start;
	Node* end;
public:
	Dll(void);
	Dll(int data);
	void insert(int data);
	void remove(int index);
	void print();
	int size();
	bool isEmpty();
};