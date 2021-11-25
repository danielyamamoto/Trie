#include "Node.hpp"

// Complejidad O(n)
// Para inicializar los nodos con valores de no encendido
Node::Node() {
    isActive = -1;
    for (int i = 0; i < 26; i ++) {
        children[i] = nullptr;
    }
}

// Complejidad O(n)
// Para activar un nodo
void Node::SetActive() {
    isActive = 1;
    if (children[0] == nullptr) {
        for (int i = 0; i < 26; i ++) {
            children[i] = new Node();
        }
    }
}

// Complejidad O(n)
// Cuantos árboles tengo activos
int Node::GetNumActive() {
    int numActive = 0;
    for (int i = 0; i < 26; i ++) {
        if (children[i] != nullptr) {
            if (children[i]->isActive == 1) {
                numActive++;
            }
        }
    }
    return numActive;
}

// Complejidad O(1)
// Regresa si el nodo está activo 
bool Node::IsActive(int child) {
    if (children[child] != nullptr) { 
        return children[child]->isActive == 1; 
    } else { 
        return false; 
    }
}

// Complejidad O(1)
// Activa un nodo
void Node::SetActive(int child) {
    if (children[child] != nullptr) {
        children[child]->isActive = 1;
    }
}

// Complejidad O(n)
// Imprime el siguiente Nodo
void Node::Print() {
    for(int i = 0; i < 26; i ++) {
        if(children[i] != nullptr) {
            if(children[i]->isActive == 1) {
                int n = (i + 'a');
                string s = "";
                s += n;
                cout << s << "|";
                children[i]->Print();
            }
        }
    }
}