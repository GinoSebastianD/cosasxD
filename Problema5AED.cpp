// si head pasa a tail esta vacio
// si head y tail apuntan al mismo lugar , queda un elemento
//Caso : cuando la cola la llenamos , la vaciamos y luego hacemos POP , el head debe volver
#include "iostream"
using namespace std;

template<class T>
class Cola
{
public:
	Cola() {
		head = nullptr;
		tail = nullptr;
		elem = 0;
	}

	bool pop(T& x);
	void push(T x);
	void print();
	int front();
	int back();


private:
	T* head;
	T* tail;
	T arr[10];
	T elem;
};


template<class T>
bool Cola<T>::pop(T& x)
{
	if (elem == 0)
	{
		return false;
	}
	if (head == nullptr) {
		return false;
	}
	if (head > arr + 9)
	{
		head = arr;
		x = *head;
		head++;
		elem--;
		return true;
	}
	else
	{
		x = *head;
		head++;
		elem--;
		return true;
	}
}
template<class T>
void Cola<T>::push(T x)
{
	if (elem == 10)
	{
		cout << "se lleno" << endl;
		return;
	}
	if (head == nullptr)
	{
		tail = arr;
		head = arr;
		*head = x;
		tail++;
		elem++;
		return;
	}
	if (tail > arr + 9 && head != arr)
	{
		tail = arr;
		*tail = x;
		tail++;
		elem++;
		return;
	}
	else
	{
		*tail = x;
		tail++;
		elem++;
	}

}
template<class T>
void Cola<T>::print() {
	if (elem == 0) {
		cout << "ta vacia" << endl;
		return;
	}
	T* p = head;
	int count = 0;
	while (count < elem) {
		cout << *p << " ";
		p++;
		if (p > arr + 9) {
			p = arr;
		}
		count++;
	}
	cout << endl;
}
template<class T>
int Cola<T>::front() // acceder al primer elemento
{
	if (elem == 0)
	{
		cout << "ta vacia";
		return -1;
	}
	cout << *head <<endl;
	return *head;
}
template<class T>
int Cola<T>::back() //acceder al último elemento
{
	if (elem == 0)
	{
		cout << "ta vacia";
		return -1;
	}
	cout << *tail << endl;
	return *tail;

}
int main() {
	Cola<int> col;
	for (int i = 5; i < 10; i++) {
		col.push(i);
	}
	col.print();

	cout << endl;
	col.front();
	cout << endl;
	int val;
	for (int i = 0; i < 5; i++) {
		col.pop(val);

		cout << val << " ";
	}
	cout << endl;
	col.front();


}
