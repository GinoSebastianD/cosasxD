

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
	void buscarelemento(int x);
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

void FL::buscarelemento(int x)
{
	Node** b = &head;
	for (; *b != 0; b = &(*b)->next) {
		if ((*b)->v ==x)
		{
			cout << "si esta" << endl;
			return;
		}
	}
	cout << "no esta" << endl;
	return;

}




bool FL::insert(int x)
{
	Node** pos = nullptr;
	if (find(x,pos))
	{
		return false;
	}
	//find(pos, x); --> quitando el if anterior logramos q se cree la lista enlazada con repeticiones y ordenado.
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
	fl.buscarelemento(4);
	fl.print();
}


