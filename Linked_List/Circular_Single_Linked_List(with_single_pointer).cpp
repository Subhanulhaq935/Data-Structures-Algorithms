#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int x)
    {
        data = x;
        next = NULL;
    }

    friend class CSLL;
};

class CSLL
{
    Node *last;

public:
    CSLL()
    {
        last = NULL;
    }

    void insert_at_end(int x)
    {
        if (last == NULL)
        {
            last = new Node(x);
            last->next = last;
        }

        else
        {
            Node *t = new Node(x);
            t->next = last->next;
            last->next = t;
            last = t;
        }
    }

    void insert_at_start(int x)
    {
        if (last == NULL)
        {
            last = new Node(x);
            last->next = last;
        }

        Node *temp = last->next;
        Node *t = new Node(x);
        t->next = temp;
        last->next = t;
    }

    void insert_before(int x, int y)
    {
        Node *temp = last->next;
        Node *prev = NULL;

        if (temp->data == x)
        {
            Node *t = new Node(y);
            t->next = temp;
            last->next = t;
            return;
        }
        // Node* first = last->next;
        while (1)
        {
            prev = temp;
            temp = temp->next;

            if (temp == last->next)
                break;

            if (temp->data == x)
            {
                Node *t = new Node(y);
                prev->next = t;
                t->next = temp;
                break;
            }
        }
    }

    void insert_after(int x, int y)
    {
        Node *temp = last->next;

        while (1)
        {
            if (temp->data == x)
            {
                Node *t = new Node(y);
                t->next = temp->next;
                temp->next = t;
                break;
            }
            temp = temp->next;
            if (temp == last)
            {

                if (temp->data == x)
                {
                    Node *t = new Node(y);
                    t->next = temp->next;
                    temp->next = t;
                    last = t;
                    break;
                }
            }
            if (temp == last->next)
                break;
        }
    }

    void delete_at_end()
    {
        if (last == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        if (last->next == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            Node *temp = last->next;
            Node *prev = NULL;

            while (temp->next != last)
            {
                temp = temp->next;
            }

            prev = temp;
            temp = temp->next;
            prev->next = last->next;
            delete last;
            last = prev;
        }
    }

    void delete_at_start()
    {
        if (last == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node *temp = last->next;

        if (temp == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            last->next = temp->next;
            delete temp;
        }
    }

    void delete_specific_Node(int x)
    {
        Node *temp = last->next;
        Node *prev = NULL;
        int count = 1;
        while (1)
        {
            if (count == x)
            {
                if (temp == last->next)
                {
                    last->next = temp->next;
                    delete temp;
                    break;
                }

                else if (temp == last)
                {
                    prev->next = temp->next;
                    delete temp;
                    last = prev;
                    break;
                }

                else
                {
                    prev->next = temp->next;
                    delete temp;
                    break;
                }
            }

            else
            {
                prev = temp;

                temp = temp->next;
                count++;

                if (temp == last->next)
                    break;
            }
        }
    }

    void display()
    {
        if (last == NULL)
        {
            cout << "The list is Empty:";
            return;
        }
        else
        {
            Node *temp = last->next;

            while (1)
            {
                cout << temp->data;
                temp = temp->next;
                if (temp != last->next)
                {
                    cout << "->";
                }

                if (temp == last->next)
                {
                    break;
                }
            }
        }
    }
};

int main()
{

    CSLL list;
    list.insert_at_end(1);
    list.insert_at_end(2);
    list.insert_at_end(3);
    // list.insert_at_start(4);
    // list.insert_before(1,4);
    // list.insert_after(3, 4);
    // list.delete_at_end();
    //list.delete_at_start();
    list.delete_specific_Node(1);

    list.display();
    return 0;
}