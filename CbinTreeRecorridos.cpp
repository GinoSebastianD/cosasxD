#include "iostream"
using namespace std;

struct Node
{
	Node* der;
	Node* izq;
	int v;
	Node(int x) {
		der = nullptr;
		izq = nullptr;
		v = x;
	}
};

class RecorridoArbol
{
public:
	Node* root;

	RecorridoArbol();
	bool find(int x, Node**& pos);
	bool insert(int x);
	bool del(int x);
	void in_orden(Node* r);
	void post_orden(Node* r);
	~RecorridoArbol();

private:

};

RecorridoArbol::RecorridoArbol()
{
	root = nullptr;
}

bool RecorridoArbol::find(int x, Node**& pos)
{
	pos = &root;
	while (*pos && (*pos)->v != x)
	{
		if ((*pos)->v < x)
		{
			pos = &(*pos)->der;	
		}
		else
		{
			pos = &(*pos)->izq;
		}
	}
	return *pos != nullptr;

}

bool RecorridoArbol::insert(int x)
{
	Node** pos;
	if (find(x,pos))
	{
		return false;
	}
	*pos = new Node(x);
	return true;
}

bool RecorridoArbol::del(int x)
{
	return false;
}

void RecorridoArbol::in_orden(Node* r)
{
	if (!r)
	{
		return;
	}
	in_orden(r->izq);
	cout << r->v << " ";
	in_orden(r->der);
}

void RecorridoArbol::post_orden(Node* r)
{
	if (!r)
	{
		return;
	}
	in_orden(r->der);
	in_orden(r->izq);
	cout << r->v << " ";
}

RecorridoArbol::~RecorridoArbol()
{
}

int main() {
	RecorridoArbol arb;
	arb.insert(8);
	arb.insert(5);
	arb.insert(6);
	arb.insert(7);
	arb.insert(9);
	arb.insert(10);
	arb.insert(11);
	arb.insert(4);
	arb.insert(3);

	arb.in_orden(arb.root);

	return 0;
}
