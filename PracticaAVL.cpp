#include <iostream>
#include <vector>
using namespace std;

struct node
{
	node* nodes[2];
	int val;
	int altura;
	node(int x) {
		val = x;
		nodes[0] = nodes[1] = nullptr;
		altura = 1;
	}
};

class AVL
{
public:
	
	node* root = nullptr;
	void insert( int x);
	bool find(int x, std::vector<node*>& vec, node**& pos);
	void balanceo(std::vector<node*>& vec);

	int altura(node* root);
	int diferencia(node* root);

	node* rotacion_der(node* y);
	node* rotacion_iz(node* x);

	void in_orden(node* root);
	void print();

private:

};

void AVL::insert(int x)
{
	node** pos = nullptr;
	std::vector<node*> vec;
	if (find(x,vec,pos))
	{
		return;
	}
	*pos = new node(x);
	vec.push_back(*pos);
	balanceo(vec);
	return;
}

bool AVL::find(int x, std::vector<node*>& vec, node**& pos)
{
	for (pos = &root ; *pos && (*pos)->val != x ; pos = &(*pos)->nodes[(*pos)->val< x])
	{
		if (*pos)
		{
			vec.push_back(*pos);
		}
	}
	return *pos && (*pos)->val == x;
}

void AVL::balanceo(std::vector<node*>& vec)
{
	for (int i = (vec.size() - 1); i >= 0; i--)
	{
		node* act = vec[i];
		act->altura = altura(act);
		int balanceo = diferencia(act);
		if (balanceo < -1)
		{
			if (altura(act->nodes[0]) <= 0)
			{
				node* n_root = rotacion_der(act);
				if (i == 0)
				{
					root = n_root;
				}
				else
				{
					node* padre = vec[i - 1];
					if (padre->nodes[0] == act)
					{
						padre->nodes[0] = n_root;
					}
					else
					{
						padre->nodes[1] = n_root;
					}
				}
			}
			else
			{
				node* temp = rotacion_iz(act->nodes[0]);
				act->nodes[0] = temp;
				node* n_root = rotacion_der(act);
				if (i == 0)
				{
					root = n_root;
				}
				else
				{
					node* padre = vec[i - 1];
					if (padre->nodes[0] == act)
					{
						padre->nodes[0] = n_root;
					}
					else
					{
						padre->nodes[1] = n_root;
					}
				}
				
			}
		}
		else if (balanceo >1)
		{
			if (altura(act->nodes[1]) >= 0)
			{
				node* n_root = rotacion_iz(act);
				if (i == 0)
				{
					root = n_root;
				}
				else
				{
					node* padre = vec[i - 1];
					if (padre->nodes[0] == act)
					{
						padre->nodes[0] = n_root;
					}
					else
					{
						padre->nodes[1] = n_root;
					}
				}
			}
			else
			{
				node* temp = rotacion_der(act->nodes[1]);
				act->nodes[1] = temp;
				node* n_root = rotacion_iz(act);
				if (i == 0)
				{
					root = n_root;
				}
				else
				{
					node* padre = vec[i - 1];
					if (padre->nodes[0] == act)
					{
						padre->nodes[0] = n_root;
					}
					else
					{
						padre->nodes[1] = n_root;
					}
				}
			}

		}

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
	return 1 + max(izq, der);
}

int AVL::diferencia(node* root)
{
	int izq = 0;
	int der = 0;
	if (root->nodes[0])
	{
		izq = root->altura;
	}
	if (root->nodes[1])
	{
		der = root->altura;
	}
	return der - izq;
}

node* AVL::rotacion_der(node* y)
{
	node* x = y->nodes[0];
	node* tmp = x->nodes[1];

	x->nodes[1] = y;
	y->nodes[0] = tmp;

	y->altura = altura(y);
	x->altura = altura(x);

	return x;
}

node* AVL::rotacion_iz(node* x)
{
	node* y = x->nodes[1];
	node* tmp = y->nodes[0];

	y->nodes[0] = x;
	x->nodes[1] = tmp;


	x->altura = altura(x);
	y->altura = altura(y);

	return y;
}

void AVL::in_orden(node* root)
{
	if (!root)
	{
		return;
	}
	in_orden(root->nodes[0]);
	cout << root->val << " ";
	in_orden(root->nodes[1]);
}

void AVL::print()
{
	in_orden(root);
}

int main() {
	AVL avl;
	for (int i = 0; i < 10; i++)
	{
		avl.insert(i);
	}
	avl.print();
}
