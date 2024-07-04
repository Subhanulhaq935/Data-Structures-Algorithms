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
            if (nextNode == first)
                break;
            temp = nextNode;
        }

        first = NULL;
        last = NULL;
    }

    void insert_at_start(int x)
    {
        if (first == NULL)
        {
            first = new Node(x);
            last = first;
            last->next = last->prev = first;
        }

        Node *t = new Node(x);
        t->next = first;
        first->prev = t;
        t->prev = last;
        last->next = t;
        first = t;
    }

    void insert_at_end(int x)
    {
        Node *t = new Node(x);
        if (first == nullptr)
        {
            first = t;
            last = t;
            first->next = first;
            first->prev = first;
        }
        else
        {
            t->next = first;
            t->prev = last;
            last->next = t;
            first->prev = t;
            last = t;
        }
    }

    void insert_before(int x, int y)
    {
        Node *t = new Node(y);

        Node *temp = first;
        Node *pre = NULL;

        if (first->data == x)
        {
            t->next = first;
            first->prev = t;
            t->prev = last;
            last->next = t;
            first = t;
            return;
        }

        while (temp->next != first)
        {
            if (temp->data == x)
            {
                pre->next = t;
                t->prev = pre;
                t->next = temp;
                temp->prev = t;
                break;
            }

            pre = temp;
            temp = temp->next;
        }

        if (temp->data == x)
        {
            pre->next = t;
            t->prev = pre;
            t->next = temp;
            temp->prev = t;
            return;
        }
    }

    void insert_after(int x, int y)
    {
        Node *t = new Node(y);
        Node *temp = first;

        if (first == NULL)
        {
            // cout << "The list is Empty:" << endl;
            delete t;
            return;
        }

        while (true)
        {
            if (temp->data == x)
            {
                t->next = temp->next;
                t->prev = temp;
                temp->next->prev = t;
                temp->next = t;

                if (temp == last)
                {
                    last = t;
                }

                break;
                ;
            }

            temp = temp->next;

            if (temp == first)
            {
                cout << "Node with value " << x << " not found." << endl;
                delete t;
                return;
            }
        }
    }

    void sorted_insertion_Ascending(int x)
    {
        Node *temp = new Node(x);

        if (first == NULL)
        {
            first = last = temp;
            first->prev = last->next = first;
        }

        else if (x < first->data)
        {
            temp->next = first;
            first->prev = temp;
            temp->prev = last;
            last->next = temp;
            first = temp;
        }

        else if (x > last->data)
        {
            last->next = temp;
            temp->prev = last;
            temp->next = first;
            first->prev = last;
            last = temp;
        }

        else
        {
            Node *t = first;
            while (t->data < x)
            {
                t = t->next;
            }
            temp->next = t;
            temp->prev = t->prev;
            t->prev->next = temp;
            t->prev = temp;
        }
    }

    void sorted_insertion_Decending(int x)
    {
        Node *temp = new Node(x);

        if (first == NULL)
        {
            first = last = temp;
            first->prev = last->next = first;
        }

        else if (x > first->data)
        {
            temp->next = first;
            first->prev = temp;
            temp->prev = last;
            last->next = temp;
            first = temp;
        }

        else if (x < last->data)
        {
            last->next = temp;
            temp->prev = last;
            temp->next = first;
            first->prev = last;
            last = temp;
        }

        else
        {
            Node *t = first;
            while (t->data > x)
            {
                t = t->next;
            }
            temp->next = t;
            temp->prev = t->prev;
            t->prev->next = temp;
            t->prev = temp;
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

            while (1)
            {
                cout << temp->data;
                if (temp->next != first)
                {
                    cout << "->";
                }

                if (temp->next == first)
                    return;

                temp = temp->next;
            }
        }
    }

    void delete_first()
    {
        if (first == NULL)
        {
            return;
        }

        else
        {
            if (first == last)
            {
                delete first;
                first = NULL;
                return;
            }

            else
            {
                Node *temp;
                temp = first;

                first = first->next;
                delete temp;
                first->prev = last;
                last->next = first;
            }
        }
    }

    void delete_End()
    {
        if (first == NULL)
        {
            return;
        }

        if (first == last)
        {
            delete first;
            first = NULL;
            return;
        }

        else
        {
            Node *temp = last;
            last = last->prev;

            delete temp;
            last->next = first;
            first->prev = last;
        }
    }

    void Delete_kth_Node(int x)
    {
        if (first == NULL)
        {
            return;
        }

        Node *temp = first;
        int count = 1;

        while (temp->next != first)
        {
            if (count == x)
            {
                if (temp == first)
                {

                    first = first->next;
                    delete temp;
                    first->prev = last;
                    last->next = first;
                    break;
                }

                else if (temp == last)
                {
                    last = last->prev;
                    delete temp;
                    last->next = first;
                    first->prev = last;
                    break;
                }

                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    break;
                }
            }

            else
            {

                temp = temp->next;
                count++;
            }
        }
    }

    void delete_first_Occurance(int x)
    {

        if (first == NULL)
        {
            return;
        }

        Node *temp = first;
        int count = 1;

        while (temp->next != NULL)
        {
            if (temp->data == x && count == 1)
            {
                if (first == last)
                {
                    delete first;
                    first = last = NULL;
                    break;
                }
                else if (temp == first)
                {
                    first = first->next;
                    delete temp;
                    first->prev = last;
                    last->next = first;
                    break;
                }

                else if (temp == last)
                {
                    last = last->prev;
                    delete temp;
                    last->next = first;
                    first->prev = last;
                    break;
                }

                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    break;
                }
            }

            else
            {
                temp = temp->next;
            }
        }
    }

    void delete_all_Occurance(int x)
    {
        if (first == nullptr)
        {
            return;
        }

        Node *temp = first;
        Node *pre = nullptr;
        int count = 0;

        if (temp == first && temp == last && temp->data == x)
        {
            delete temp;
            first = last = nullptr;
            count++;
            return;
        }

        while (1)
        {
            if (temp->data == x)
            {
                count++;
                if (temp == first)
                {
                    first = first->next;
                    first->prev = last;
                    last->next = first;
                    delete temp;
                    temp = first;
                }
                else if (temp == last)
                {
                    last = last->prev;
                    last->next = first;
                    first->prev = last;
                    delete temp;
                    temp = first;
                }
                else
                {
                    pre->next = temp->next;
                    temp->next->prev = pre;
                    Node *to_delete = temp;
                    temp = temp->next;
                    delete to_delete;
                }
            }
            else
            {
                pre = temp;
                if (temp->next == first)
                    return;
                temp = temp->next;
            }
        }
    }

    void delete_kth_Occurance(int x, int k)
    {
        if (first == nullptr)
        {
            return;
        }

        Node *temp = first;
        Node *pre = nullptr;
        int count = 0;

        while (1)
        {
            if (temp->data == x)
            {
                count++;
                if (count == k)
                {
                    if (temp = last)
                    {
                        delete first;
                        first = last = NULL;
                        break;
                    }
                    else if (temp == first)
                    {
                        first = first->next;
                        first->prev = last;
                        last->next = first;
                        delete temp;
                        return;
                    }
                    else if (temp == last)
                    {
                        last = last->prev;
                        last->next = first;
                        first->prev = last;
                        delete temp;
                        return;
                    }
                    else
                    {
                        pre->next = temp->next;
                        temp->next->prev = pre;
                        delete temp;
                        return;
                    }
                }
            }
            pre = temp;
            if (temp->next == first)
                return;
            temp = temp->next;
        }
    }
};

int main()
{
    DLL list;
    int choice, value, position;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at start\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before\n";
        cout << "4. Insert after\n";
        cout << "5. Sorted insertion (ascending)\n";
        cout << "6. Sorted insertion (descending)\n";
        cout << "7. Delete first\n";
        cout << "8. Delete end\n";
        cout << "9. Delete kth node\n";
        cout << "10. Delete first occurrence\n";
        cout << "11. Delete all occurrences\n";
        cout << "12. Delete kth occurrence\n";
        cout << "13. Print list\n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at start: ";
            cin >> value;
            list.insert_at_start(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insert_at_end(value);
            break;
        case 3:
            cout << "Enter value to insert before: ";
            cin >> value;
            cout << "Enter the node value to insert before: ";
            cin >> position;
            list.insert_before(position, value);
            break;
        case 4:
            cout << "Enter value to insert after: ";
            cin >> value;
            cout << "Enter the node value to insert after: ";
            cin >> position;
            list.insert_after(position, value);
            break;
        case 5:
            cout << "Enter value for sorted insertion (ascending): ";
            cin >> value;
            list.sorted_insertion_Ascending(value);
            break;
        case 6:
            cout << "Enter value for sorted insertion (descending): ";
            cin >> value;
            list.sorted_insertion_Decending(value);
            break;
        case 7:
            list.delete_first();
            break;
        case 8:
            list.delete_End();
            break;
        case 9:
            cout << "Enter the kth position to delete: ";
            cin >> position;
            list.Delete_kth_Node(position);
            break;
        case 10:
            cout << "Enter value to delete first occurrence: ";
            cin >> value;
            list.delete_first_Occurance(value);
            break;
        case 11:
            cout << "Enter value to delete all occurrences: ";
            cin >> value;
            list.delete_all_Occurance(value);
            break;
        case 12:
            cout << "Enter value to delete kth occurrence: ";
            cin >> value;
            cout << "Enter the occurrence number (k): ";
            cin >> position;
            list.delete_kth_Occurance(value, position);
            break;
        case 13:
            list.print_list();
            cout << endl;
            break;
        case 14:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}