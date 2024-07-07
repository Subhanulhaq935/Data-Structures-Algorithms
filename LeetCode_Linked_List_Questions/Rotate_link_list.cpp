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

    Node *Rotate(int R)
    {
        if(start == NULL)
        {
            return NULL;
        }

        else
        {
            Node *temp = start;
            int lenght = 1;
            while(temp->link != NULL)
            {
                lenght++;
                temp = temp->link;
            }

            temp->link = start;

            R = R % lenght;

            int count = lenght - R;

            temp = start;
           while(temp != NULL)
           {
             count--;
             if(count == 0)
             {
                start = temp->link;
                temp->link = NULL;
             }
             temp = temp->link;

           } 

           return start;
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

    list.Rotate(22);

    cout<<"Rotated list by times"<<endl;

    list.print_list();
    return 0;
}