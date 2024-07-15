#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }

        else
        {
            top = top + 1;
            arr[top] = x;
        }
    }

    bool isFull()
    {
        if (top == capacity - 1)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
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
        int x;
        if (isEmpty())
        {
           // cout << "Stack UnderFlow:";
            return -1;
        }

        else
        {
            x = arr[top];
            top = top - 1;
            return x;
        }
    }

    int peek()
    {

        int x;

        if (top == -1)
        {
            return -1;
        }
        x = arr[top];
        return x;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        // if(isFull())
        // {
        //     cout<<" Stack Overflow:\n";
        //     return;
        // }
        else
        {
            cout << "In Array elements are: ";
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;

            cout << "In Stack the order of elements are: ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    // stack.print();
    // stack.push(6);

    // stack.pop();
    // stack.pop();
    // stack.pop();
    // stack.pop();
    // stack.pop();

    // int x = stack.peek();
    // cout << "Peek is: ";
    // cout << x;
    // cout << endl;

    //stack.pop();

    stack.print();

    return 0;
}