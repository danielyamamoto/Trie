#include <string>
#include <iostream>

using namespace std;

class Node {
public:
    int isActive;
    Node* children[26];

    Node();
    void SetActive();
    int GetNumActive();
    bool IsActive(int child);
    void SetActive(int child);
    void Print();
};