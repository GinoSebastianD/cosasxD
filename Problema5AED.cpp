// si head pasa a tail esta vacio
// si head y tail apuntan al mismo lugar , queda un elemento
//
#include "iostream"
using namespace std;

class Cola
{
public:
	Cola() {
		head = nullptr;
		tail = nullptr;
	}

	bool pop(int & x);
	void push(int x);
	void print();

	~Cola();

private:
	int* head;
	int* tail;
	int arr[10];
};



bool Cola::pop(int & x)
{
	x = *head;
	head++;
	return true;
}

void Cola::push(int x)
{
	if (head == nullptr)
	{
		tail = arr;
		head = arr;
		*head = x;
		tail++;
		return;
	}
	if (tail > arr + 9 && head != arr)
	{
		tail = arr;
		*tail = x;
		tail++;
		return;
	}
	else
	{
		*tail = x;
		tail++;
	}
	
}

void Cola::print()
{
	int* p = head;
	while (p < arr +10)
	{
		cout << *p << " ";
		p++;
	}
}



Cola::~Cola()
{


}




int main() {
	Cola col;
	col.push(1);
	col.push(2);
	col.push(3);
	col.push(4);
	col.push(5);
	col.push(6);
	col.push(7);
	col.push(8);
	col.push(9);
	col.push(10);
	int eliminado;
	col.pop(eliminado);
	col.push(11);
	cout << eliminado << endl;

	col.print();
}
