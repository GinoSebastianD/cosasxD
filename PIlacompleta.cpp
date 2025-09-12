#include "iostream"
using namespace std;
class Pila
{
public:
	Pila() {
		TOP = nullptr;
	}
	void push(int x);
	int pop();
	bool lleno();
	bool vacio();
	void print();
	int cabeza();
private:
	int* TOP;
	int arr[10] = {0};
};
void Pila::push(int x) {
	if (vacio())
	{
		TOP = arr;
		*TOP = x;
		return;
	}
	else if (!lleno())
	{
		TOP++;
		*TOP = x;
	}
	else
	{
		cout << "ta lleno" << endl;
	}
}
int Pila::pop() {
	int a = 0;
	if (vacio())
	{
		cout << "ta vacio" <<endl;
		return -1;
	}
	else
	{

		a = *TOP;
		TOP--;
		if (TOP<arr)
		{
			TOP = nullptr;
		}
		return a;
	}
	
}
bool Pila::lleno() {
	return TOP == arr + 9;
}
bool Pila::vacio() {
	return TOP == nullptr;
}
void Pila::print() {
	int* p = arr;
	for (; p <= TOP; p++)
	{
		cout << *p << " ";
	}
}

int Pila::cabeza()
{
	if (vacio()) {
		cout << "ta vacio" << endl;
	}
	return *TOP;
}
int main() {
	Pila pil;
	pil.push(5);
	pil.push(6);
	pil.push(7);
	pil.push(8);
	pil.push(9);
	pil.push(10);
	pil.push(11);
	pil.push(12);
	pil.push(13);
	pil.pop();
	pil.pop();
	pil.pop();
	pil.pop();
	pil.pop();
	pil.pop();
	pil.pop();
	cout<< pil.cabeza() << endl;

	pil.print();
	return 0;
}
