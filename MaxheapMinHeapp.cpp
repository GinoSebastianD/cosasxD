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
	int pop();
	void arriba(Node* node);
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

int heap::pop()
{
	if (!root) return -1;

	int maxValue = root->v;
	Node* lastNode = root;

	deque<Node*> q;
	q.push_back(root);
	while (!q.empty()) {
		lastNode = q.front();
		q.pop_front();
		if (lastNode->nodes[0]) q.push_back(lastNode->nodes[0]);
		if (lastNode->nodes[1]) q.push_back(lastNode->nodes[1]);
	}

	if (root != lastNode) {
		root->v = lastNode->v;

		Node* parent = lastNode->padre;
		if (parent->nodes[0] == lastNode) {
			parent->nodes[0] = nullptr;
		}
		else {
			parent->nodes[1] = nullptr;
			col.push_front(parent);
		}
	}
	else {
		root = nullptr;
		while (!col.empty()) {
			col.pop_front();
		}
	}

	delete lastNode;
	arriba(root);
	return maxValue;
}

void heap::arriba(Node* node)
{
	while (node) {
		Node* maxChild = nullptr;
		if (node->nodes[0] && node->nodes[1]) {
			maxChild = node->nodes[0]->v > node->nodes[1]->v ?
				node->nodes[0] : node->nodes[1];
		}
		else if (node->nodes[0]) {
			maxChild = node->nodes[0];
		}
		else if (node->nodes[1]) {
			maxChild = node->nodes[1];
		}

		if (maxChild && maxChild->v > node->v) {
			swap(node->v, maxChild->v);
			node = maxChild;
		}
		else {
			break;
		}
	}
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
	for (int i = 1; i <= 10; i++)
	{
		hmax.push(i);
	}
	cout << hmax.pop() << endl;;
	hmax.print();
}
