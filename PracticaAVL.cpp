#include <iostream>
#include <vector>

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

private:

};

bool AVL::find(int x, std::vector<node*>& vec, node**& pos)
{
	return false;
}

void AVL::insert(int x)	
{
}
