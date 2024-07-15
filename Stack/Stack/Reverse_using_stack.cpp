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

    friend class SLL;  // Friend class to access Node's members
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
        return top == NULL;
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
            Node* temp = top;
            top = top->next;
            int poppedValue = temp->data;  // Retrieve the data before deleting
            delete temp;
            return poppedValue;
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

        Node* current = top;

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
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
            Node *nextNode = temp->next;
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
            Node *temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new Node(x);
        }
    }

    void reverse()
    {
        if (start == NULL || start->next == NULL) return;

        Stack stack;
        Node* temp = start;

        // Push all elements of the linked list onto the stack
        while (temp != NULL)
        {
            stack.push(temp->data);
            temp = temp->next;
        }

        temp = start;

        // Pop all elements from the stack and reassign to the nodes
        while (temp != NULL)
        {
            temp->data = stack.pop();
            temp = temp->next;
        }
    }

    void display()
    {
        if (start == NULL)
        {
            cout << "List is Empty:" << endl;
            return;
        }

        Node* current = start;

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
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

    cout << "Original Linked List: ";
    list.display();

    list.reverse();

    cout << "Reversed Linked List: ";
    list.display();

    return 0;
}
