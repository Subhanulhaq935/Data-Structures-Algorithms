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
    Stack stack;
    int choice, value;

    do
    {
        cout << "\nStack Menu:\n";
        cout << "1. Push an element\n";
        cout << "2. Pop an element\n";
        cout << "3. Peek at the top element\n";
        cout << "4. Display stack contents\n";
        cout << "5. Count elements in the stack\n";
        cout << "6. Check if the stack is empty\n";
        cout << "7. Exit\n";
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
                cout << "POP the top element:" << endl;
                stack.pop();
            }
            else
            {
                cout << "There is Nothing to POP:" << endl;
            }
            break;

        case 3:
            value = stack.peek();
            if (value != -1)
            {
                cout << "Top element is " << value << endl;
            }
            break;

        case 4:
            cout << "Stack contents: ";
            cout<<endl;
            stack.display();
            break;

        case 5:
            cout << "Number of elements in stack: " << stack.count_elements_in_Stack() << endl;
            break;

        case 6:
            if (stack.isEmpty())
            {
                cout << "The stack is empty." << endl;
            }
            else
            {
                cout << "The stack is not empty." << endl;
            }
            break;

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
            break;
        }
    } while (choice != 7);

    return 0;
}
