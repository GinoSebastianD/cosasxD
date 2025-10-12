#include "iostream"
#include <vector>

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
	int kthSmallest(Node* raiz, int k);
	void inorder(Node* p, vector<int>& vec);
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
	if (!n) {
		return;
	}
	print(n->izq);
	cout << n->x << " ";
	print(n->der);
	
}

int ArbolBinario::kthSmallest(Node* raiz, int k)
{
	std::vector<int> vec;

	inorder(raiz, vec);
	return vec[k-1];
}

void ArbolBinario::inorder(Node* p, vector<int>& vec)
{
	if (!p)
	{
		return;
	}
	inorder(p->izq, vec);
	vec.push_back(p->x);
	inorder(p->der, vec);
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

	cout<< a.kthSmallest(a.tail, 3);
	cout << endl;
	a.print(a.tail);

	return 0;
}
