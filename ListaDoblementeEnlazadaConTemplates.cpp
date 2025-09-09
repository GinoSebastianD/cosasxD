#include "iostream"
using namespace std;

template<class T>
struct Node
{

	Node* next;
	Node* prev;
	T v;
	Node(T x) {
		v = x;
		next = nullptr;
		prev = nullptr;
	}
};

template<class T>
class LD
{
public:
	LD() {
		head = nullptr;
		tail = nullptr;
	}
	void insert(T x);
	void del(T x);
	void print();
	bool find(Node<T>*&pos,T x);

	~LD();

private:
	Node<T>* head;
	Node<T>* tail;
};




template<class T>
bool LD<T>::find(Node<T>*& pos, T x)
{
	pos = head;
	for (; pos->next != 0 && pos->v < x; pos = pos->next);
	return pos != 0 && pos->v == x;

}
template<class T>
void LD<T>::insert(T x)
{
	Node<T>* pos;
	if (head == nullptr)
	{
		head = new Node<T>(x);
		tail = head;
		return;
	}
	if (find(pos,x))
	{
		return;
	}

	Node<T>* ant = new Node<T>(x);
	if (x < pos->v)
	{
		head = ant;
		ant->next = pos;
		pos->prev = ant;
		return;
	}
	if (pos->next!=nullptr)
	{

	}


	pos->next = ant;
	ant->prev = pos;

	
}

template<class T>
void LD<T>::del(T x)
{
}

template<class T>
void LD<T>::print()
{
	Node<T>* p = head;
	cout << "NULL->";
	while (p)
	{
		cout << p->v << "->";
		p = p->next;
	}
	cout << "NULL";
}


template<class T>
LD<T>::~LD()
{
}
int main() {
	LD<int> ld;
	ld.insert(4);
	ld.insert(3);
	ld.insert(2);
	ld.insert(5);
	ld.print();

}
