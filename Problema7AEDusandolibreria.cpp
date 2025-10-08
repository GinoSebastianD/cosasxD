#include "iostream"
#include "queue"
#include <cstdlib> 
using namespace std;


struct Node
{
	Node* nodes[2];
	int v;
	Node(int x) {
		nodes[0] = nullptr;
		nodes[1] = nullptr;
		v = x;
	}

};

void inorden(Node* n) {
	if (!n)
	{
		return;
	}
	inorden(n->nodes[0]);
	cout << n->v << " ";
	inorden(n->nodes[1]);

}

template <class T, int N>
Node* arbol(T* ini, T* fin) {
	queue<Node*> col;
	
	for (int i = 0; i < N; i++)
	{
		Node* raiz = new Node(*(ini+i));
		col.push(raiz);
	}

	while (col.size() > 1)
	{
		Node* a = col.front();
		col.pop();
		Node* b = col.front();
		col.pop();

		Node* padre = new Node(a->v + b->v);
		padre->nodes[0] = a;
		padre->nodes[1] = b;
		col.push(padre);

	}


	return col.front();
	

}


int main() {
	srand(time(0));
	const int N = 4;
	int arr[N];
	

	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 10;
	}

	Node* root = arbol<int, N>(arr, arr + N);
	inorden(root);

}
