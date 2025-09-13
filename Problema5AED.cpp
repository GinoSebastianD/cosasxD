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
		cout << "se lleno"<< endl;
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
int main() {
	Cola<int> col;
	for (int i = 0; i < 10; i++) {
		col.push(i); 
	}
	int val;
	for (int i = 0; i < 5; i++) {
		col.pop(val);
	}
	col.push(11);



	//for (int i = 0; i < 10; i++) {
	//	col.push(i); // Llena la cola
	//}
	//int val;
	//for (int i = 0; i < 10; i++) {
	//	col.pop(val); // Vacía la cola
	//}
	//col.pop(val);
	
	//for (int i = 0; i < 10; i++)
	//{
	//	col.push(i);
	//}
	//for (int i = 0; i < 5; i++)
	//{
	//	col.pop(i);
	//}
	//for (int i = 0; i < 5; i++)
	//{
	//	col.push(i);
	//}


	//for (int i = 0; i < 10; i++)
	//{
	//	col.push(i);
	//}
	//int val;
	//col.pop(val);
	//cout << val << endl;
	//col.push(15);
	col.print();
}
