#include<iostream>
#include<deque>

struct node
{
	node* nodes[2];
	node* padre;
	int val;
	std::string Color;
	node(int x, std::string col) {
		nodes[0] = nodes[1] = nullptr;
		val = x;
		Color = col;
		padre = nullptr;
	}

};

class RedBlackTree
{
public:
	node* m_root = nullptr;
	void insert(int x);
	bool find(node**&pos, int x, std::deque<node*> deq);
	void balanceo(std::deque<node*> deq);

private:

};

void RedBlackTree::insert(int x)
{

	if (!m_root)
	{
		m_root = new node(x,"Black");
		return;
	}


	node** pos;
	std::deque<node*> deq;
	if (find(pos, x, deq))
	{
		return;
	}
	*pos = new node(x,"Red");
	deq.push_back(*pos);
	balanceo(deq);
	return;
}

bool RedBlackTree::find(node**& pos, int x, std::deque<node*> deq)
{
	pos = &m_root;
	for (;*pos && (*pos)->val != x ; pos = &(*pos)->nodes[(*pos)->val < x])
	{
		deq.push_back(*pos);
	}
	return *pos && (*pos)->val == x;
}

void RedBlackTree::balanceo(std::deque<node*> deq)
{


}
