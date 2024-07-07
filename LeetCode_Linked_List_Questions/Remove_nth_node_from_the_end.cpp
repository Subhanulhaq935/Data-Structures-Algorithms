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

    void delete_end_Node_from_the_end(int n)
    {
        Node* temp = start;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp->link;
        }

        int d = count - n;
        temp = start;

        while(temp != NULL)
        {
            d--;
            if(d == 0)
            {
                Node* t = temp->link;
                temp->link = t->link;
                delete t;
                break;
            }
            temp = temp->link;
        }
    }
};

int main()
{
    SLL list;
    list.insert_at_end(1);
    list.insert_at_end(2);
    list.insert_at_end(3);
    list.insert_at_end(4);
    list.insert_at_end(5);
    list.insert_at_end(6);

    list.print_list();
    cout<<endl;

    list.delete_end_Node_from_the_end(2);

    list.print_list();
    return 0;
}