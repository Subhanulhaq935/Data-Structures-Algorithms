#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *link;

public:
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

    friend class SLL;
};

class SLL
{
    Node *start;

public:
    SLL()
    {
        start = NULL;
    }

    ~SLL()
    {
        Node *temp = start;
        while (temp != NULL)
        {
            Node *nextNode = temp->link;
            delete temp;
            temp = nextNode;
        }
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

    Node *Seggregate()
    {
        if (start == NULL)
        {
            return NULL;
        }

        else
        {
            Node *t1 = start;
            Node *t2 = start->link;
            Node *t3 = t2;

            while (t1->link != NULL && t2->link != NULL)
            {
                t1->link = t1->link->link;
                t1 = t1->link;

                t2->link = t2->link->link;
                t2 = t2->link;
            }

            t1->link = t3;

            return start;
        }
    }
};

int main()
{
    SLL list;
    list.insert_at_end(0);
    list.insert_at_end(-2);
    list.insert_at_end(1);
    list.insert_at_end(4);
    list.insert_at_end(6);

    list.print_list();
    cout << endl;

    cout << "Seggregate List:" << endl;

    list.Seggregate();

    list.print_list();

    return 0;
}




