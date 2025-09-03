#include "iostream"
using namespace std;

template<class T>
struct Node
{
	Node* next;
	T v;
	Node(T x) {
		v = x;
		next = nullptr;
	}
};

template<class T>
class CircularLinked
{
public:
	CircularLinked() {
		head = nullptr;
	};
	void insert(T x);
	void eliminar();
	void find();
	void print();

	~CircularLinked();

private:
	Node<T> * head;

};

template<class T>
void CircularLinked<T>::insert(T x)
{
	Node<T>* nuevo = new Node<T>(x);
	if (head==nullptr)
	{
		
		head = nuevo;
		head->next = head;
	}
	else if (x<head->v )
	{
		Node<T>* ant = head;
		while (ant->next != head)
		{
			ant = ant->next;
		}
		ant->next = nuevo;
		nuevo->next = head;
		head = nuevo;
	}
	else
	{
		Node<T>* tmp = head;
		while (tmp->next!=head && tmp->next->v < x)
		{
			tmp = tmp->next;
		}
		nuevo->next = tmp->next;
		tmp->next = nuevo;
	}
	

}

template<class T>
void CircularLinked<T>::eliminar()
{

}

template<class T>
void CircularLinked<T>::find()
{
}

template<class T>
void CircularLinked<T>::print()
{
	Node<T>* p = head;
	cout << "HEAD->";
	for ( ; p!=head || p == head ; p=p->next)
	{
		cout  << p->v << "->";
		if (p->next==head)
		{
			break;
		}
	}
	cout << "HEAD";
}

template<class T>
CircularLinked<T>::~CircularLinked()
{
}


int main() {
	CircularLinked<int> circu;
	circu.insert(4);
	circu.insert(3);
	circu.insert(5);
	circu.insert(7);
	circu.insert(9);
	circu.insert(11);
	circu.insert(13);


	circu.print();

}
