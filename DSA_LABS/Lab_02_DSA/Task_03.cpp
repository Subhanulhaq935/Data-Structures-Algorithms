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

    Node *reverse(Node *start)
    {
        Node *prev = NULL;
        Node *current = start;
        Node *next = NULL;

        while (current != NULL)
        {
            next = current->link; 
            current->link = prev; 
            prev = current;      
            current = next;       
        }
    

        return prev; 
    }

    bool Palindrome()
    {
        Node *fast = start->link;
        Node *slow = start;

        while (fast!= NULL && fast->link!= NULL)
        {
            fast = fast->link->link;
            slow = slow->link;
        }

        Node * temp = reverse(slow->link);

        Node* firstNode = start;
        Node* SecondNode = temp;

        while(temp != NULL)
        {
            if(firstNode->data != temp->data)
            {
               return false;
                break;
            }

            firstNode = firstNode->link;
            temp = temp->link;
        }

        slow->link = reverse(SecondNode);

        return true;

    }
};

int main()
{
    SLL list;
    list.insert_at_end(1);
    list.insert_at_end(2);
    list.insert_at_end(3);
    list.insert_at_end(3);
    list.insert_at_end(2);
    list.insert_at_end(1);

    list.print_list();
    cout<<endl;

    bool check = list.Palindrome();

    if (!check)
    {
        cout << "The list is not a Palindrome:" << endl;
    }
    else
    {
        cout << "The list is Palindrome:" << endl;
    }

    //list.print_list();

    return 0;
}