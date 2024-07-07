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

    // Worst Solution:

    // void pairs(int sum)
    // {
    //     if(first ==  NULL)
    //     {
    //         cout<<"The list is Empty";
    //         return;
    //     }

    //     else
    //     {
    //         Node *temp1 = first;
    //         while(temp1 != NULL)
    //         {
    //             Node *temp2 = temp1->next;

    //             while(temp2 != NULL && temp1->data + temp2->data <= sum)
    //             {
    //                 if(temp1->data + temp2->data == sum)
    //                 {
    //                     cout<<"(" << temp1->data << "," << temp2->data <<")"<<endl;
    //                 }
    //                 temp2 = temp2->next;
    //             }

    //             temp1 = temp1->next;
    //         }

    //         cout<<"No pair found:"<<endl;
    //     }
    // }

    // Optimal Solution:
    // sorted list only:

    void pairs(int sum)
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
            return;
        }
        else
        {
            Node *head = first;
            Node *tail = last;
            bool found = false;

            while (tail->data > head->data)
            {
                if (head->data + tail->data == sum)
                {
                    cout << "(" << head->data << "," << tail->data << ")" << endl;
                    found = true;
                    head = head->next;
                    tail = tail->prev;
                }

                else if (head->data + tail->data > sum)
                {
                    tail = tail->prev;
                }

                else
                {
                    head = head->next;
                }
            }
            if (!found)
            {
                cout << "No pair found:" << endl;
            }
        }
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

    list.print_list();
    cout << endl;

    int sum;
    cout << "Enter the number whose pair you want to check: ";
    cin >> sum;

    list.pairs(sum);
    return 0;
}