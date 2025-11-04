#include <iostream>
#include <vector>
using namespace std;
struct node
{
	node* nodes[2] = {};
	int v;
	int altura;
	node(int x) {
		nodes[0] = nodes[1] = nullptr;
		v = x;
		altura = 1;
	}
};

class AVL
{
public:
	bool find(int x , std::vector<node*>& vec , node ** &pos);
	void insert(int x);
	bool balanceo(std::vector<node*>&vec);
	int altura(node* root);
	node* root = 0;
private:

};

bool AVL::find(int x, std::vector<node*>& vec, node**& pos)
{
	for (pos = &root ; *pos && (*pos)->v != x ; pos = &(*pos)->nodes[(*pos)->v<x])
	{
		if (*pos)
		{
			vec.push_back(*pos);
		}
	}
	return *pos != nullptr;
}

void AVL::insert(int x)	
{
	node** pos;
	std::vector<node*> vec;
	if (!find(x,vec,pos))
	{
		return;
	}
	*pos = new node(x);
	vec.push_back(*pos);
	balanceo(vec);
	return;
}

bool AVL::balanceo(std::vector<node*>&vec)
{
	for (int i = (vec.size()-1) ; i >0 ; i-- )
	{
		node* ref = vec[i];
		ref->altura = altura(ref);

	}
}

int AVL::altura(node* root)
{
	int izq = 0;
	int der = 0;
	if (!root)
	{
		return 0;
	}
	if (root->nodes[0])
	{
		izq = root->altura;
	}
	if (root->nodes[1])
	{
		der = root->altura;
	}
	return 1 + max(izq,der);
}
