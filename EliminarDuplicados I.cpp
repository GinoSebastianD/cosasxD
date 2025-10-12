#include "iostream"
using namespace std;

struct Node
{
	Node* next;
	int v;
	Node(int x) {
		next = nullptr;
		v = x;
	}
};

class FL
{
public:
	Node* head;
	FL() {
		head = nullptr;
	};
	~FL();

	bool push_front(int x);
	
	bool pop_front(int &v);
	Node* eliminarduplicados(Node* head);

	void print();

private:

};

FL::~FL()
{
}

bool FL::push_front(int x)
{
	if (!head)
	{
		head = new Node(x);
		return true;
	}
	Node* tmp = new Node(x);
	tmp->next = head;
	head = tmp;
	return false;
}

bool FL::pop_front(int& v)
{
	return false;
}

Node* FL::eliminarduplicados(Node* head)
{
	Node* ini = head;
	while (ini && ini->next)
	{
		if ( ini->v == ini->next->v  )
		{
			Node* sig = ini->next;
			ini->next = sig->next;
			delete sig;
		}
		else
		{
			ini = ini->next;
		}
	}
	return head;
}

void FL::print()
{
	for (Node* i = head; i; i =i->next)
	{
		cout << i->v << " ";
	}
}


int main() {
	FL fl;
	fl.push_front(5);
	fl.push_front(5);
	fl.push_front(5);
	fl.push_front(5);
	fl.push_front(4);
	fl.push_front(3);
	fl.push_front(3);
	fl.push_front(3);
	fl.push_front(3);

	fl.eliminarduplicados(fl.head);
	fl.print();

}


