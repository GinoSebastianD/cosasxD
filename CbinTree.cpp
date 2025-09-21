#include "iostream"
using namespace std;

struct Node
{
	Node* izq;
	Node* der;
	int x;
	Node(int v) {
		x = v;
		izq = nullptr;
		der = nullptr;
	}
};

class ArbolBinario
{
public:
	Node* tail;

	ArbolBinario();

	bool find(int x , Node**& pos);
	bool insert(int x);
	bool del(int x);
	void print(Node* n);
	~ArbolBinario();

private:
};

ArbolBinario::ArbolBinario()
{
	tail = nullptr;
}

bool ArbolBinario::find(int x , Node**& pos)
{
	pos = &tail;
	while (*pos!=nullptr && (*pos)->x != x)
	{
		if ((*pos)->x < x)
		{
			pos = &(*pos)->izq;
		}
		else
		{
			pos = &(*pos)->der;
		}
	}
	return *pos!=nullptr;
}

bool ArbolBinario::insert(int x)
{
	Node** pos;
	if (find(x, pos))
	{
		return false;
	}
	*pos = new Node(x);
}

bool ArbolBinario::del(int x)
{
	Node** pos = nullptr;
	if (!find(x,pos))
	{
		return false;
	}
	Node* nod = *pos;
	//primer caso , nodos hoja
	if (nod->der == nullptr && nod->izq == nullptr)
	{
		*pos = nullptr;
		delete nod;
		return true;
	}
	//segundo caso, nodos con un hijo
	if (nod->der == nullptr)
	{
		*pos = nod->der;
		delete nod;
		return true;
	}

	if (nod->izq == nullptr)
	{
		*pos = nod->izq;
		delete nod;
		return true;
	}	
	//tercer caso , nodos con dos hijos

	Node** tmp_2 = &(*pos)->der;
	while ( (*tmp_2)->izq != nullptr )
	{
		tmp_2 = &(*tmp_2)->izq;
	}
	nod->x = (*tmp_2)->x;
	Node* tmp_3 = *tmp_2;
	*tmp_2 = (*tmp_2)->der; // aqui siempre a la derecha , pq puede haber un caso donde el menor nodo del sub arbol izquierda tenga solo un hijo pero no dos.
	delete tmp_3;
	return true;
}

void ArbolBinario::print(Node* n)
{
	if (n == nullptr) {
		return;
	}
	if (n->izq) {
		print(n->izq);
	}
	cout << n->x << " ";
	if (n->der) {
		print(n->der);
	}
}

ArbolBinario::~ArbolBinario()
{
	delete tail;
}
int main() {
	ArbolBinario a;
	a.insert(52);
	a.insert(41);
	a.insert(64);
	a.insert(55);
	a.insert(32);
	a.insert(44);
	a.insert(73);
	a.insert(56);

	Node* temp = a.tail;
	a.print(temp);
	cout << endl;

	a.del(52);
	a.print(temp);
	cout << endl;

	a.del(44);
	a.print(temp);
	cout << endl;

	return 0;
}
