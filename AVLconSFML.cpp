#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    node* nodes[2];
    int val;
    int altura;
    node(int x) {
        val = x;
        nodes[0] = nodes[1] = nullptr;
        altura = 1;
    }
};

class AVL
{
public:
    node* root = nullptr;
    void insert(int x);
    bool find(int x, std::vector<node*>& vec, node**& pos);
    void balanceo(std::vector<node*>& vec);

    int altura(node* root);
    int diferencia(node* root);

    node* rotacion_der(node* y);
    node* rotacion_iz(node* x);

    void in_orden(node* root);
    void print();

    // nueva función de borrado
    void remove(int x);

private:

};

void AVL::insert(int x)
{
    node** pos = nullptr;
    std::vector<node*> vec;
    if (find(x, vec, pos))
    {
        return;
    }
    *pos = new node(x);
    vec.push_back(*pos);
    balanceo(vec);
    return;
}

bool AVL::find(int x, std::vector<node*>& vec, node**& pos)
{
    for (pos = &root; *pos && (*pos)->val != x; pos = &(*pos)->nodes[(*pos)->val < x])
    {
        if (*pos)
        {
            vec.push_back(*pos);
        }
    }
    return *pos && (*pos)->val == x;
}

void AVL::balanceo(std::vector<node*>& vec)
{
    for (int i = (int)vec.size() - 1; i >= 0; i--)
    {
        node* act = vec[i];
        act->altura = altura(act);
        int balanceo = diferencia(act);
        if (balanceo < -1)
        {
            if (diferencia(act->nodes[0]) <= 0)
            {
                node* n_root = rotacion_der(act);
                if (i == 0)
                {
                    root = n_root;
                }
                else
                {
                    node* padre = vec[i - 1];
                    if (padre->nodes[0] == act)
                    {
                        padre->nodes[0] = n_root;
                    }
                    else
                    {
                        padre->nodes[1] = n_root;
                    }
                }
            }
            else
            {
                node* temp = rotacion_iz(act->nodes[0]);
                act->nodes[0] = temp;
                node* n_root = rotacion_der(act);
                if (i == 0)
                {
                    root = n_root;
                }
                else
                {
                    node* padre = vec[i - 1];
                    if (padre->nodes[0] == act)
                    {
                        padre->nodes[0] = n_root;
                    }
                    else
                    {
                        padre->nodes[1] = n_root;
                    }
                }

            }
        }
        else if (balanceo > 1)
        {
            if (diferencia(act->nodes[1]) >= 0)
            {
                node* n_root = rotacion_iz(act);
                if (i == 0)
                {
                    root = n_root;
                }
                else
                {
                    node* padre = vec[i - 1];
                    if (padre->nodes[0] == act)
                    {
                        padre->nodes[0] = n_root;
                    }
                    else
                    {
                        padre->nodes[1] = n_root;
                    }
                }
            }
            else
            {
                node* temp = rotacion_der(act->nodes[1]);
                act->nodes[1] = temp;
                node* n_root = rotacion_iz(act);
                if (i == 0)
                {
                    root = n_root;
                }
                else
                {
                    node* padre = vec[i - 1];
                    if (padre->nodes[0] == act)
                    {
                        padre->nodes[0] = n_root;
                    }
                    else
                    {
                        padre->nodes[1] = n_root;
                    }
                }
            }

        }

    }
}

int AVL::altura(node* root)
{
    int izq = 0;
    int der = 0;
    if (!root)
    {
        return 0;
    }
    if (root->nodes[0])
    {
        izq = root->nodes[0]->altura;
    }
    if (root->nodes[1])
    {
        der = root->nodes[1]->altura;
    }
    return 1 + max(izq, der);
}

int AVL::diferencia(node* root)
{
    if (!root) return 0;
    int izq = 0;
    int der = 0;
    if (root->nodes[0])
    {
        izq = root->nodes[0]->altura;
    }
    if (root->nodes[1])
    {
        der = root->nodes[1]->altura;
    }
    return der - izq;
}

node* AVL::rotacion_der(node* y)
{
    node* x = y->nodes[0];
    node* tmp = x->nodes[1];

    x->nodes[1] = y;
    y->nodes[0] = tmp;

    y->altura = altura(y);
    x->altura = altura(x);

    return x;
}

node* AVL::rotacion_iz(node* x)
{
    node* y = x->nodes[1];
    node* tmp = y->nodes[0];

    y->nodes[0] = x;
    x->nodes[1] = tmp;


    x->altura = altura(x);
    y->altura = altura(y);

    return y;
}

void AVL::in_orden(node* root)
{
    if (!root)
    {
        return;
    }
    in_orden(root->nodes[0]);
    cout << root->val << " ";
    in_orden(root->nodes[1]);
}

void AVL::print()
{
    in_orden(root);
    cout << endl;
}

// IMPLEMENTACIÓN DE remove (borrado BST + rebalanceo usando balanceo)
void AVL::remove(int x) {
    // buscar el nodo a borrar, guardando ruta
    node** pos = nullptr;
    vector<node*> ruta;
    if (!find(x, ruta, pos)) {
        cout << "El valor " << x << " no existe en el árbol." << endl;
        return;
    }

    // pos es puntero a puntero del nodo a borrar
    node** targetPtr = pos;
    node* target = *targetPtr;

    // si tiene dos hijos, buscar sucesor (mínimo en subárbol derecho)
    if (target->nodes[0] && target->nodes[1]) {
        node** succPtr = &target->nodes[1];
        // opcional: no agregamos al vector ruta los nodos del sucesor ahora; recompondremos ruta luego
        while ((*succPtr)->nodes[0]) {
            succPtr = &(*succPtr)->nodes[0];
        }
        // copiar valor del sucesor al target y cambiar targetPtr al sucesor para eliminarlo
        (*targetPtr)->val = (*succPtr)->val;
        targetPtr = succPtr;
        target = *targetPtr;
    }

    // target tiene 0 o 1 hijo
    node* hijo = target->nodes[0] ? target->nodes[0] : target->nodes[1];
    *targetPtr = hijo;
    delete target;

    // reconstruir ruta desde root hacia la posición de la eliminación (pos de inserción del valor x)
    vector<node*> nuevaRuta;
    node** p = &root;
    while (*p) {
        nuevaRuta.push_back(*p);
        if (x < (*p)->val) p = &(*p)->nodes[0];
        else if (x > (*p)->val) p = &(*p)->nodes[1];
        else {
            // si encontramos el valor (puede suceder si hubo copia de sucesor),
            // avanzamos un paso (hacia donde estaría) y salimos
            p = &(*p)->nodes[1]; // avanzar arbitrariamente para terminar la ruta
        }
    }

    // balancear por la ruta reconstruida (si está vacía, no hace nada)
    if (!nuevaRuta.empty())
        balanceo(nuevaRuta);
}

///////////////////////
// SFML Drawing Code //
///////////////////////

template <class T>
void drawTree(sf::RenderWindow& window, T* nodePtr, float x, float y, float xOffset, float level, const sf::Font& font) {
    if (!nodePtr) return;

    sf::CircleShape circle(20.f);
    circle.setFillColor(sf::Color::Black);
    circle.setPosition(x, y);

    window.draw(circle);

    // text dentro del círculo
    sf::Text text(std::to_string(nodePtr->val), font, 18);
    // centralizar aproximado
    sf::FloatRect tb = text.getLocalBounds();
    text.setPosition(x + 20 - tb.width / 2.0f - 4, y + 20 - tb.height / 2.0f - 6);
    text.setFillColor(sf::Color::White);
    window.draw(text);

    if (nodePtr->nodes[0]) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20), sf::Color::Black),
            sf::Vertex(sf::Vector2f(x - xOffset + 20, y + 80), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);
        drawTree(window, nodePtr->nodes[0], x - xOffset, y + 80, xOffset / 2.0f, level + 1, font);
    }

    if (nodePtr->nodes[1]) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20), sf::Color::Black),
            sf::Vertex(sf::Vector2f(x + xOffset + 20, y + 80), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);
        drawTree(window, nodePtr->nodes[1], x + xOffset, y + 80, xOffset / 2.0f, level + 1, font);
    }
}

int main() {
    AVL arbol;

    // Fuente: pon aquí la ruta correcta a una fuente .ttf en tu sistema
    sf::Font font;
    if (!font.loadFromFile("C:/Users/ginod/OneDrive/Documentos/AED/AVLSFML/Arial.ttf")) {
        std::cerr << "Failed to load font. Cambia la ruta a tu .ttf" << std::endl;
        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(1280, 720), "AVL Tree (SFML)");

    // opcional: poblar con algunos valores iniciales (como en tu ejemplo)
    // for (int i = 1; i <= 10; ++i) arbol.insert(i);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    int value;
                    std::cout << "Enter value to add: ";
                    if (!(std::cin >> value)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Entrada invalida\n";
                    }
                    else {
                        arbol.insert(value);
                    }
                }
                else if (event.key.code == sf::Keyboard::R) {
                    int value;
                    std::cout << "Enter value to remove: ";
                    if (!(std::cin >> value)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Entrada invalida\n";
                    }
                    else {
                        arbol.remove(value);
                    }
                }
                else if (event.key.code == sf::Keyboard::P) {
                    // imprimir en orden en consola
                    arbol.print();
                }
            }
        }

        window.clear(sf::Color::White);

        if (arbol.root) {
            drawTree(window, arbol.root, 640.0f, 50.0f, 300.0f, 1.0f, font);
        }

        window.display();
    }

    return 0;
}
