#include "iostream"
using namespace std;

struct Node
{
	int v;
	Node* next;
	Node(int x) {
		v = x;
		next = nullptr;
	}
};

class Cola
{
public:
	Cola()
	{
		head = nullptr;
		fin = nullptr;
	}
	bool push(int x);
	bool vacia();
	void pop();
	
	void imprimir();



private:
	Node* head;
	Node* fin;
};


bool Cola::push(int x)
{
	if (vacia())
	{
		head = new Node(x);
		fin = head;
		return true;
	}
	else
	{
		Node* p = new Node(x);
		fin->next = p;
		fin = p;
		return true;
	}
}

bool Cola::vacia()
{
	return head == nullptr && fin == nullptr;
}

void Cola::pop()
{
	if (vacia())
	{
		return;
	}
	Node* tmp = head;
	head = head->next;
	delete tmp;
	if (head==nullptr)
	{
		fin = nullptr;
	}
}

void Cola::imprimir()
{
	Node* p = head;
	for (  ;p ; p=p->next)
	{
		cout << p->v << "->";
	}
	cout << "NULL";
}



int main()
{
	
	Cola pil;
	pil.push(4);
	pil.push(3);
	pil.push(9);
	pil.pop();

	pil.imprimir();
	return 0;
}
