#include "Trie.hpp"

// Complejidad O(1)
Trie::Trie(Node* _root) {
    root = _root;
}

// Complejidad O(n)
void Trie::Add(string w) {
    //Nivel actual
    Node* currentNode = root; 
    //Si el nivel existe, si no, crearlo y revisar que esté activo el nodo que quiero

    //Por cada char del string dado
    for(int c = 0; c < w.size(); c ++) {
        //Caracter actual
        int chr = w[c] - 'a'; 

        //Si no existe el nivel, lo creamos y activamos el nodo del char correspondiente 
        if(currentNode->children[chr] == nullptr) {
            currentNode->children[chr] = new Node();
            currentNode->SetActive(chr);
        }
        //Si existe el nivel, solo activamos el char
        else if(!currentNode->IsActive(chr)) {
            currentNode->SetActive(chr);
        }
        //Pasamos al siguiente nodo
        currentNode = currentNode->children[chr];
    }
}

// Complejidad O(n)
void Trie::Search(string w) {
    // Nivel actual (root)
    Node* currentNode = root;
    
    string exists = "false";
    // Se recorre todos los chars del string 
    for (int c = 0; c < w.size(); c ++) {
        //Si el nodo es nulo ya no tiene caso seguir buscando porque no está
        if (currentNode == nullptr) {
            break;
        }
        // Caracter actual
        int chr = w[c] - 'a'; 
        
        if (currentNode->IsActive(chr) == true) {
            exists = "true";
        } else {
            exists = "false";
        }
        currentNode = currentNode->children[chr];
    }
    cout << exists << "\n";
}

// Complejidad O(n)
void Trie::Print() {
    root->Print(); // Complejidad O(n)
}