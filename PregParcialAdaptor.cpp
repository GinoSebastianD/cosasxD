#include <iostream>

struct Node
{
	int value;
	Node* next;
	Node(int _v, Node* _n = nullptr) : value(_v), next(_n) {}
};

class SinglyLinkedList
{
public:
	
	SinglyLinkedList()
	{
		head = nullptr;
	}
	
	void insert( int x)
	{
		if (head == nullptr)
		{
			head = new Node(x);
			return;
		}
		head = new Node(x, head);
	}
	
	void rem_back()
	{
		//esto no ,es una pila;
	}
	
	void rem_front()
	{
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	
	bool empty()
	{
		return head == nullptr;
	}
	
	void print()
	{
		Node* p = head;
		for (; p; p=p->next)
		{
			std::cout << p->value<< " ";
		}
	}
	
	int& front()
	{
		return head->value;
	}
	
private:
		Node* head;
};

class Stack
{
public:
	void push(int x)
	{
		FL.insert(x);
	}
	
	void pop()
	{
		FL.rem_front();
	}
	
	int& top()
	{
		return FL.front();
	}
	
	bool empty()
	{
		return FL.empty();
	}
	
	void print()
	{
		FL.print();
	}
	
private:
	SinglyLinkedList FL;
};

int main()
{
	// Pruebas del stack
	Stack stack;
	
	// Prueba 1: Inserción de elementos
	std::cout << "Prueba 1: Insertando elementos" << std::endl;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	std::cout << "Stack: ";
	stack.print();
	
	// Prueba 2: Acceso al elemento superior
	std::cout << "\nPrueba 2: Elemento superior" << std::endl;
	std::cout << "Top: " << stack.top() << std::endl;
	
	// Prueba 3: Eliminación de elementos
	std::cout << "\nPrueba 3: Eliminando elementos" << std::endl;
	stack.pop();
	std::cout << "Después de pop: ";
	stack.print();
	std::cout << "Nuevo top: " << stack.top() << std::endl;
	
	// Prueba 4: Verificación de pila vacía
	std::cout << "\nPrueba 4: Verificación de pila vacía" << std::endl;
	std::cout << "¿Está vacía? " << (stack.empty() ? "Sí" : "No") << std::endl;
	
	// Prueba 5: Vaciado completo de la pila
	std::cout << "\nPrueba 5: Vaciado completo" << std::endl;
	stack.pop(); // Queda un elemento
	stack.pop(); // Queda vacía
	std::cout << "Después de vaciar: ";
	stack.print();
	std::cout << "¿Está vacía? " << (stack.empty() ? "Sí" : "No") << std::endl;
	
	// Prueba 6: Operaciones adicionales
	std::cout << "\nPrueba 6: Operaciones adicionales" << std::endl;
	for (int i = 1; i <= 5; i++)
	{
		stack.push(i * 10);
	}
	std::cout << "Después de insertar 5 elementos: ";
	stack.print();
	
	return 0;
}
