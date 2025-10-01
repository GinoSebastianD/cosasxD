#include "iostream"
#include "stack"
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
	bool br = 0;
	RecorridoArbol();
	bool find(int x, Node**& pos);
	bool insert(int x);
	bool del(int x);
	void in_orden(Node* r);
	void reverse(Node* r);
	void post_orden(Node* r);
	void pre_orden(Node* r);
	void liberar_memoria(Node* r);
	void in_orden_sin_recursividad(Node* r);

	Node** deriz(Node** q);
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
	Node** pos;
	if (!find(x,pos))
	{
		return false;
	}
	if ( (*pos)->der && (*pos)->izq )
	{
		Node** q = deriz(pos);
		(*pos)->v = (*q)->v;
		pos = q;
	}
	Node* tmp = *pos;
	if ((*pos)->der)
	{
		*pos = (*pos)->der;
	}
	else
	{
		*pos = (*pos)->izq;
	}
	delete tmp;
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

void RecorridoArbol::reverse(Node* r)
{
	if (!r)
	{
		return;
	}
	reverse(r->der);
	cout << r->v << " ";
	reverse(r->izq);
}

void RecorridoArbol::post_orden(Node* r)
{
	if (!r)
	{
		return;
	}
	post_orden(r->izq);
	post_orden(r->der);
	cout << r->v << " ";
}

void RecorridoArbol::pre_orden(Node* r)
{
	if (!r)
	{
		return;
	}
	cout << r->v << " ";
	pre_orden(r->izq);
	pre_orden(r->der);
	
}

void RecorridoArbol::liberar_memoria(Node* r)
{
	if (!r)
	{
		return;
	}
	liberar_memoria(r->izq);
	liberar_memoria(r->der);
	delete r;
}

void RecorridoArbol::in_orden_sin_recursividad(Node* r)
{

}

Node** RecorridoArbol::deriz(Node** q)
{
	if (br == 0)
	{
		q = &(*q)->der;
		while ((*q)->izq)
		{
			q = &(*q)->izq;
		}
	}
	else
	{
		q = &(*q)->izq;
		while ((*q)->der)
		{
			q = &(*q)->der;
		}
	}
	br = !br;
	return q;
}

RecorridoArbol::~RecorridoArbol()
{
	liberar_memoria(root);
}

int main() {
	RecorridoArbol arb;
	
	arb.insert(15);
	arb.insert(25);
	arb.insert(12);
	arb.insert(7);
	arb.insert(13);
	arb.insert(18);
	arb.insert(30);

	arb.del(12);
	arb.del(30);

	//arb.post_orden(arb.root);
	//cout << endl;
	arb.in_orden(arb.root);
	//cout << endl;
	//arb.reverse(arb.root);
	//cout << endl;
	//arb.pre_orden(arb.root);

	return 0;
}
