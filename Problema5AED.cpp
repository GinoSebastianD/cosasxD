// si head pasa a tail esta vacio
// si head y tail apuntan al mismo lugar , queda un elemento
//Caso : cuando la cola la llenamos , la vaciamos y luego hacemos POP , el head debe volver
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
	if (head >  arr+9 )
	{
		head = arr;
		x = *head;
		head++;
		return true;
	}
	else
	{
		x = *head;
		head++;
		return true;
	}
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
	if (head == tail)
	{
		cout<<"Vacia";
		return;
	}
	int* p = head;
	while (p < arr + 10)
	{
		if (head>tail)
		{
			cout << *p << " ";
			p++;
		}
		else {
			p++;
		}
	}


	p = arr;
	while (p<tail)
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
	int val;
	col.pop(val);
	cout << val << endl;

	col.print();
}
