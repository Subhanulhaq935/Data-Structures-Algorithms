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
                cout << current->data << " ";
                current = current->next;
            }

            cout << endl;
        }
    }

    void sortStack(Stack &s)
    {
        while(!s.isEmpty())
        {
             
        }
    }
};

int main()
{
    Stack stack;
    stack.push(4);
    stack.push(7);
    stack.push(10);
    stack.push(3);

    cout << "Stack contents: ";
    stack.display();

    stack.sortStack(stack);
    stack.display();
    // cout << "Top element: " << stack.peek() << endl;

    // stack.pop();
    // cout << "Stack contents after pop: ";
    // stack.display();

    // cout << "Top element after pop: " << stack.peek() <<endl;
    return 0;
}