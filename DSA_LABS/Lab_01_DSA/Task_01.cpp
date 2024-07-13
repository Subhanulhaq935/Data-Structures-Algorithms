#include <iostream>
using namespace std;

class Node
{
    int data;

public:
    Node *link;

    Node()
    {
        data = 0;
        link = NULL;
    }
    Node(int x)
    {
        data = x;
        link = NULL;
    }

    int getData()
    {
        return data;
    }
};

class SLL
{
public:
    Node *start;

    SLL()
    {
        start = NULL;
    }

    void insert_at_end(int x)
    {
        if (start == NULL)
        {
            start = new Node(x);
        }

        else
        {
            Node *temp;
            temp = start;

            while (temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = new Node(x);
        }
    }

    void print_list()
    {
        if (start == NULL)
        {
            cout << "The list is empty:";
        }

        Node *temp;
        temp = start;

        while (temp != NULL)
        {
            cout << temp->getData();
            if (temp->link != NULL)
            {
                cout << "->";
            }

            temp = temp->link;
        }
    }

    void Reverse_List()
    {
        if (start == NULL)
        {
            cout << "The list is Empty:" << endl;
        }

        else
        {
            Node *prev = NULL;
            Node *temp = start;

            while (temp != NULL)
            {
                Node *next = temp->link;
                temp->link = prev;
                prev = temp;
                temp = next;
            }

            start = prev;
        }
    }
};

int main()
{
    SLL list1;
    list1.insert_at_end(1);
    list1.insert_at_end(2);
    list1.insert_at_end(3);
    list1.insert_at_end(4);
    list1.insert_at_end(5);

    list1.Reverse_List();
    list1.print_list();

    return 0;
}