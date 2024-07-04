#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *link;

public:
    Node()
    {
        data = 0;
        link = NULL;
    }

    Node(int x)
    {
        data = x;
        link = NULL;
    }

    int getData()
    {
        return data;
    }

    friend class SLL;
};

class SLL
{
    Node *start;
    Node *last;

public:
    SLL()
    {
        start = NULL;
        last = NULL;
    }

    ~SLL()
    {
        Node *temp = start;
        while (temp != NULL)
        {
            Node *nextNode = temp->link;
            delete temp;
            temp = nextNode;
        }
    }

    void insert_at_end(int x)
    {
        if (start == NULL)
        {
            start = new Node(x);
            last = start;
        }

        else
        {
            Node *temp = start;

            while (temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = new Node(x);
            last = temp->link;
        }
    }

    void insert_at_start(int x)
    {
        if (start == NULL)
        {
            start = new Node(x);
            last = start;
        }

        else
        {

            Node *temp = new Node(x);
            temp->link = start;
            start = temp;
        }
    }

    void insert_before(int x, int y)
    {
        Node *temp = start;
        Node *prev;

        Node *new1 = new Node(y);

        if (start->getData() == x)
        {
            new1->link = start;
            start = new1;
        }

        else
        {
            while (temp != NULL)
            {
                if (temp->getData() == x)
                {
                    prev->link = new1;
                    new1->link = temp;
                }

                prev = temp;
                temp = temp->link;
            }
        }
    }

    void insert_after(int x, int y)
    {
        Node *temp = start;

        Node *new1 = new Node(y);

        while (temp != NULL)
        {
            if (temp->getData() == x)
            {
                new1->link = temp->link;
                temp->link = new1;

                if (temp == last)
                {
                    last = temp->link;
                }
                break;
            }

            temp = temp->link;
        }
    }

    void delete_at_kth_occurance(int val, int k)
    {
        if (start == NULL)
        {
            cout << "The list is Empty:" << endl;
            return;
        }
        else
        {

            Node *temp = start;
            Node *prev = NULL;
            int count = 0;

            while (temp != NULL)
            {

                if (temp->getData() == val)
                {
                    count++;
                    if (count == k)
                    {
                        if (prev == NULL)
                        {
                            start = start->link;
                            if (temp == last)
                            {
                                last = NULL;
                            }
                            delete temp;
                            break;
                        }

                        else
                        {
                            prev->link = temp->link;
                            if (temp == last)
                            {
                                last = prev;
                            }
                            delete temp;
                            break;
                        }
                    }
                }

                prev = temp;
                temp = temp->link;
            }

            if (count == 0)
            {
                cout << "Your given number is not present in the list:" << endl;
            }
        }
    }

    void delete_first_Occurance(int val)
    {
        if (start == NULL)
        {
            cout << "The list is empty:" << endl;
            return;
        }

        else
        {
            Node *temp = start;
            Node *prev = NULL;
            int count = 0;

            while (temp != NULL)
            {
                if (temp->getData() == val)
                {
                    count++;
                    if (prev == NULL && count == 1)
                    {
                        start = start->link;
                        if (temp == last)
                        {
                            last = NULL;
                        }

                        delete temp;
                        break;
                    }

                    if (count == 1)
                    {
                        prev->link = temp->link;

                        if (temp == last)
                        {
                            last = prev;
                        }
                        delete temp;
                        break;
                    }
                }

                prev = temp;
                temp = temp->link;
            }

            if (count == 0)
            {
                cout << "Your given number is not present in the list:" << endl;
            }
        }
    }

    void print_list()
    {
        if (start == NULL)
        {
            cout << "The list is empty:";
        }

        Node *temp;
        temp = start;

        while (temp != NULL)
        {
            cout << temp->getData();
            if (temp->link != NULL)
            {
                cout << "->";
            }

            temp = temp->link;
        }
    }

    void delete_all_Occurances(int x)
    {
        Node *temp = start;
        Node *prev = NULL;
        int count = 0;
        if (start == NULL)
        {
            cout << "The list is Empty:" << endl;
            return;
        }

        while (temp != NULL)
        {
            if (temp->getData() == x)
            {
                count++;
                if (prev == NULL)
                {
                    start = start->link;
                    if (temp == last)
                    {
                        last = NULL;
                    }
                    delete temp;
                    temp = start;
                }

                else
                {

                    prev->link = temp->link;
                    if (temp == last)
                    {
                        last = prev;
                    }
                    delete temp;
                    temp = prev->link;
                }
            }
            else
            {

                prev = temp;
                temp = temp->link;
            }
        }

        if (count == 0)
        {
            cout << "The Number is not present in the list:" << endl;
        }
    }

    void Reverse()
    {
        if (start == NULL)
        {
            cout << "The List is Empty:" << endl;
            return;
        }

        else
        {
            Node *prev = NULL;
            Node *temp = start;

            last = start;

            while (temp != NULL)
            {
                Node *next = temp->link;
                temp->link = prev;
                prev = temp;
                temp = next;
            }

            start = prev;
        }
    }

    void Print_Reverse()
    {
        Reverse();
        print_list();
        Reverse();
    }
};

int main()
{
    SLL list;
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
            list.delete_at_kth_occurance(value, k);
            break;

        case 6:
            cout << "Enter the value to delete first occurrence: ";
            cin >> value;
            list.delete_first_Occurance(value);
            break;

        case 7:
            cout << "Enter the value to delete all occurrences: ";
            cin >> value;
            list.delete_all_Occurances(value);
            break;

        case 8:
            list.Reverse();
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
