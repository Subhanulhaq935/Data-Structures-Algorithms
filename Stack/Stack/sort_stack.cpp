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

    friend class Stack;
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    ~Stack()
    {
        while (top != NULL)
        {
            Node *t = top;
            top = top->next;
            delete t;
        }
    }

    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty:" << endl;
            return -1;
        }

        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty:" << endl;
            return;
        }

        else
        {
            Node *current = top;

            while (current != NULL)
            {
                cout << "| " << current->data << " |";
                cout << endl;
                current = current->next;
            }

            cout << " ---";
        }
    }

    int count_elements_in_Stack()
    {
        int count = 0;

        Node *t = top;

        while (t != NULL)
        {
            count++;
            t = t->next;
        }

        return count;
    }
};




int main()
{
    int n;
    cout << "Enter the size:" << endl;
    cin >> n;

    Stack  s1, s2;

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s1.push(a);
    }

    while(!s1.isEmpty())
    {
        int k = s1.peek();
        s1.pop();

        while(!s2.isEmpty() && s2.peek() < k)
        {
            s1.push(s2.peek());
            s2.pop();
        }

        s2.push(k);
    }

    cout<<"Sorted Stack:"<<endl;

   // while(!s2.isEmpty())
    //{
        s2.display();
        //s2.pop();
    //}

    cout<<endl;

    return 0;
}
