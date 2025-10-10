
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
		if (front_index == NULL && back_index == NULL)
		{
			front_index = back_index = capacity / 2;
			data[front_index] = x;
			element_count++;
			return;
		}
		if (front_index == 0)
		{
			resize();
		}
		front_index--;
		data[front_index] = x;
		element_count++;

		
	}

	void push_back(int x) {
		if (front_index == NULL && back_index == NULL)
		{
			front_index = back_index = capacity / 2;
			data[back_index] = x;
			element_count++;
			return;
		}
		if (back_index == capacity)
		{
			resize();
		}
		back_index++;
		data[back_index] = x;
		element_count++;
	}

	void resize() {
		int tamnew = (capacity+1) * 2;
		int* newmap = new int[tamnew];
		int ini = (tamnew-element_count)/2;
		for (int i = front_index; i <= back_index; i++)
		{
			newmap[ini + i] = data[i];
		}
		delete[] data;
		data = newmap;
		front_index = ini;
		back_index = front_index + element_count - 1;
		capacity = tamnew;
 	}

	void pop_front() {
		
		if (back_index == front_index)
		{
			back_index = front_index = NULL;
			element_count--;
		}
		if (front_index == capacity)
		{
			std::cout << "vacio";
		}
		else
		{
			front_index++;
			element_count--;
		}
		


	}

	void pop_back() {
		if (back_index == front_index)
		{
			back_index = front_index = NULL;
			element_count--;
		}
		if (back_index == 0)
		{
			std::cout << "vacio";
		}
		else
		{
			back_index--;
			element_count--;
		}


	}

	int& operator[](int i)
	{
		return data[front_index + i];
	}

	void print()
	{
		for (int i = front_index ; i <= back_index; i++)
		{
			std::cout << data[i] << " ";
		}
	}

private:
	int* data;                
	int capacity;             
	int front_index;			
	int back_index;           
	int element_count;       

};



int main() {
	VectorDeque dq;
	 
	dq.push_back(10);
	dq.push_front(5);
	dq.push_back(15);
	dq.push_front(1);
	dq.print(); 

	std::cout << "Accediendo mediante operator[]: ";
	for (int i = 0; i < 4; i++) {
		std::cout << dq[i] << " ";
	}
	std::cout << std::endl;

	dq[0] = 100;  
	dq[3] = 300;  
	std::cout << "Después de modificar: ";
	dq.print();   
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		dq.push_front(i * 10);
		dq.push_back(i * 100);
	}
	dq.print();
	std::cout << std::endl;

	std::cout << "Elemento en el índice 5: " << dq[5] << std::endl;
	std::cout << "Elemento en el índice 15: " << dq[15] << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {
		dq.pop_front();
		dq.pop_back();
	}
	dq.print();

	return 0;
}
