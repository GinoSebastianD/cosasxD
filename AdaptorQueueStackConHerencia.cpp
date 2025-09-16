#include "vector"
#include "iostream"
using namespace std;

template<class T, class P = vector<int>>
class vec_queue:public P
{
public:
	vec_queue() {};
    void push(T x)
    {
		this->push_back(x); 
    }

	void pop()
	{
		if (!this->empty()) // verifica q no este vacia la cola
		{
			this->erase(this->begin()); // eliminar el primer elemento
		
		}

	}

	void print()
	{
		for (int element: *this)
		{
			cout << element << " ";
		}
	}


private:
};


template<class T, class P2 = vector<int>>
class vec_stack:public P2
{
public:
	vec_stack<T,P2>() {};
	void push(T x);
	void pop();
	void print();
private:
};

template<class T, class P2>
void vec_stack<T,P2>::push(T x)
{
	this->push_back(x);
}
template<class T, class P2>
void vec_stack<T, P2>::pop()
{
	this->pop_back();
}

template<class T, class P2>
void vec_stack<T,P2>::print()
{
	for (int elemento: *this)
	{
		cout<<elemento << " ";
	}
}



int main() {
	vec_stack<int> v_S;
	v_S.push(5);
	v_S.push(4);
	v_S.push(3);
	v_S.push(2);
	v_S.push(1);
	v_S.push(0);
	v_S.pop();
	v_S.print();
}
