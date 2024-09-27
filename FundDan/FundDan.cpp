
#include <iostream>
#include <vector>



class List {
    struct Node {
        int x;
        Node* Next;
    };
    Node* Head, * Tail, *Current;
    
public:
    int lenght = 0;
    List() :Head(NULL), Tail(NULL), Current(NULL) {};
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

List::~List() {
    /*while(Head) {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }*/
    //free(Current);
}


void List::DeleteThis(int xDelete) {
    if (Head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    } 

    Current = Head;
    Node* previous = nullptr;

    for (int count = lenght; count > 0; count--) {
        Node* next = Current->Next; 
        if (Current->x == xDelete) {
            if (Current == Head) {
                if (lenght == 1) {
                    // Если это последний элемент в списке
                    delete Current;
                    Head = nullptr;
                    Tail = nullptr;
                    lenght--;
                    return;
                }
                else {
                    // Удаление головы, но список не пуст
                    Head = Current->Next;
                    Tail->Next = Head;
                }
            }
            else {
                // Удаление не головы
                previous->Next = Current->Next;
                if (Current == Tail) {
                    // Если это последний элемент
                    Tail = previous;
                    Tail->Next = Head;
                }
            }

            delete Current;
            Current = nullptr;
            lenght--;
        }
        else {
            previous = Current;
        }

        Current = next;
       
    }
}
void List::DeleteAfter(int xAfter) {
    Current = Head;
    for (int i = 0; i < lenght; i++) {
        
       
        if (Current->x == xAfter) {

            Node* tmp = Current->Next;
            Current->Next = Current->Next->Next;

            if (tmp == Head) Head = tmp->Next;
            delete tmp;
            lenght--;
        }
        Current = Current->Next;

    }
    
}

void List::SearchThis(int xSearch) {
    if (Head == nullptr) {
        std::cout << "List empty!" << std::endl;
    }
    Current = Head;
    for (int i = 0; i < lenght; i++) {
        if (Current->x == xSearch) {
            std::cout << "Element : " << xSearch << " is in the list" << std::endl;
            return;
        }
        Current = Current->Next;
    }
    std::cout << "Element : " << xSearch << " is not in the list" << std::endl;
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
    lenght++;
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

void Menu() {

    while (true) {
    
    
    
    
    }

}

int main()
{
    MakeList();
    moreLists[0].AddElement(45);
    moreLists[0].AddElement(775);
    moreLists[0].AddElement(896);
    moreLists[0].AddElement(45);
    moreLists[0].AddElement(115);
    moreLists[0].AddElement(102);
    moreLists[0].PrintList();
    moreLists[0].SearchThis(775);
    moreLists[0].DeleteThis(45);
    moreLists[0].DeleteAfter(45);
    moreLists[0].PrintList();
    moreLists[0].SearchThis(45);

    /*MakeList();
    moreLists[1].AddElement(8855);
    moreLists[1].AddElement(5);
    moreLists[1].AddElement(6);
    moreLists[1].PrintList();*/

}