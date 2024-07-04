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
    Node *last;

public:
    DLL()
    {
        first = NULL;
        last = NULL;
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

        first = NULL;
        last = NULL;
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

    void insert_at_start(int x)
    {
        if (first == NULL)
        {
            first = new Node(x);
            last = first;
        }
        else
        {
            Node *temp = new Node(x);
            temp->next = first;
            first->prev = temp;
            first = temp;
        }
    }

    void insert_at_end(int x)
    {
        if (first == NULL)
        {
            first = new Node(x);
            last = first;
        }

        else
        {
            Node *temp = new Node(x);
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }

    void insert_before(int x, int y)
    {
        if (first == NULL)
        {
            cout << "The List is Empty:" << endl;
        }

        if (first->next == NULL)
        {
            Node *temp = new Node(y);
            temp->next = first;
            first->prev = temp;
            first = temp;
        }

        else
        {
            Node *temp = first;
            Node *p = NULL;

            while (temp != NULL)
            {
                if (temp->data == x)
                {
                    Node *t = new Node(y);
                    p->next = t;
                    t->prev = p;
                    t->next = temp;
                    temp->prev = t;
                }

                p = temp;
                temp = temp->next;
            }
        }
    }

    void insert_after(int x, int y)
    {
        if (first == NULL)
        {
            cout << "The List is Empty:" << endl;
        }

        if (last->data == x)
        {
            Node *t = new Node(y);
            last->next = t;
            t->prev = last;
            last = t;
        }
        else
        {
            Node *temp = first;
            while (temp != NULL)
            {
                if (temp->data == x)
                {
                    Node *t = new Node(y);
                    t->next = temp->next;
                    temp->next->prev = t;
                    t->prev = temp;
                    temp->next = t;
                }

                temp = temp->next;
            }
        }
    }

    void delete_first_occurance(int x)
    {
        if (first == NULL)
        {
            cout << "The List is Empty:" << endl;
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
                            break;
                        }

                        else
                        {
                            if (temp->next == NULL)
                            {
                                pre->next = NULL;
                                last = pre;
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

                cout << "Occurance not found in the list:" << endl;
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
                                last = pre;
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

    void delete_all_Occurances(int x)
    {
        if (first == NULL)
        {
            cout << "The List is Empty:" << endl;
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
                        if (first != NULL)
                        {
                            first->prev = NULL;
                        }

                        delete temp;
                        temp = first;
                    }

                    else
                    {
                        if (temp->next == NULL)
                        {
                            pre->next = NULL;
                            last = pre;
                            delete temp;
                            // temp = NULL;
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

    void Reverse_List()
    {
        if (first == NULL)
        {
            cout << "The list is Empty:" << endl;
        }

        else
        {
            Node *pre = NULL;
            Node *temp = first;

            last = first; // Agar ap DLL Single pointer se kar rahe .... just comment out this statement:

            while (temp != NULL)
            {
                Node *nextnode = temp->next;
                temp->next = pre;
                temp->prev = nextnode;
                pre = temp;
                temp = nextnode;
            }

            first = pre;
        }
    }

    void Print_Reverse()
    {
        Node *temp = last;
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->prev != NULL)
            {
                cout << "->";
            }

            temp = temp->prev;
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
        cout << "10. Print Reverse\n";
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
            list.delete_all_Occurances(value);
            break;

        case 8:
            list.Reverse_List();
            break;

        case 9:
            list.print_list();
            break;

        case 10:
            list.Print_Reverse();
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
