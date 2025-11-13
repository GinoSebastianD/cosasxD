#include<iostream>
#include<deque>
#include <SFML/Graphics.hpp>

struct node
{
	node* nodes[2];
	node* padre;
	int val;
	std::string Color;
	node(int x, std::string col) {
		nodes[0] = nodes[1] = nullptr;
		val = x;
		Color = col;
	}

};

class RedBlackTree
{
public:
	node* m_root = nullptr;
	void insert(int x);
	bool find(node**&pos, int x, std::deque<node*>& deq);
	void balanceo(std::deque<node*>& deq);
	void rotacion_izq(node**& pos);
	void rotacion_der(node**&pos);

private:

};

void RedBlackTree::insert(int x)
{

	if (!m_root)
	{
		m_root = new node(x,"Black");
		return;
	}


	node** pos;
	std::deque<node*> deq;
	if (find(pos, x, deq))
	{
		return;
	}
	*pos = new node(x,"Red");
	deq.push_back(*pos);
	balanceo(deq);
	return;
}

bool RedBlackTree::find(node**& pos, int x, std::deque<node*>& deq)
{
	pos = &m_root;
	for (;*pos && (*pos)->val != x ; pos = &(*pos)->nodes[(*pos)->val < x])
	{
		deq.push_back(*pos);
	}
	return *pos && (*pos)->val == x;
}

void RedBlackTree::balanceo(std::deque<node*>& deq)
{
	while (deq.size() >=3 )
	{
		node* abuelo = deq[deq.size() - 3];
		node* padre = deq[deq.size() - 2];
		node* hijo = deq.back();

		if (padre->Color == "Black") {
			break;
		}
		node* tio = (abuelo->nodes[0] == padre) ? abuelo->nodes[1] : abuelo->nodes[0];

		if (tio && tio->Color == "Red")
		{
			tio->Color = "Black";
			padre->Color = "Black";
			abuelo->Color = "Red";
			deq.pop_back();
		}

		else
		{
			node** cas;
			if (deq.size() == 3)
			{
				cas = &m_root;
			}
			else
			{
				node* bisabuelo = deq[deq.size() - 4];
				cas = (bisabuelo->nodes[0] == abuelo) ? &bisabuelo->nodes[0] : &bisabuelo->nodes[1];
			}

			if (abuelo->nodes[0] == padre)
			{
				if (padre->nodes[1] == hijo)
				{
					node** tmp = &abuelo->nodes[0];
					rotacion_izq(tmp);
					padre = *tmp;
				}
				rotacion_der(cas);
				(*cas)->Color = "Black";
				(*cas)->nodes[1]->Color = "Red";
			}
			else
			{
				if (padre->nodes[0] == hijo)
				{
					node** tmp = &abuelo->nodes[1];
					rotacion_der(tmp);
					padre = *tmp;
				}
				rotacion_izq(cas);
				(*cas)->Color = "Black";
				(*cas)->nodes[0]->Color = "Red";
				
			}
			break;
		}
		


	}
	m_root->Color = "Black";
}

void RedBlackTree::rotacion_izq(node**& pos)
{
	node* x = *pos;
	node* y = x->nodes[1];
	x->nodes[1] = y->nodes[0];
	y->nodes[0] = x;
	*pos = y;
}

void RedBlackTree::rotacion_der(node**& pos)
{
	node* x = *pos;
	node* y = x->nodes[0];
	x->nodes[0] = y->nodes[1];
	y->nodes[1] = x;
	*pos = y;
}

//int main() {
//	RedBlackTree root;
//	root.insert(8);
//	root.insert(13);
//	root.insert(7);
//	root.insert(15);
//	root.insert(12);
//	root.insert(1);
//	root.insert(16);
//}

class Visualizador {
public:
	sf::RenderWindow window;
	sf::Font font;
	Visualizador() : window(sf::VideoMode(900, 700), "Arbol Rojo-Negro") {
		if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
			std::cerr << "Error cargando fuente (Arial.ttf)\n";
		}
	}

	void dibujarNodo(sf::RenderWindow& w, node* n, float x, float y, float dx) {
		if (!n) return;

		// Dibujar líneas a hijos
		if (n->nodes[0]) {
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(x, y)),
				sf::Vertex(sf::Vector2f(x - dx, y + 80))
			};
			w.draw(line, 2, sf::Lines);
			dibujarNodo(w, n->nodes[0], x - dx, y + 80, dx / 1.7f);
		}
		if (n->nodes[1]) {
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(x, y)),
				sf::Vertex(sf::Vector2f(x + dx, y + 80))
			};
			w.draw(line, 2, sf::Lines);
			dibujarNodo(w, n->nodes[1], x + dx, y + 80, dx / 1.7f);
		}

		// Nodo
		sf::CircleShape circle(20);
		circle.setFillColor(n->Color == "Red" ? sf::Color::Red : sf::Color::Black);
		circle.setOutlineColor(sf::Color::White);
		circle.setOutlineThickness(2);
		circle.setPosition(x - 20, y - 20);

		sf::Text text;
		text.setFont(font);
		text.setString(std::to_string(n->val));
		text.setCharacterSize(16);
		text.setFillColor(sf::Color::White);
		text.setPosition(x - 10, y - 12);

		w.draw(circle);
		w.draw(text);
	}

	void dibujar(RedBlackTree& tree) {
		window.clear(sf::Color(30, 30, 30));
		dibujarNodo(window, tree.m_root, 450, 80, 180);
		window.display();
	}
};

//////////////////////////////////
// MAIN
//////////////////////////////////

int main() {
	RedBlackTree tree;
	Visualizador vis;

	std::cout << "Presiona la tecla 'A' para insertar un numero.\n";
	std::cout << "Presiona 'ESC' para salir.\n";

	while (vis.window.isOpen()) {
		sf::Event e;
		while (vis.window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				vis.window.close();
				
			if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Escape)
					vis.window.close();

				if (e.key.code == sf::Keyboard::A) {
					int x;
					std::cout << "Ingrese numero: ";
					std::cin >> x;
					tree.insert(x);
				}
			}
		}

		vis.dibujar(tree);
	}

	return 0;
}
