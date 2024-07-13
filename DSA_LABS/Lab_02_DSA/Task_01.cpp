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
            if (nextNode == first)
                break;
            temp = nextNode;
        }

        first = NULL;
        last = NULL;
    }

    void insert_at_start(int x)
    {
        if (first == NULL)
        {
            first = new Node(x);
            last = first;
            last->next = last->prev = first;
        }

        Node *t = new Node(x);
        t->next = first;
        first->prev = t;
        t->prev = last;
        last->next = t;
        first = t;
    }

    void insert_at_end(int x)
    {
        Node *t = new Node(x);
        if (first == nullptr)
        {
            first = t;
            last = t;
            first->next = first;
            first->prev = first;
        }
        else
        {
            t->next = first;
            t->prev = last;
            last->next = t;
            first->prev = t;
            last = t;
        }
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

            while (1)
            {
                cout << temp->data;
                if (temp->next != first)
                {
                    cout << "->";
                }

                if (temp->next == first)
                    return;

                temp = temp->next;
            }
        }
    }

    int removeMthNodes(int m)
    {
        Node *temp;
        temp = first;

        while (1)
        {
            for (int i = 1; i < m; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            Node *del;
            del = temp;
            if (temp == first)
                first= first->next;
                first->prev = last;

            if (temp == last)
                last = last->prev;
                last->next = first;
            delete del;
            temp = temp->next;
            if (first == last)
                break;
        }
        return temp->data;
    }

};

int main()
{

    DLL list;
    list.insert_at_end(1);
    list.insert_at_end(2);
    list.insert_at_end(3);
    list.insert_at_end(4);
    list.insert_at_end(5);
    list.insert_at_end(6);
    list.insert_at_end(7);

    list.print_list();
    cout << endl;

    int x = list.removeMthNodes(3);
    cout<<x;

    //list.print_list();
    return 0;
}