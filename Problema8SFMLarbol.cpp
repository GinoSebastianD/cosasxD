#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// ======================================================
// ESTRUCTURA DE NODO
// ======================================================
struct Node {
    Node* izq;
    Node* der;
    int x;
    Node(int v = 0) {
        izq = der = nullptr;
        x = v;
    }
};

// ======================================================
// CLASE COLA CIRCULAR + CONSTRUCCIÓN DE ÁRBOL
// ======================================================
template<class T, int N>
class Cola {
public:
    T arr[N];
    T* head;
    T* tail;

    Cola() {
        head = nullptr;
        tail = nullptr;
    }

    bool pop(T& x);
    bool push(T x);
    bool lleno();
    bool vacio();
    void print();
    Node* construir();
    void inorden(Node* n);
};

template<class T, int N>
bool Cola<T, N>::vacio() {
    return (head == nullptr && tail == nullptr);
}

template<class T, int N>
bool Cola<T, N>::lleno() {
    if (!head) return false;
    if (tail + 1 == head) return true;
    if (tail == arr + (N - 1) && head == arr) return true;
    return false;
}

template<class T, int N>
bool Cola<T, N>::push(T x) {
    if (lleno()) return false;
    if (!head) {
        head = tail = arr;
    }
    else if (tail == arr + (N - 1)) {
        tail = arr;
    }
    else tail++;
    *tail = x;
    return true;
}

template<class T, int N>
bool Cola<T, N>::pop(T& x) {
    if (vacio()) return false;
    x = *head;
    if (head == tail) {
        head = tail = nullptr;
    }
    else if (head == arr + (N - 1)) {
        head = arr;
    }
    else head++;
    return true;
}

template<class T, int N>
void Cola<T, N>::print() {
    if (vacio()) {
        cout << "Cola vacía" << endl;
        return;
    }
    T* p = head;
    cout << "Cola: ";
    while (true) {
        cout << (*p)->x << " ";
        if (p == tail) break;
        if (p == arr + (N - 1)) p = arr;
        else p++;
    }
    cout << endl;
}

// ======================================================
// CONSTRUCCIÓN DE ÁRBOL DENTRO DE COLA
// ======================================================
template<class T, int N>
Node* Cola<T, N>::construir() {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        Node* nuevo = new Node(rand() % 10);
        this->push(nuevo);
    }

    Node* raiz = nullptr;
    while (!this->vacio()) {
        Node* i, * d;
        if (!this->pop(i)) break;
        if (!this->pop(d)) { raiz = i; break; }

        Node* padre = new Node(i->x + d->x);
        padre->izq = i;
        padre->der = d;

        if (!this->vacio())
            this->push(padre);

        raiz = padre;
    }
    return raiz;
}

template<class T, int N>
void Cola<T, N>::inorden(Node* n) {
    if (!n) return;
    inorden(n->izq);
    cout << n->x << " ";
    inorden(n->der);
}

class TreeVisualizer {
private:
    sf::RenderWindow window;
    sf::Font font;

    void drawNode(Node* node, float x, float y, float offsetX, int level) {
        if (!node) return;

        float childY = y + 80;
        sf::Color color(100 + (node->x * 10) % 155, 180, 200);

        // 🔹 Líneas negras
        if (node->izq) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::Black),
                sf::Vertex(sf::Vector2f(x - offsetX, childY), sf::Color::Black)
            };
            window.draw(line, 2, sf::Lines);
            drawNode(node->izq, x - offsetX, childY, offsetX / 1.8, level + 1);
        }

        if (node->der) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::Black),
                sf::Vertex(sf::Vector2f(x + offsetX, childY), sf::Color::Black)
            };
            window.draw(line, 2, sf::Lines);
            drawNode(node->der, x + offsetX, childY, offsetX / 1.8, level + 1);
        }

        // 🔹 Nodo circular
        sf::CircleShape circle(20);
        circle.setFillColor(color);
        circle.setOutlineColor(sf::Color::Black);
        circle.setOutlineThickness(2);
        circle.setPosition(x - 20, y - 20);
        window.draw(circle);

        // 🔹 Texto del valor
        sf::Text text;
        text.setFont(font);
        text.setString(to_string(node->x));
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x - 8, y - 12);
        window.draw(text);
    }

public:
    TreeVisualizer() : window(sf::VideoMode(800, 600), "Árbol con SFML") {
        font.loadFromFile("arial.ttf"); // asegúrate de tener arial.ttf
    }

    void render(Node* root) {
        while (window.isOpen()) {
            sf::Event e;
            while (window.pollEvent(e)) {
                if (e.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color(230, 240, 250));
            if (root) drawNode(root, 400, 80, 200, 0);
            window.display();
        }
    }
};

// ======================================================
// MAIN
// ======================================================
int main() {
    Cola<Node*, 8> c;
    Node* raiz = c.construir();

    cout << "Recorrido inorden: ";
    c.inorden(raiz);
    cout << endl;

    TreeVisualizer visual;
    visual.render(raiz);

    return 0;
}
