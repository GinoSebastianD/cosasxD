
#include <iostream>

class VectorDeque {
public:
	// Constructor con capacidad inicial de 5
	VectorDeque(int initial_capacity = 5)
	{
		// Inicializar el vector con la capacidad inicial
		// Inicializar front_index, back_index, element_count;

		data = new int[initial_capacity];
		capacity = initial_capacity - 1;             // Capacidad total del vector
		front_index = NULL;          // Índice, o puntero, del primer elemento
		back_index = NULL;           // Índice, o puntero, del último elemento
		element_count = 0;


	}

	~VectorDeque()
	{
		delete[] data;
	}

	void push_front(int x)
	{
		

		
	}

	void push_back(int x) {
		
	}

	void resize() {
		

	}

	void pop_front() {
		



	}

	void pop_back() {
		


	}

	int& operator[](int i)
	{

	}

	void print()
	{

	}

private:
	int* data;                
	int capacity;             
	int front_index;			
	int back_index;           // Índice, o puntero, del último elemento
	int element_count;        // Número de elementos

};



int main() {
	VectorDeque dq;

	// Inserta elementos
	dq.push_back(10);
	dq.push_front(5);
	dq.push_back(15);
	dq.push_front(1);
	dq.print();  // Debería mostrar: 1 5 10 15

	// Prueba del operador []
	std::cout << "Accediendo mediante operator[]: ";
	for (int i = 0; i < 4; i++) {
		std::cout << dq[i] << " ";
	}
	std::cout << std::endl;

	// Modificación mediante operator[]
	dq[0] = 100;  // Modificar el primer elemento
	dq[3] = 300;  // Modificar el último elemento
	std::cout << "Después de modificar: ";
	dq.print();   // Debería mostrar: 100 5 10 300

	// Prueba de redimensionamiento
	for (int i = 0; i < 10; i++) {
		dq.push_front(i * 10);
		dq.push_back(i * 100);
	}
	dq.print();

	// Acceso después del redimensionamiento
	std::cout << "Elemento en el índice 5: " << dq[5] << std::endl;
	std::cout << "Elemento en el índice 15: " << dq[15] << std::endl;

	// Prueba de eliminación
	for (int i = 0; i < 5; i++) {
		dq.pop_front();
		dq.pop_back();
	}
	dq.print();

	return 0;
}
