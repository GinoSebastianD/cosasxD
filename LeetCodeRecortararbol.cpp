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
			
	bool find(int x, Node**& pos);
	bool insert(int x);
	bool del(int x);
	void print(Node* n);
	Node* trimBST(Node* root, int low, int high);
	Node* inorden(Node* raiz, int low, int high);

	~ArbolBinario();

private:
};

ArbolBinario::ArbolBinario()
{
	tail = nullptr;
}

bool ArbolBinario::find(int x, Node**& pos)
{
	pos = &tail;
	while (*pos != nullptr && (*pos)->x != x)
	{
		if ((*pos)->x > x)
		{
			pos = &(*pos)->izq;
		}
		else
		{
			pos = &(*pos)->der;
		}
	}
	return *pos != nullptr;
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
	if (!find(x, pos))
	{
		return false;
	}

	if ((*pos)->der && (*pos)->izq)
	{
		Node** tmp_2 = &(*pos)->der;
		while ((*tmp_2)->izq != nullptr)
		{
			tmp_2 = &(*tmp_2)->izq;
		}
		(*pos)->x = (*tmp_2)->x;
		pos = tmp_2;
	}
	Node* tmp_3 = *pos;
	if ((*pos)->der)
	{
		*pos = tmp_3->der;
	}
	else
	{
		*pos = tmp_3->izq;
	}
	delete tmp_3;

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


Node* ArbolBinario::trimBST(Node* root, int low, int high)
{
	
	return inorden(root, low, high);
}

Node* ArbolBinario::inorden(Node* raiz , int low , int high)
{
	if (!raiz)
	{
		return nullptr;
	}
	if (raiz->x < low )
	{
		return inorden(raiz->der, low, high);
	}
	if (raiz->x > high)
	{
		return inorden(raiz->izq, low, high);
	}
	raiz->izq = inorden(raiz->izq, low, high);
	raiz ->der = inorden(raiz->der, low, high);
	return raiz;
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

	a.trimBST(a.tail, 32, 52);
	a.print(a.tail);
	return 0;
}
