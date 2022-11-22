#include <iostream>
using namespace std;

#include <fstream>


struct Node
{
    int data;
    Node* pnext;

    Node(int _data) : data(_data), pnext(nullptr) {}

    bool compare(Node test_node)
    {
        return data == test_node.data;
    }
};

class List
{
    Node* head;
    Node* tail;

public:

    List()
    {
        head = nullptr;
        tail = head;
    }

    void addNode(int value)
    {
        Node* new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            Node* temp = head;
            while (temp->pnext != nullptr)
                temp = temp->pnext;
            temp->pnext = new_node;
        }
        tail = new_node;
    }
    void deleteElement(int value)
    {
        if (head == NULL)
            return;
        
        Node* i = head, * j = head->pnext;
        while (j != tail)
        {
            if (j->data == value)
            {
                //перестановка
                i->pnext = j->pnext;
                delete j;
                j = i->pnext;

            }
            else
            {
                i = i->pnext, j = j->pnext;
            }
        }

    }
    void printLinkedList()
    {
        Node* temp = head;
        while (temp->pnext != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->pnext;
        }
    }
};
