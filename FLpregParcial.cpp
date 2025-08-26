

#include "iostream"
using namespace std;

struct Node
{
	Node* next;
	int v;
	Node(int x) { v = x, next = nullptr; }
};

class FL
{
public:
	FL() {
		head = nullptr;
	};

	bool insert(int x);
	bool delet(int x);
	bool find(int x , Node**&pos);
	void print();

	~FL();

private:
	Node* head;



};

bool FL::find(int x, Node**& pos)
{
	pos = &head;
	for (; *pos != 0 && (*pos)->v < x; pos = &((*pos)->next));
	return *pos && (*pos)->v == x;
}


bool FL::insert(int x)
{
	Node** pos = nullptr;
	if (find(x,pos))
	{
		return false;
	}
	

	Node* n = new Node(x);
	
	n->next = *pos;
	*pos = n;

	return true;
}

bool FL::delet(int x)
{
	Node** pos;
	if (!find(x,pos))
	{
		return false;
	}
	Node* tmp = *pos;
	*pos = tmp->next;
	delete tmp;
	tmp = *pos;

}


void FL::print()
{
	for (Node *i = head; i ; i = i->next)
	{
		cout << i->v << "->";
	}
	cout << "nullptr";
}

FL::~FL()
{
	Node* tmp = head;
	while (tmp) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}

int main() {
	FL fl;
	fl.insert(5);
	fl.insert(4);
	fl.insert(3);
	fl.delet(3);
	fl.print();
}
