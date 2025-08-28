


#include "iostream"
using namespace std;

struct Node
{
	Node* next;
	Node* nextd;
	int v;
	Node(int x) {
		next = nullptr;
		nextd = nullptr;
		v = x;
	}
};
class DL
{
public:
	DL() {
		head = 0;
		end=0;
	}
	void push_front(int x);
	void push_back(int x);
	void pop_back();
	void pop_front();
	void print();
	int& operator [](int x);

	~DL();

private:
	Node* head;
	Node* end;
};

void DL::push_front(int x)
{
	if (head == NULL)
	{
		head = new Node(x);
		end = head;
	}
	else {
		head->nextd = new Node(x);
		head->nextd->next = head;
		head = head->nextd;

	}
}

void DL::push_back(int x)
{
	if (end == nullptr)
	{
		end = new Node(x);
		head = end;
	}
	else
	{
		end->next = new Node(x);
		end->next->nextd = end;
		end = end->next;	
	}
}
  
void DL::pop_back() { //eliminar el nodo del fin
	if (end == nullptr) {
		cout << "vacias" << endl;
		return; // Asegurarse de salir si la lista está vacía
	}
	Node* tmp = end;
	end = end->nextd;
	if (end) { 
		end->next = nullptr;
	} else {
		head = nullptr;
	}
	delete tmp;
}
void DL::pop_front() { //eliminar el nodo de inicio
	if (head == 0)
	{
		cout << "vacio" << endl;
	}
	Node* tmp = head;
	head = head->next;
	if (head)
	{
		head->nextd = 0;
	}
	else
	{
		end = 0;
	}
	delete tmp;
}


void DL::print()
{
	for (Node* i = head; i ; i = i->next)
	{
		cout << i->v << "->";
	}
	cout << "nullptr"<<endl;
	cout << head->v <<endl;

}

int& DL::operator[](int x)
{
	Node* p=head;
	for (int j=0;  j<x ; j++)
	{
		p = p->next;
	}
	return p->v;

}

DL::~DL()
{
}


int main() {
    DL dl;
    dl.push_front(3);
    dl.push_back(4);

    dl[1] = 2; 
    dl.print();

    return 0;
}


