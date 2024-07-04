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
        }

        else
        {
            Node *temp;
            temp = start;

            while (temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = new Node(x);
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

    void insert_at_start(int x)
    {
        Node *temp;
        temp = new Node(x);
        temp->link = start;
        start = temp;
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
            }

            temp = temp->link;
        }
    }

    string is_empty()
    {
        if (start == NULL)
        {
            cout << "The list is empty:" << endl;
        }

        else
        {
            cout << "The list is not empty and contain the following elements:" << endl;
            print_list();
        }
    }

    Node *search(int x)
    {
        Node *temp = start;

        while (temp != NULL)
        {
            if (temp->getData() == x)
            {
                return temp;
            }

            temp = temp->link;
        }

        return NULL;
    }

    void delete_start()
    {
        if (start == NULL)
        {
            cout << "There is nothing to delete:" << endl;
            return;
        }

        else
        {
            Node *temp = start;
            start = start->link;
            delete temp;
        }
    }

    void delete_end()
    {
        if (start == NULL)
        {
            cout << "There is nothing to delete:" << endl;
            return;
        }

        if (start->link == NULL)
        {
            delete start;
            start = NULL;
        }

        else
        {
            Node *temp = start;
            Node *prev = NULL;

            while (temp->link != NULL)
            {
                prev = temp;
                temp = temp->link;
            }

            delete temp;
            prev->link = NULL;
        }
    }

    void delete_at_specific_position(int x)
    {
        if (start == NULL)
        {
            cout << "The List is Empty:" << endl;
        }

        if (start->getData() == x)
        {
            delete start;
            start = NULL;
        }

        else
        {
            Node *temp = start;
            Node *prev = NULL;

            while (temp->getData() != x)
            {
                prev = temp;
                temp = temp->link;
            }

            prev->link = temp->link;
            delete temp;
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
                            delete temp;
                            break;
                        }

                        else
                        {
                            prev->link = temp->link;
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

                        delete temp;
                        break;
                    }

                    if (count == 1)
                    {
                        prev->link = temp->link;
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
                    delete temp;
                    temp = start;
                }

                else
                {

                    prev->link = temp->link;
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

    void Reverse_list()
    {
        if (start == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        else
        {
            Node *prev = NULL;
            Node *temp = start;

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
        Reverse_list();
        print_list();
        Reverse_list();
    }
};

int main()
{
    SLL list1;
    int choice, value, afterValue, beforeValue, k;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at start\n";
        cout << "3. Insert after a value\n";
        cout << "4. Insert before a value\n";
        cout << "5. Delete start element\n";
        cout << "6. Delete end element\n";
        cout << "7. Delete specific position\n";
        cout << "8. Delete kth occurrence\n";
        cout << "9. Delete first occurrence\n";
        cout << "10. Delete all occurrences\n";
        cout << "11. Reverse list\n";
        cout << "12. Print list\n";
        cout << "13. Check if list is empty\n";
        cout << "14. Search for a value\n";
        cout << "15. Print Reverse\n";
        cout << "16. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list1.insert_at_end(value);
            break;

        case 2:
            cout << "Enter value to insert at start: ";
            cin >> value;
            list1.insert_at_start(value);
            break;

        case 3:
            cout << "Enter the value to insert after: ";
            cin >> afterValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            list1.insert_after(afterValue, value);
            break;

        case 4:
            cout << "Enter the value to insert before: ";
            cin >> beforeValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            list1.insert_before(beforeValue, value);
            break;

        case 5:
            list1.delete_start();
            break;

        case 6:
            list1.delete_end();
            break;

        case 7:
            cout << "Enter the value to delete: ";
            cin >> value;
            list1.delete_at_specific_position(value);
            break;

        case 8:
            cout << "Enter the value to delete: ";
            cin >> value;
            cout << "Enter the occurrence number: ";
            cin >> k;
            list1.delete_at_kth_occurance(value, k);
            break;

        case 9:
            cout << "Enter the value to delete: ";
            cin >> value;
            list1.delete_first_Occurance(value);
            break;

        case 10:
            cout << "Enter the value to delete all occurrences: ";
            cin >> value;
            list1.delete_all_Occurances(value);
            break;

        case 11:
            list1.Reverse_list();
            break;

        case 12:
            list1.print_list();
            break;

        case 13:
            list1.is_empty();
            break;

        case 14:
            cout << "Enter the value to search: ";
            cin >> value;
            if (list1.search(value))
            {
                cout << "Value " << value << " found in the list." << endl;
            }
            else
            {
                cout << "Value " << value << " not found in the list." << endl;
            }
            break;

        case 15:
            list1.Print_Reverse();
            break;

        case 16:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
