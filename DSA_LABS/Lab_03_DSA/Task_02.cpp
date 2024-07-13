// In this Task I use 2 stack:
// One is for Enqueue Operations and the second one is for Dequeue operation:

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
        return top == NULL;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty:" << endl;
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
};

// Queue class using two stacks
class Queue_Using_Stack
{
    Stack s1;
    Stack s2;

public:
    bool is_empty()
    {
        return s1.isEmpty() && s2.isEmpty();
    }

    void Enqueue(int x)
    {
        s1.push(x);
    }

    int Dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is Empty:" << endl;
            return -1;
        }

        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.peek());
                s1.pop();
            }
        }

        if (s2.isEmpty())
        {
            cout << "Queue is Empty:" << endl;
            return -1;
        }

        int v = s2.peek();
        s2.pop();
        return v;
    }
};

int main()
{
    Queue_Using_Stack q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;

    return 0;
}
