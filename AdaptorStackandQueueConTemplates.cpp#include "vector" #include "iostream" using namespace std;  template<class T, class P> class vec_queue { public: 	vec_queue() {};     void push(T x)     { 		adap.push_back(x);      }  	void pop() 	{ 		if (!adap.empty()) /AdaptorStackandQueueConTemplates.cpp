#include "vector"
#include "iostream"
using namespace std;

template<class T, class P>
class vec_queue
{
public:
	vec_queue() {};
    void push(T x)
    {
		adap.push_back(x); 
    }

	void pop()
	{
		if (!adap.empty()) // verifica q no este vacia la cola
		{
			adap.erase(adap.begin()); // eliminar el primer elemento
		}

	}

	void print()
	{
		for (int element: adap)
		{
			cout << element << " ";
		}
	}


private:
	P adap;
};


template<class T, class P>
class vec_stack
{
public:
	vec_stack<T,P>() {};
	void push(T x);
	void pop();
	void print();
private:
	P vect;
};



template<class T, class P>
void vec_stack<T,P>::push(T x)
{
	vect.push_back(x);
}
template<class T, class P>
void vec_stack<T, P>::pop()
{
	vect.pop_back();
}

template<class T, class P>
void vec_stack<T,P>::print()
{
	for (int elemento: vect)
	{
		cout<<elemento << " ";
	}
}



int main() {
	vec_queue<int ,vector<int>> v_S;
	v_S.push(5);
	v_S.push(4);
	v_S.push(3);
	v_S.push(2);
	v_S.push(1);
	v_S.push(0);
	v_S.pop();
	v_S.print();
}
