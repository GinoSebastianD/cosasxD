#include "iostream"
using namespace std;


struct Node
{
	Node* next;
	int v;
	Node(int x) {
		v = x;
		next = 0;
	}
};


class FL
{
public:
	FL() {
		head = 0;
	};
	void insert(int x);
	void print();
	Node* removeElements(Node* head, int val);

	Node* getHead() {
		return head;
	}
	void setHead(Node* h) {
		head = h;
	}

	~FL();

private:
	Node* head;

};

Node* FL::removeElements(Node* head, int x) {
	

		while (head && head->v==x)
		{
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
		Node* prev = head;
		Node* p = head;
	while (p)

	{
		
		p = p->next;
		while (p && p->v == x)
		{
			prev->next = p->next;
			Node* q = p->next;
			delete p;
			p = q;
		}
		prev = p;
	}

	return head;
}




void FL::insert(int x)
{
	Node* p = new Node(x);
	p->next = head;
	head = p;

}
void FL::print() {
	Node* x = head;
	for (; x; x=x->next)
	{
		cout << x->v << "->";
	}
	cout << "Null"; 

}

FL::~FL()
{
	Node* del = head;
	while (del)
	{
		head = del->next;
		delete del;
		del = head;
	}
}

int main() {
	FL fl;
	fl.insert(4);
	fl.insert(5);
	fl.insert(6);
	fl.insert(4);
	fl.insert(8);
	fl.insert(4);
	fl.setHead(fl.removeElements(fl.getHead(), 4));

	fl.print();
}
