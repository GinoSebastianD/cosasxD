#include "iostream"

struct Node
{
	Node* arr[2];
	int v;
	Node(int x) {
		arr[0] = 0;
		arr[1] = 0;
		v = x;
	}
};

class MyClass
{
public:
	Node* root = nullptr;
	MyClass();
	
	bool find(int x, Node**& pos);
	bool insert(int x);
	void del(int x);
	void memoria(Node* tmp);
	void print(Node* tmp);
	~MyClass();

private:

};

MyClass::MyClass()
{
}

bool MyClass::find(int x, Node**& pos)
{
	for (pos = &root; *pos != nullptr && (*pos)->v != x; pos = &(*pos)->arr[x > (*pos)->v]);
	return *pos != nullptr;
}

bool MyClass::insert(int x)
{
	Node** pos;
	if (find(x,pos))
	{
		return false;
	}
	*pos = new Node(x);

}

void MyClass::del(int x)
{
	Node** tmp_2 = &root;
	if (!find(x,tmp_2))
	{
		return;
	}
	if ( (*tmp_2)->arr[1] != nullptr && (*tmp_2)->arr[0])
	{
		Node** tmp_3 = &(*tmp_2)->arr[1];
		while ( (*tmp_3)->arr[0])
		{
			tmp_3 = &(*tmp_3)->arr[0];
		}
		(*tmp_2)->v = (*tmp_3)->v;
		tmp_3 = tmp_2;
	}
	Node* tmp_4 = *tmp_2;
	*tmp_2 = (*tmp_2)->arr[(*tmp_2)->arr[0] == 0];
	delete tmp_4;

}

void MyClass::memoria(Node* tmp)
{
	if (!tmp)
	{
		return;
	}

	memoria(tmp->arr[0]);
	memoria(tmp->arr[1]);
	delete tmp;
}




void MyClass::print(Node* tmp)
{
	if (tmp->arr ==nullptr)
	{
		return;
	}
	if (tmp->arr[1] !=nullptr)
	{
		print(tmp->arr[1]);
	}
	std::cout << tmp->v << " ";
	
	print(tmp->arr[0]);

}

MyClass::~MyClass()
{
	memoria(root);
}

int main() {
	MyClass arbol;
	arbol.insert(8);
	arbol.insert(12);
	arbol.insert(9);
	arbol.insert(7);
	arbol.insert(6);


	arbol.del(12);
	
	arbol.print(arbol.root);
}

