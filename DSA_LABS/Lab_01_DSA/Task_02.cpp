#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *link;

    Node()
    {
        data = 0;
        link = nullptr;
    }
    Node(int x)
    {
        data = x;
        link = nullptr;
    }

    int getData()
    {
        return data;
    }
};

class SLL
{
private:
    Node *start;

public:
    SLL()
    {
        start = nullptr;
    }

    void insert_at_the_end(int x)
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

    void ZigZagList()
    {
        Node *temp;
        temp = start;
        int count = 1;
        while (temp->link != nullptr)
        {
            if (count % 2 == 1)
            {
                if (temp->data > temp->link->data)
                {
                    int x;
                    x = temp->data;
                    temp->data = temp->link->data;
                    temp->link->data = x;
                }
            }
            else if (count % 2 == 0)
            {
                if (temp->data < temp->link->data)
                {
                    int x;
                    x = temp->data;
                    temp->data = temp->link->data;
                    temp->link->data = x;
                }
            }
            temp = temp->link;
            count++;
        }
    }
};

int main()
{
    SLL list1;

    list1.insert_at_the_end(1);
    list1.insert_at_the_end(2);
    list1.insert_at_the_end(3);
    list1.insert_at_the_end(4);
    list1.insert_at_the_end(5);

    list1.ZigZagList();

    list1.print_list();

    return 0;
}