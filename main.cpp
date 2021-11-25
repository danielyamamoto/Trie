/*
El programa recibe palabras, las guarda en un trie y después se buscan palabras dentro de la estructura.

Autores:
Yusdivia Molina
Daniel Yamamoto
Héctor Noyola

Fecha de modificación: 23/09/2021
*/

#include <iostream>
#include <string>
#include <vector>
#include "Trie.hpp"

using namespace std;

int main() {
    // Creamos trie y le añadimos el nodo inicial
    Node* root = new Node();
    Trie* trie = new Trie(root);

    // Pedimos el número de palabras
    int n = 0;
    cout << "Word's size: ";
    cin >> n;
  
    // Pedimos las palabras a guardar en el trie 
    for (int i = 0; i < n; i++) {
        string word;
        //cout << "Word " << i+1 << ": ";
        cin >> word;
        trie->Add(word);
    }

    // Pedimos el número de palabras
    int m = 0;
    cout << "Search's size: ";
    cin >> m;
  
    vector<string> res;
    // Pedimos las palabras a guardar en el trie 
    for (int i = 0; i < m; i++) {
        string word;
        //cout << "Word " << i+1 << ": ";
        cin >> word;
        res.push_back(word);
    }

    // Salida 1: Imprimimos el trie
    cout << "\n---First---\n";
    trie->Print();
    cout << "\n";

    // Salida 2: M booleanos correspondientes al resultado
    cout << "\n---Second---\n";
    for (int i = 0; i < m; i++) {
        cout << res[i] << " ";
        trie->Search(res[i]);
    }

    return 0;
}