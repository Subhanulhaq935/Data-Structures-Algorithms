#include <iostream>
using namespace std;

class Node

{
    int data;
    Node *prev;
    Node *next;

public:
    Node()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }

    friend class DLL;
};

class DLL
{
    Node *first;
    Node *last;

public:
    DLL()
    {
        first = NULL;
        last = NULL;
    }

    ~DLL()
    {
        Node *temp = first;
        while (temp != NULL)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        first = NULL;
        last = NULL;
    }

    void print_list()
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
        }

        else
        {
            Node *temp;
            temp = first;

            while (temp != NULL)
            {
                cout << temp->data;
                if (temp->next != NULL)
                {
                    cout << "->";
                }

                temp = temp->next;
            }
        }
    }

    void insert_at_start(int x)
    {
        if (first == NULL)
        {
            first = new Node(x);
            last = first;
        }
        else
        {
            Node *temp = new Node(x);
            temp->next = first;
            first->prev = temp;
            first = temp;
        }
    }

    void insert_at_end(int x)
    {
        if (first == NULL)
        {
            first = new Node(x);
            last = first;
        }

        else
        {
            Node *temp = new Node(x);
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }

    void Remove_Duplicate()
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
            return;
        }

        Node *temp1 = first;
        Node *temp2 = temp1->next;
        bool found = false;

        while (temp1->next != NULL)
        {
            if (temp1->data == temp2->data)
            {
                temp1->next = temp2->next;
                temp2->next->prev = temp1;
                delete temp2;
                temp2 = temp1->next;
                found = true;
            }

            else
            {
                temp1 = temp2;
                temp2 = temp2->next;
            }
        }
        if (!found)
        {
            cout << "No duplicate found:" << endl;
        }
    }
};

int main()
{
    DLL list;
    list.insert_at_end(1);
    list.insert_at_end(1);
    list.insert_at_end(1);
    list.insert_at_end(2);
    list.insert_at_end(3);
    list.insert_at_end(3);
    list.insert_at_end(4);

    list.print_list();
    cout << endl;

    list.Remove_Duplicate();
    list.print_list();

    return 0;
}