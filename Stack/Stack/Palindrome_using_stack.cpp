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
            int poppedValue = temp->data;
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

    bool isPalindrome()
    {
        if (start == NULL || start->next == NULL) return true;

        Stack stack;
        Node* temp = start;

       
        while (temp != NULL)
        {
            stack.push(temp->data);
            temp = temp->next;
        }

        temp = start;
        while (temp != NULL)
        {
            if (temp->data != stack.pop())
            {
                return false;
            }
            temp = temp->next;
        }
        return true;
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
    list.insert_at_end(2);
    list.insert_at_end(1);

    cout << "Linked List: ";
    list.display();

    if (list.isPalindrome())
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
