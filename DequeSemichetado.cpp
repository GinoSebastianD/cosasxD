//formula indices
//calculo de nelem en el deque y metodos set y get para acceder al nelem
#include "iostream"
using namespace std;
template<class T>
class Deque
{
public:
	Deque(T tam_m, T tam_arr) {
		tam_map = tam_m;
		tam_array = tam_arr;
		map = new T * [tam_map];
		ini = map + (tam_map / 2);
		fin = ini;
		ini_array = nullptr;
		fin_array = nullptr;
		nelem = 0;
	}


	void push_front(T x);
	void push_back(T x);
	T pop_back();
	T pop_front();
	void print();
	T& operator[](T x);
	~Deque();

	void set_nelem() {
		nelem = nelem; 
	}
	int get_nelem() {
		return nelem; 
	}

private:
	T** map;
	T** ini;
	T** fin;
	T* ini_array;
	T* fin_array;
	T tam_map;
	T tam_array;
	T nelem;
};

template<class T>
void Deque<T>::push_front(T x)
{
	if (ini_array == nullptr)
	{
		*ini = new T [tam_array];
		ini_array = *ini + (tam_array/2);
		fin_array = ini_array;
		*ini_array = x;
		nelem++;
	}
	else if (ini_array == *ini)
	{
		ini--;
		*ini = new T[tam_array];
		ini_array = *ini + tam_array-1;
		*ini_array = x;
		nelem++;
	}
	else
	{
		ini_array--;
		*ini_array = x;
		nelem++;

	}

}
template<class T>
void Deque<T>::push_back(T x)
{
	if (fin_array == nullptr)
	{
		*fin = new T[tam_array];
		fin_array = *fin + (tam_array/2);
		ini_array = fin_array;
		*fin_array = x;
		nelem++;

	}
	else if(fin_array == *fin + tam_array-1)
	{
		fin++;
		*fin = new T[tam_array];
		fin_array = *fin;
		*fin_array = x;
		nelem++;

	}
	else
	{
		fin_array++;
		*fin_array = x;
		nelem++;

	}
}
template<class T>
T Deque<T>::pop_front()
{
	int contenedor = 0;
	
	if (ini_array == nullptr && fin_array == nullptr)
	{
		return -1;
	}
	else if (ini_array == fin_array)
	{
		contenedor = *ini_array;
		ini_array = nullptr;
		fin_array = nullptr;
		delete[] * ini;

	}
	else if (ini_array == *ini+(tam_array-1))
	{
		contenedor = *ini_array;
		delete[] * ini;
		ini++;
		ini_array = *ini;
		nelem--;
	}
	else
	{
		contenedor = *ini_array;
		ini_array++;
		nelem--;
	}
	
	return contenedor;
}
template<class T>
T Deque<T>::pop_back()
{
	int contenedor = 0;

	if (ini_array == nullptr && fin_array == nullptr)
	{
		return -1;
	}
	else if (ini_array == fin_array)
	{
		contenedor = *fin_array;
		ini_array = nullptr;
		fin_array = nullptr;
		delete[] * fin;

	}
	else if (fin_array == *fin)
	{
		contenedor = *fin_array;
		delete[] * fin;
		fin--;
		fin_array = *fin + tam_array - 1;
		nelem--;

	}
	else
	{
		contenedor = *fin_array;
		fin_array--;
		nelem--;
	}

	return contenedor;
}


template<class T>
void Deque<T>::print()
{
	if (ini_array == nullptr && fin_array == nullptr)
	{
		cout << "vacio" << endl;
		return;
	}
	T** tmp_ini = ini;
	T* tmp_ini_array = ini_array;
	while (tmp_ini<=fin)
	{
		cout << "[";
		while (tmp_ini_array <= *tmp_ini +(tam_array-1))
		{
			cout << *tmp_ini_array << " ";
			if (tmp_ini_array == fin_array)
			{
				break;
			}
			tmp_ini_array++;
		}
		cout << "]";
		tmp_ini++;
		tmp_ini_array = *tmp_ini;

	}

}

template<class T>
T & Deque<T>::operator[](T x)
{
	if (x+1>nelem)
	{
		cout << "No ps hdp";
		return *ini_array;
	}
	else
	{
		T elem_faltan = (ini_array - *ini);
		T n_id = x + elem_faltan;
		T agre = n_id % 5;
		T ubi = n_id / 5;

		return *(*(ini + ubi) + agre);
	}
}

template<class T>
Deque<T>::~Deque()
{
	for (T** p = ini; p <= fin; ++p) {
		if (*p != nullptr) {
			delete[] * p;
			*p = nullptr;
		}
	}
}




int main() {
	Deque<int> dq(5,5);
	dq.push_front(5);
	dq.push_front(3);
	dq.push_front(4);
	dq.push_front(4);
	dq.push_front(6);
	dq.push_front(7);
	dq.push_front(8);
	dq.push_front(9);
	dq[5] = 8;
	dq.pop_back();
	cout<<dq.get_nelem() << endl;
	int valor = dq[6];
	cout << valor << endl;
	dq.print();
}
