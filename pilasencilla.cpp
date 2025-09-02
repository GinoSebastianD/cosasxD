#include "iostream"
using namespace std;


class Pila
{
public:
	Pila():cabeza (nullptr) {
		arr[10] = 0;
	};
	bool push(int x);
	bool pop();
	bool llena();
	bool vacia();
	void imprimir();
	~Pila();

private:
	int arr[10];
	int* cabeza;
};


bool Pila::push(int x)
{
	if (vacia())
	{
		cabeza = &arr[0];

	}
	else
	{
		cabeza++;
	}
	*cabeza = x;
	return true;
}

bool Pila::pop()
{
	cabeza--;
	return true;
	
}

bool Pila::llena()
{
	return cabeza == &arr[9];
}

bool Pila::vacia()
{
	return cabeza == nullptr; 
}

void Pila::imprimir()
{
	for (int *q= cabeza; q >= &arr[0] ; q--)
	{
		cout << *q << " ";
	}
}

Pila::~Pila()
{
}


int main() {
	Pila pil;
	pil.push(3);
	pil.push(4);
	pil.push(5);
	pil.push(6);

	pil.pop();
	pil.imprimir();


}
