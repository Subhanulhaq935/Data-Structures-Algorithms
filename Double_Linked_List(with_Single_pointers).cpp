#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *prev;
    Node *next;

public:
    Node()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }

    friend class DLL;
};

class DLL
{
    Node *first;

public:
    DLL()
    {
        first = NULL;
    }

    ~DLL()
    {
        Node *temp = first;
        while (temp != NULL)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    void insert_at_end(int x)
    {
        if (first == NULL)
        {
            first = new Node(x);
        }

        else
        {
            Node *temp = first;

            while (temp != NULL)
            {
                if (temp->next == NULL)
                {
                    Node *t = new Node(x);
                    temp->next = t;
                    t->prev = temp;
                    break;
                }

                temp = temp->next;
            }
        }
    }

    void insert_at_start(int x)
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
        }
        Node *temp = new Node(x);
        temp->next = first;
        first->prev = temp;
        first = temp;
    }

    void insert_before(int x, int y)
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
            return;
        }

        else
        {
            Node *temp = first;
            Node *pre = NULL;

            while (temp != NULL)
            {
                if (temp->data == x)
                {

                    Node *t = new Node(y);

                    if (temp == first)
                    {

                        t->next = first;
                        first->prev = t;
                        first = t;
                    }

                    else
                    {

                        t->prev = pre;
                        t->next = temp;
                        pre->next = t;
                        temp->prev = t;
                    }

                    return;
                }
                else
                {
                    pre = temp;
                    temp = temp->next;
                }
            }

            cout << "Number is not found:" << endl;
        }
    }

    void insert_after(int x, int y)
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
            return;
        }

        else
        {
            Node *temp = first;

            while (temp != NULL)
            {
                Node *t = new Node(y);
                if (temp->data == x)
                {
                    if (temp->next == NULL)
                    {
                        t->prev = temp;
                        t->next = temp->next;
                        temp->next = t;
                    }

                    else
                    {
                        t->next = temp->next;
                        temp->next->prev = t;
                        t->prev = temp;
                        temp->next = t;
                    }

                    return;
                }

                else
                {
                    temp = temp->next;
                }
            }

            cout << "Number is not found:" << endl;
        }
    }

    void delete_all(int x)
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
            return;
        }

        else
        {
            Node *temp = first;
            Node *pre = NULL;
            int count = 0;

            while (temp != NULL)
            {
                if (temp->data == x)
                {
                    count++;
                    if (pre == NULL)
                    {
                        first = first->next;
                        first->prev = NULL;
                        delete temp;
                        temp = first;
                    }
                    else
                    {
                        if (temp->next == NULL)
                        {
                            pre->next = NULL;
                            delete temp;
                            break;
                        }

                        else
                        {
                            pre->next = temp->next;
                            temp->next->prev = pre;
                            delete temp;
                            temp = pre->next;
                        }
                    }
                }

                else
                {
                    pre = temp;
                    temp = temp->next;
                }
            }

            if (count == 0)
            {
                cout << "Element is not found in this list:" << endl;
            }
        }
    }

    void delete_first_occurance(int x)
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
            return;
        }

        else
        {
            Node *temp = first;
            Node *pre = NULL;
            int count = 0;

            while (temp != NULL)
            {
                if (temp->data == x)
                {
                    count++;

                    if (count == 1)
                    {
                        if (pre == NULL)
                        {
                            first = first->next;
                            first->prev = NULL;
                            delete temp;
                            temp = first;
                            break;
                        }

                        else
                        {
                            if (temp->next == NULL)
                            {
                                pre->next = NULL;
                                delete temp;
                                break;
                            }

                            else
                            {
                                pre->next = temp->next;
                                temp->next->prev = pre;
                                delete temp;
                                break;
                            }
                        }
                    }
                }

                pre = temp;
                temp = temp->next;
            }
            if (count == 0)
            {
                cout << "Element is not found in this list:" << endl;
            }
        }
    }

    void delete_kth_occurance(int x, int k)
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
        }

        else
        {
            Node *temp = first;
            Node *pre = NULL;
            int count = 0;
            while (temp != NULL)
            {
                if (temp->data == x)
                {
                    count++;
                    if (count == k)
                    {
                        if (pre == NULL)
                        {
                            first = first->next;
                            first->prev = NULL;
                            delete temp;
                            break;
                        }

                        else
                        {
                            if (temp->next == NULL)
                            {
                                pre->next = NULL;
                                delete temp;
                                break;
                            }
                            else
                            {
                                pre->next = temp->next;
                                temp->next = pre->prev;
                                delete temp;
                                break;
                            }
                        }
                    }
                }

                pre = temp;
                temp = temp->next;
            }

            if (count == 0 || count < k || count > k)
            {

                cout << "Occurance not found in the list:" << endl;
            }
        }
    }

    void Reverse_list()
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
            return;
        }

        else
        {
            Node *temp = first;
            Node *pre = NULL;

            while (temp != NULL)
            {
                Node *nextNode = temp->next;
                temp->next = pre;
                temp->prev = nextNode;
                pre = temp;
                temp = nextNode;
            }

            first = pre;
        }
    }

    void print_reverse()
    {
        if (first == NULL)
        {
            cout << "The List is Empty:" << endl;
            return;
        }

        else
        {
            Node *temp = first;
            Node *extra = first;

            while (temp != NULL)
            {
                if(temp->next == NULL)
                {
                    first = temp;
                    break;
                }

                temp = temp->next;
            }

            while(first != NULL)
            {
                cout<< first->data;
                if(first->prev != NULL)
                {
                    cout<<"->";
                }

                first = first->prev;
            }

            first = extra;
        }
    }

    void print_list()
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
        }

        else
        {
            Node *temp;
            temp = first;

            while (temp != NULL)
            {
                cout << temp->data;
                if (temp->next != NULL)
                {
                    cout << "->";
                }

                temp = temp->next;
            }
        }
    }
};

int main()
{
    DLL list;
    int choice, value, afterValue, beforeValue, k;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at start\n";
        cout << "3. Insert after a value\n";
        cout << "4. Insert before a value\n";
        cout << "5. Delete kth occurrence\n";
        cout << "6. Delete first occurrence\n";
        cout << "7. Delete all occurrences\n";
        cout << "8. Reverse list\n";
        cout << "9. Print list\n";
        cout << "10.Reverse Print\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insert_at_end(value);
            break;

        case 2:
            cout << "Enter value to insert at start: ";
            cin >> value;
            list.insert_at_start(value);
            break;

        case 3:
            cout << "Enter the value to insert after: ";
            cin >> afterValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            list.insert_after(afterValue, value);
            break;

        case 4:
            cout << "Enter the value to insert before: ";
            cin >> beforeValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            list.insert_before(beforeValue, value);
            break;

        case 5:
            cout << "Enter the value to delete: ";
            cin >> value;
            cout << "Enter the occurrence number: ";
            cin >> k;
            list.delete_kth_occurance(value, k);
            break;

        case 6:
            cout << "Enter the value to delete first occurrence: ";
            cin >> value;
            list.delete_first_occurance(value);
            break;

        case 7:
            cout << "Enter the value to delete all occurrences: ";
            cin >> value;
            list.delete_all(value);
            break;

        case 8:

            list.Reverse_list();
            break;

        case 9:
            list.print_list();
            break;

        case 10:
            list.print_reverse();
            break;

        case 11:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
