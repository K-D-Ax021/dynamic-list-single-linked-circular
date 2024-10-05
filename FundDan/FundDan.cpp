
#include <iostream>
#include <vector>
#include <map>
#include <windows.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

struct Node {
    int x;
    Node* Next;
};
class List {
    
    
    
public:
    Node* Head, * Tail, * Current;
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
    void DeleteList();
};
//List arrayLists[5];
std::vector<List> moreLists;
std::map<std::string, int> mapLists;
int countList = 0;
int nowWorkList = 0;

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
    
    if (Head == nullptr) {

        std::cout << "List  is empty!" << std::endl;
        return;
    } 

    Node* temp = Head;
    do {
        std::cout << temp->x << " ";
        temp = temp->Next;
    } while (temp != Head);
    std::cout << std::endl;
}

void MakeList() {
    if (countList >= 4) {
        std::cout << "MAX count List!" << std::endl;
        return;
    }

    std::string nameList;
    std::cout << "Enter name of the new list: ";
    std::cin >> nameList;
    if (mapLists.find(nameList) != mapLists.end()) {
        
        std::cout << " SAME NAME LIST! ERROR!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }
    mapLists[nameList] = countList + 1;
    moreLists.push_back(List());
    countList++;
    
    
}
void DeleteMapList(const std::string& nameList) {
    auto it = mapLists.find(nameList);
    if (it != mapLists.end()) {
        int index = it->second - 1;  // Индекс списка
        moreLists.erase(moreLists.begin() + index);
        mapLists.erase(it);

        // Обновляем индексы в mapLists после удаления
        int newIndex = 1;
        for (auto& pair : mapLists) {
            pair.second = newIndex++;
        }

        countList--;  
    }
}

void List::DeleteList() {
    if (Head == nullptr) {
        std::cout << "List is already empty!" << std::endl;
        return;
    }

    Node* current = Head;
    Node* next = nullptr;

    do {
        next = current->Next;
        delete current;
        current = next;
    } while (current != Head);

    Head = nullptr;
    Tail = nullptr;
    lenght = 0;

    std::cout << "List deleted successfully!" << std::endl;
}


void MenuOut() {

    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(
        console_color, 2);


    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    SetConsoleTextAttribute(
        console_color, 3);
    std::cout << "1 Make List (Max list = 4)" <<  std::endl;
    std::cout << "2 Add element" << std::endl;
    std::cout << "3 Delete all same elements" << std::endl;
    std::cout << "4 Delete after number" << std::endl;
    std::cout << "5 Search elements" << std::endl;
    std::cout << "6 Print list" << std::endl;
    std::cout << "7 Delete List" << std::endl;
    SetConsoleTextAttribute(
        console_color, 2);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    SetConsoleTextAttribute(
        console_color, 5);
    std::cout << "Your Lists : \n" << std::endl;
    for (auto it = mapLists.begin(); it != mapLists.end(); it++)
    {
        std::cout << "  " << mapLists[it->first] << " " << it->first << "  ";
    }
    SetConsoleTextAttribute(
        console_color, 2);
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    SetConsoleTextAttribute(
        console_color, 1);
    
    for (int i = 0; i < countList;i++) {
        std::cout << i + 1 << " : ";
        moreLists[i].PrintList();
    }
    SetConsoleTextAttribute(
        console_color, 2);
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    SetConsoleTextAttribute(
        console_color, 6);
}
void Menu() {
    int codeCommand = 0;
    do {
        MenuOut();
        std::cout << "Enter code Command : ";
        std::cin >> codeCommand;
        if (codeCommand > 7 || codeCommand < 1) {
            std::cout << "Unknown command !" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else {
            switch (codeCommand)
            {
            case 1:
                MakeList();
                break;
            case 2:
                if (countList == 0) {
                    std::cout << "At first Create List!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
                else {
                    std::cout << "Chose number list : ";
                    std::cin >> nowWorkList;
                    if (nowWorkList > countList || nowWorkList < 1) {
                        std::cout << "Unknown List ! " << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        break;
                    }
                    else {
                        std::cout << "Enter Numbers what you want to add, or enter '-1' keyword to exit  : ";
                        int numb = 0;
                        while (true) {
                            std::cin >> numb;
                            if (numb == -1)
                            {
                                break;
                            }

                            moreLists[nowWorkList - 1].AddElement(numb);

                        }

                    }
                }



                break;
            case 3:
                if (countList == 0) {
                    std::cout << "At first Create List!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    break;
                }
                else {
                    std::cout << "Chose number list : ";
                    std::cin >> nowWorkList;
                    if (nowWorkList > countList || nowWorkList < 1) {
                        std::cout << "Unknown List ! " << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        break;
                    }
                    else {
                        int numb = 0;
                        std::cout << "Enter number what you want to delete : ";
                        std::cin >> numb;
                        moreLists[nowWorkList - 1].DeleteThis(numb);
                    }
                }
                break;
            case 4:
                if (countList == 0) {
                    std::cout << "At first Create List!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    break;
                }
                else {
                    std::cout << "Chose number list : ";
                    std::cin >> nowWorkList;
                    if (nowWorkList > countList || nowWorkList < 1) {
                        std::cout << "Unknown List ! " << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        break;
                    }
                    else {
                        int numb = 0;
                        std::cout << "Enter number after there to delete : ";
                        std::cin >> numb;
                        moreLists[nowWorkList - 1].DeleteAfter(numb);
                    }
                }
                break;
            case 5:
                if (countList == 0) {
                    std::cout << "At first Create List!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    break;
                }
                else {
                    std::cout << "Chose number list : ";
                    std::cin >> nowWorkList;
                    if (nowWorkList > countList || nowWorkList < 1) {
                        std::cout << "Unknown List ! " << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        break;
                    }
                    else {
                        int numb = 0;
                        std::cout << "Enter number what you want search : ";
                        std::cin >> numb;
                        moreLists[nowWorkList - 1].SearchThis(numb);
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                    }
                }
                break;
            case 6:
                if (countList == 0) {
                    std::cout << "At first Create List!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    break;
                }
                else {
                    std::cout << "Choose number list : ";
                    std::cin >> nowWorkList;
                    if (nowWorkList > countList || nowWorkList < 1) {
                        std::cout << "Unknown List ! " << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        break;
                    }
                    else {

                        moreLists[nowWorkList - 1].PrintList();
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                    }
                }
                break;
            case 7:  
                if (countList == 0) {
                    std::cout << "At first, create a list!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
                else {
                    std::string nameList;
                    std::cout << "Enter the name of the list to delete: ";
                    std::cin >> nameList;
                    DeleteMapList(nameList);
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }
                break;
            default:
                break;
            }

        }

        system("cls");

    } while (true);

}

int main()
{
    Menu();

}