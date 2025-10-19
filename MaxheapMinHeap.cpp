#include <iostream>
#include <deque>
using namespace std;

struct Node
{
	Node* nodes[2];
	int v;
	Node* padre;
	Node(int x) {
		nodes[0] = nodes[1] = nullptr;
		padre = nullptr;
		v = x;
	}
};
class heap
{
public:

	heap() {
		root = nullptr;
	};
	~heap();
	void push(int x);
	void heap_max(Node* root);
	bool find(int x,Node* root);
	void print();
private:
	Node* root;
	std::deque<Node*> col;
};



heap::~heap()
{
}
bool heap::find(int x, Node* root)
{
	if (!root)
	{
		return false;
	}
	if (root->v == x)
	{
		return true;
	}
	return find(x, root->nodes[0]) || find(x, root->nodes[1]);
}

void heap::print()
{
	std::deque<Node*> deq;
	deq.push_back(root);
	while (!deq.empty())
	{
		Node* front = deq.front();
		std::cout << front->v << " ";
		deq.pop_front();

		if (front->nodes[0])
		{
			deq.push_back(front->nodes[0]);
		}
		if (front->nodes[1])
		{
			deq.push_back(front->nodes[1]);
		}
	}

}


void heap::push(int x)
{
	if (!root)
	{
		root = new Node(x);
		col.push_back(root);
		return;
	}
	Node* cabeza = col.front();
	Node* newNode = new Node(x);
	newNode->padre = cabeza;
	if (!cabeza->nodes[0])
	{
		cabeza->nodes[0] = newNode;
	}
	else
	{
		cabeza->nodes[1] = newNode;
		col.pop_front();
	}
	col.push_back(newNode);
	heap_max(newNode);
	return;

}

void heap::heap_max(Node* root)
{
	while (root->padre && root->v > root->padre->v)
	{
		swap(root->v, root->padre->v);
		root = root->padre;
	}
}




int main() {
	heap hmax;
	for (int i = 1; i <= 10; ++i) {
		hmax.push(i);
	}
	hmax.print();
}
