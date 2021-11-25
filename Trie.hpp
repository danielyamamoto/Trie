#include <iostream>
#include <string>
#include "Node.hpp"

using namespace std;

class Trie {
public:
    Node* root;

    Trie(Node* _root);
    void Add(string w);
    void Search(string w);
    void Print();
};