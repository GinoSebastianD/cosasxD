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
	bool push(T x);
	bool lleno();
	bool vacio();

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
	if (vacio())
	{
		cout << "ta vacio";
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
bool Cola<T>::push(T x)
{

	if (lleno())
	{
		cout << "se lleno" << endl;
		return false;
	}
	if (head == nullptr)
	{
		tail = arr;
		head = arr;
		tail++;
		*head = x;
		elem++;
		return true;
	}
	if (tail > arr + 9 && head != arr)
	{
		tail = arr;
		*tail = x;
		tail++;
		elem++;
		return true;
	}


	else
	{
		*tail = x;
		tail++;
		elem++;
		return true;
	}

}

template<class T>
bool Cola<T>::lleno()
{
	if (head == arr && tail == arr + 10)
	{
		return true;
	}
	if (head != nullptr && head != arr && tail == head)
	{
		return true;
	}

	return false;
}
template<class T>
bool Cola<T>::vacio()
{
	if (head == nullptr && tail == nullptr)
	{
		return true;
	}
	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
		return true;
	}
	return false;
}
template<class T>
void Cola<T>::print() {
	if (vacio()) {
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
	col.print();
	int val;
	for (int i = 0; i < 9; i++) {
		col.pop(val); // Vacía la cola
	}
	for (int i = 0; i < 1; i++) {
		col.push(i);
	}
	int x;
	col.pop(x);
	col.pop(x);
	col.print();






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
}
