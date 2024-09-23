#include <iostream>
#include <vector>

struct Node {
    int x;
    Node *Next;
};

class List {
    Node* Head, * Tail;

public:

    List() :Head(NULL), Tail(NULL) {};
    ~List();//2


    
    //void MakeList();//1
    void AddElement(int x);//3
    void DeleteThis(int x);//4
    void DeleteAfter(int x); //5
    void SearchThis(int x); //6
    void PrintList(); //7
    //-------------- 8
};
std::vector<List> moreLists;

List::~List(){
    /*while(Head) {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }*/
}



void List::AddElement(int Xpast) {
    Node* newNode = new Node();
    newNode->x = Xpast;

    if (Head == nullptr) {
        Head = newNode;
        Tail = newNode;
        newNode->Next = Head; 
    }
    else {
        
        Tail->Next = newNode;   
        newNode->Next = Head;   
        Tail = newNode;         
    }
}

void List::PrintList() {
    if (Head == nullptr) return;

    Node* temp = Head;
    do {
        std::cout << temp->x << " ";
        temp = temp->Next;
    } while (temp != Head);
    std::cout << std::endl;
}

void MakeList() {
    moreLists.push_back(List());
}


int main()
{
    MakeList();
    moreLists[0].AddElement(45);
    moreLists[0].AddElement(775);
    moreLists[0].AddElement(896);
    moreLists[0].PrintList();
    MakeList();
    moreLists[1].AddElement(8855);
    moreLists[1].AddElement(5);
    moreLists[1].AddElement(6);
    moreLists[1].PrintList();
    
}

