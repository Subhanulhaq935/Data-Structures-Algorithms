#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *prev;
    Node *next;

public:
    Node(int x)
    {
        data = x;
        prev = NULL;
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
        if (top == NULL)
        {
            Node *newNode = new Node(x);
            newNode->next = top;
            top = newNode;
        }

        else
        {
            Node *newNode = new Node(x);
            newNode->next = top;
            top->prev = newNode;
            top = newNode;
        }
    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty:";
            return;
        }

        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
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

    int count_the_elements()
    {
        int count = 0;
        Node *temp = top;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main()
{
    Stack stack;
    int choice, value;

    do
    {
        cout << "\nStack Menu:\n";
        cout << "1. Push an element\n";
        cout << "2. Pop an element\n";
        cout << "3. Display stack contents\n";
        cout << "4. Count elements in the stack\n";
        cout << "5. Check if the stack is empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            stack.push(value);
            cout << value << " pushed to stack." << endl;
            break;

        case 2:
            if (!stack.isEmpty())
            {
                cout << "Popping top element." << endl;
                stack.pop();
            }
            else
            {
                cout << "Stack is Empty. Nothing to pop." << endl;
            }
            break;

        case 3:
            cout << "Stack contents: " << endl;
            stack.display();
            break;

        case 4:
            cout << "Number of elements in stack: " << stack.count_the_elements() << endl;
            break;

        case 5:
            if (stack.isEmpty())
            {
                cout << "The stack is empty." << endl;
            }
            else
            {
                cout << "The stack is not empty." << endl;
            }
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}