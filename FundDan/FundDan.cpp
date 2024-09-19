#include <iostream>

struct Node {
    int x;
    Node *Next;
};

class List {
    Node* Head, * Tail;
public:
    List() :Head(NULL), Tail(NULL) {};
    void Add(int x);
};
void List::Add(int x) {

}



int main()
{
    std::cout << "Hello World!\n";
}

