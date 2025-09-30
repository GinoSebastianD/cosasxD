#include "iostream"
#include "stack"
using namespace std;

//hay dos maneras , creando un stuct o usando una funcion especial de std::stack creo 


struct Node
{
	Node* der;
	Node* izq;
	int v;
	Node(int x) {
		der = nullptr;
		izq = nullptr;
		v = x;
	}
};
struct tabla
{
	Node* p;
	int s;

};


class RecorridoArbol
{
public:
	Node* root;

	RecorridoArbol();
	bool find(int x, Node**& pos);
	bool insert(int x);
	bool del(int x);
	void in_orden(Node* r);
	
	void liberar_memoria(Node* r);
	void in_orden_sin_recursividad(Node* r);

	~RecorridoArbol();

private:

};

RecorridoArbol::RecorridoArbol()
{
	root = nullptr;
}

bool RecorridoArbol::find(int x, Node**& pos)
{
	pos = &root;
	while (*pos && (*pos)->v != x)
	{
		if ((*pos)->v < x)
		{
			pos = &(*pos)->der;
		}
		else
		{
			pos = &(*pos)->izq;
		}
	}
	return *pos != nullptr;

}

bool RecorridoArbol::insert(int x)
{
	Node** pos;
	if (find(x, pos))
	{
		return false;
	}
	*pos = new Node(x);
	return true;
}

bool RecorridoArbol::del(int x)
{
	return false;
}

void RecorridoArbol::in_orden(Node* r)
{
	if (!r)
	{
		return;
	}
	in_orden(r->izq);
	cout << r->v << " ";
	in_orden(r->der);
}


void RecorridoArbol::liberar_memoria(Node* r)
{
	if (!r)
	{
		return;
	}
	liberar_memoria(r->izq);
	liberar_memoria(r->der);
	delete r;
}

void RecorridoArbol::in_orden_sin_recursividad(Node* r)
{
	std::stack<tabla> st;
	st.push({ r,0 });
	while (!st.empty())
	{
		tabla& tope = st.top(); // creo mi variable de tipo tope y le asigno el elemento q esta en la cima de la pila.
		switch (tope.s)
		{
			case 0:
				tope.s = 1;
				if (tope.p->izq) //diferente de null
				{	
					st.push({tope.p->izq,0});					//empilamos	
				}
				break;
			case 1:
				cout << tope.p->v<< " ";
				tope.s = 2;
				break;

			case 2:
				tope.s = 3;
				if (tope.p->der) //diferente de null
				{
					st.push({ tope.p->der,0});					//empilamos	
				}
				break;
			case 3:
				st.pop();
				break;

		default:
			break;
		}
	}

}

RecorridoArbol::~RecorridoArbol()
{
	liberar_memoria(root);
}

int main() {
	RecorridoArbol arb;

	arb.insert(15);
	arb.insert(25);
	arb.insert(12);
	arb.insert(7);
	arb.insert(13);
	arb.insert(18);
	arb.insert(30);


	arb.in_orden_sin_recursividad(arb.root);
	cout << endl;
	arb.in_orden(arb.root);


	return 0;
}
