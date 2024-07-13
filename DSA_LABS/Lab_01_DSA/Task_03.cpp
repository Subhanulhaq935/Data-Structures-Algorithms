#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
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
   
};

class DLL
{
public:
    Node *first;
    Node *last;
    DLL() 
    {
        first = NULL;
        last = NULL;
    }
    void insert_at_the_end(int x)
    {
        if (first == NULL)
        {
            first = new Node(x);
            last = first;
        }
        else
        {
            last->next = new Node(x);
            last->next->prev = last;
            last = last->next;
        }
    }
    void print_list()
    {
        if (first == NULL)
        {
            cout << "The list is empty:";
        }

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
    void deleteNthNodeFromTheEnd(int n)
    {
        if (first == NULL)
        {
            return;
        }
        Node *temp = last;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            if (count == n)
            {
                if (temp->next == NULL)
                {
                    temp->prev->next = NULL;
                    delete temp;
                    break;
                }
                else if (temp->prev == NULL)
                {
                    temp->next->prev = NULL;
                    first = first->next;
                    delete temp;
                    break;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    break;
                }
            }
            temp = temp->prev;
        }
    }
};

int main()
{
    DLL list1;

    list1.insert_at_the_end(1);
    list1.insert_at_the_end(2);
    list1.insert_at_the_end(3);
    list1.insert_at_the_end(4);
    list1.insert_at_the_end(5);

    list1.deleteNthNodeFromTheEnd(2);

    list1.print_list();
    return 0;
}