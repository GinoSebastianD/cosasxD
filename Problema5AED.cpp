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
};


template<class T>
bool Cola<T>::pop(T& x)
{
	if (vacio())
	{
		cout << "ta vacio";
		return false;
	}

	else if (!head) {
		return false;
	}
	else if (head + 1 == arr + 10)
	{

		x = *head;
		head = arr;
		return true;
	}
	else
	{
		x = *head;
		head++;
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
	else if (!head)
	{
		tail = head = arr;
	}
	else if (tail == arr + 9 && head != arr)
	{

		tail = arr;

	}
	else
	{
		
		tail++;
	}
	*tail = x;
	return true;

}

template<class T>
bool Cola<T>::lleno()
{
	if (head == arr && tail == arr + 10)
	{
		return true;
	}
	if (tail+1 == head)
	{
		return true;
	}
	//if (head != nullptr && head != arr && tail == head)
	//{
	//	return true;
	//}

	return false;
}
template<class T>
bool Cola<T>::vacio()
{
	if (head == nullptr && tail == nullptr)
	{
		return true;
	}
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
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
	cout << *p << " "; // Imprimir el primer elemento

	// Imprimir los elementos restantes hasta llegar a tail
	while (p != tail) {
		p++;
		if (p > arr + 9) {
			p = arr;
		}
		cout << *p << " ";
	}
	cout << endl;
}
int main() {
	Cola<int> col;
	for (int i = 0; i < 10; i++) {
		col.push(i);
	}
	col.print();
	cout << endl;
	int val;
	for (int i = 0; i < 5; i++) {
		col.pop(val); // Vacía la cola
	}
	col.print();
	for (int i = 0; i < 5; i++) {
		col.push(i);
	}
	col.print();
	int x;
	for (int i = 0; i < 10; i++) {
		col.pop(x); // Vacía la cola
	}
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
	//int x = 0;
	//col.pop(x);
	//cout << x << endl;
	//col.push(15);
}
