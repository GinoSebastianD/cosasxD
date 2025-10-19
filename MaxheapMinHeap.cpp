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


int main() {
	

}
