#include "vector"
#include "iostream"
using namespace std;



template<class T>
class vec_stack
{
public:
	vec_stack<T>() {};
	void push(T x);
	void pop();
	void print();
private:
	vector<int> vect;
};



template<class T>
void vec_stack<T>::push(T x)
{
	vect.push_back(x);
}
template<class T>
void vec_stack<T>::pop()
{
	vect.pop_back();
}

template<class T>
void vec_stack<T>::print()
{
	for (int elemento: vect)
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
	v_S.print();
}
