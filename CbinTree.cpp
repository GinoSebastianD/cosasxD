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
	ArbolBinario();

	bool find(int x , Node**& pos);
	bool insert(int x);
	bool del(int x);
	~ArbolBinario();

private:
	Node* tail;
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
	return false;
}

ArbolBinario::~ArbolBinario()
{
}
