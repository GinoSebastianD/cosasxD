

#include "iostream"
using namespace std;

struct Node
{
	Node* next;
	int v;
	Node(int x) {
		v = x;
		next = nullptr;
	}
};

template <class T>
class FL
{
public:
	FL() {
		head = nullptr;
	};
	void insert(T x);
	bool find(Node **& pos, T x);

	void imprimir();
	



	~FL();

private:
	Node* head;
};

template<class T>
bool FL<T>::find(Node**& pos, T x)
{
	pos = &head;
	for (; *pos != 0 && (*pos)->v <= x; pos = &(*pos)->next);
	return *pos && (*pos)->v == x;
}
template<class T>
void FL<T>::insert(T x)
{
	Node** pos;
	find(pos, x);
	Node* tmp = new Node(x);
	tmp->next = *pos;
	*pos = tmp;

}
template<class T>
void FL<T>::imprimir()
{
	Node* q = head;
	for (; q; q=q->next)
	{
		cout << q->v << "->";
	}
	cout << "NULL";
}
template<class T>
FL<T>::~FL()
{
	Node* elimi = head;
	while (elimi)
	{
		
		head = head->next;
		delete elimi;
		elimi = head;
	}

}



int main() {
	FL<int> fl;
	fl.insert(4);
	fl.insert(3);
	fl.insert(2);
	fl.insert(1);
	fl.insert(2);
	fl.insert(2);
	fl.insert(2);

	fl.imprimir();
}
