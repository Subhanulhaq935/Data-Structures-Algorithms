// In this Task I use space as a delimeter:
// Agar ap double number dain gay infix me to postfix me wo space se differentiate ho ga:

#include <iostream>
#include <string>
using namespace std;

class Node
{
    double data;
    Node *next;

public:
    Node(double x)
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

    void push(double x)
    {
        Node *t = new Node(x);
        t->next = top;
        top = t;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "There is nothing to pop:" << endl;
            return;
        }
        Node *t = top;
        top = top->next;
        delete t;
    }

    double peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return top->data;
    }
};

int Precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool Check_Digit(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool Check_Space(char c)
{
    if (c == ' ')
        return true;
    else
        return false;
}

bool Check_Character(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return true;
    else
        return false;
}

class Calculator
{
    string Infix;
    char delimeter;

public:
    Calculator() : delimeter(' ') {}

    string InfixtoPostfix(string infix);
    double Evaluate_Postfix(string Postfix);
};

string Calculator::InfixtoPostfix(string infix)
{
    Stack s;
    string result = "";
    int i = 0;

    while (infix[i] != '\0')
    {
        if (Check_Digit(infix[i]) || Check_Character(infix[i]))
        {
            while (infix[i] != '\0' && (Check_Digit(infix[i]) || Check_Character(infix[i]) || infix[i] == '.'))
            {
                result += infix[i];
                i++;
            }

            result += ' ';
            continue;
        }
        else if (Check_Space(infix[i]))
        {
            i++;
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                result += s.peek();
                result += ' ';
                s.pop();
            }

            s.pop();
            i++;
        }
        else
        {
            while (!s.isEmpty() && Precedence(infix[i]) <= Precedence(s.peek()))
            {
                result += s.peek();
                result += ' ';
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }

    while (!s.isEmpty())
    {
        result += s.peek();
        result += ' ';
        s.pop();
    }

    return result;
}

double Solve(double op1, double op2, char c)
{
    switch (c)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        if (op2 == 0)
        {
            cout << "Division by zero is not allowed." << endl;
            exit(1);
        }
        return op1 / op2;
    default:
        return 0;
    }
}

double Calculator::Evaluate_Postfix(string Postfix)
{
    Stack st;
    int i = 0;
    while (Postfix[i] != '\0')
    {
        if (Check_Digit(Postfix[i]))
        {
            string temp = "";
            while (Postfix[i] != '\0' && (Check_Digit(Postfix[i]) || Postfix[i] == '.'))
            {
                temp += Postfix[i];
                i++;
            }

            st.push(stod(temp));
        }
        else if (Check_Space(Postfix[i]))
        {
            i++;
        }
        else
        {
            double op2 = st.peek();
            st.pop();

            double op1 = st.peek();
            st.pop();

            double res = Solve(op1, op2, Postfix[i]);
            st.push(res);
            i++;
        }
    }

    return st.peek();
}

int main()
{
    Calculator calc;
    string infix;

    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = calc.InfixtoPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    double result = calc.Evaluate_Postfix(postfix);
    cout << "The Result is: " << result << endl;

    return 0;
}
