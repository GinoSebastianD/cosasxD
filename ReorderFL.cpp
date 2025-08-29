#include "iostream"
using namespace std;


struct Node
{
	Node* next;
	int v;
	Node(int x) {
		v = x;
		next = 0;
	}
};



class FL
{
public:
	FL() {
		head = 0;
		nelem = 0;
	};
	
	//bool push_back(int x);
	int insert(int x);
	int eliminar(int x);
	void print();
	int& operator[](int x);
	bool find(int x, Node**& pos);
	void medio();
	bool push_back(int x);

	void reorder();
	~FL();

private:
	Node* head;
	int nelem;
};

bool FL::find(int x, Node**& pos)
{
	pos = &head;
	for (; *pos != nullptr && (*pos)->v < x; pos = &(*pos)->next);
	return *pos && (*pos)->v == x;

}

void FL::medio()
{
	Node* l = head;
	Node* r = head;
	
	for (int i = 0; i < (nelem / 2) -1; i++)
	{
		l = l->next;
		r = l->next;
	}
	if (nelem % 2 == 0)
	{
		cout << l->v << " " << r->v << endl;
	}
	
	else
	{
		cout << r->v << endl;
	}
}

bool FL::push_back(int x)
{
	Node** p;
	for (p = &head; p != 0; p = &(*p)->next);
	Node* q = new Node(x);
	q->next = head;
	head = q;
	return true;

}

int FL::insert(int x)
{
	Node** pos;
	if (find(x, pos))
	{
		return false;
	}
	Node* p = new Node(x);
	p->next = *pos;
	*pos = p;
	nelem++;
	return nelem;
}

int FL::eliminar(int x)
{
	Node** pos;
	if (!find(x, pos))
	{
		return false;
	}
	Node* tmp = *pos;
	*pos = tmp->next;
	delete tmp;
	nelem--;
	return nelem;
}



void FL::print()
{
	for (Node *p = head ; p; p = p->next)
	{
		cout << p->v << "->";
	}
	cout << "NULL" << endl;
	cout << "numero de elementos: " << nelem << endl;
}

int& FL::operator[](int x)
{
	Node* p=head;
	for (int i = 0; i < x; i++)
	{
		p = p->next;
	}
	return p->v;
}



void FL::reorder()
{

	Node* l = head;
	Node* r = head;

	while (r && r->next ) {
		l = l->next;
		r = r->next->next;
	}

	Node* vac = nullptr;
	Node* tmp = l;

	while (tmp)
	{
		tmp = l->next;
		l->next = vac;
		vac = l;
		l = tmp;
	}
	l = vac;
	vac = l->next;
	

	Node* ra = head;
	Node* n = ra->next;
	while (n && vac )
	{
		
		ra->next = l;
		l->next = n;
		ra = n;
		l = vac;
		vac = l->next;
		n = ra->next;
	}

}

FL::~FL()
{
	Node* tmp = head;
	while (tmp) {
		head = tmp->next;
		delete tmp;
		tmp = head;
	}
}


int main() {
	FL fl;
	fl.insert(5);
	fl.insert(4);
	fl.insert(3);
	fl.insert(8);
	fl.insert(9);
	fl.insert(10);
	
	fl.reorder();
	fl.print();
}


