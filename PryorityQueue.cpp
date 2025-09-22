#include "iostream"
class Pri_queue
{
public:

	int arr[10];
	int* head;
	int* tail;

	Pri_queue() {
		head = nullptr;
		tail = nullptr;
	}
	

	void push(int x); //Inserta un elemento y ordena el contenedor subyacente
	void pop(); //elimina el elemento superior
	bool empty();
	void print();
	int top();
	~Pri_queue();

private:

};

void Pri_queue::push(int x)
{
	if (empty())
	{
		std::cout << "ta vacio" << std::endl;
		return;
	}
	if (head == nullptr && tail == nullptr)
	{
		head = arr;
		tail = arr;
		*head = x;
		return;
	}
	tail++;
	*tail = x;
	for (int i =tail-head; i > 0; i--)
	{
		if (*(arr+i) > *(arr+i-1))
		{
			std::swap(*(arr + i), *(arr + i - 1));
		}
		else
		{
			break;
		}
	}
}

void Pri_queue::pop()
{

}

bool Pri_queue::empty()
{
	return false;
}

void Pri_queue::print()
{
	int* p = head;
	for (;p <= tail; p++)
	{
		std::cout << *p << " ";
	}
}

int Pri_queue::top()
{
	return *head;
}

Pri_queue::~Pri_queue()
{
}

int main() {
	Pri_queue queue;
	queue.push(5);
	queue.push(4);
	std:: cout << queue.top() << std::endl;
	queue.print();

}
