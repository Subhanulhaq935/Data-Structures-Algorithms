#include <iostream>
#include <queue>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }

    friend class Queue;
};

class Queue
{
    Node *front;
    Node *Rear;

public:
    Queue()
    {
        front = NULL;
        Rear = NULL;
    }

    ~Queue()
    {
        Node *temp = front;

        while (temp != NULL)
        {
            Node *t = temp->next;
            delete temp;
            temp = t;
        }
    }

    void Enqueue(int x)
    {
        if (Rear == NULL)
        {
            front = Rear = new Node(x);
        }

        else
        {
            Node *t = new Node(x);
            Rear->next = t;
            t->prev = Rear;
            Rear = t;
        }
    }

    void Dequeue()
    {
        if (front == NULL)
        {
            cout << "The List is Empty:";
            return;
        }

        if (front == Rear)
        {
            delete front;
            front = NULL;
            Rear = NULL;
        }

        else
        {
            Node *temp = front;

            front = front->next;
            delete temp;
            front->prev = NULL;
        }
    }

    void Add_Front(int x)
    {
        if (front == NULL)
        {
            front = new Node(x);
            Rear = front;
        }

        else
        {
            Node *t = new Node(x);
            t->next = front;
            front->prev = t;
            front = t;
        }
    }

    int Remove_Rear()
    {
        if (front == NULL)
        {
            cout << "The Queue is Empty:" << endl;
            return -1;
        }

        if (front == Rear)
        {
            int v;
            v = Rear->data;
            delete Rear;
            front = NULL;
            Rear = NULL;
            return v;
        }

        else
        {
            int v;
            Node *temp = front;

            while (temp->next != Rear)
            {
                temp = temp->next;
            }

            Node *t = Rear;
            v = Rear->data;
            Rear = temp;
            Rear->next = NULL;
            delete t;
            return v;
        }
    }

    int Peek_Front()
    {
        if (front == NULL)
        {
            cout << "The Queue is Empty:" << endl;
            return -1;
        }

        else
        {
            return front->data;
        }
    }

    int Peek_Rear()
    {
        if (front == NULL)
        {
            cout << "The Queue is Empty:" << endl;
            return -1;
        }

        else
        {
            return Rear->data;
        }
    }

    bool Is_Empty()
    {
        if (front == NULL)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    int Size()
    {
        int count = 0;
        Node *temp = front;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void Print_Queue()
    {
        if (front == NULL)
        {
            cout << "The list is Empty:";
            return;
        }

        else
        {
            Node *temp = front;

            while (temp != NULL)
            {
                cout << temp->data;

                if (temp != Rear)
                {
                    cout << "->";
                }
                temp = temp->next;
            }
        }

        cout << endl;
    }

    friend class Binary_Tree;
};

class Binary_Tree
{
    int *arr;
    int size;
    int count;

public:
    Binary_Tree(int s)
    {
        size = s;
        count = 1;
        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
    }

    ~Binary_Tree()
    {
        delete[] arr;
    }

    void insert(int x)
    {
        if (count >= size)
        {
            cout << "Tree is Full" << endl;
            return;
        }

        arr[count] = x;
        count++;
    }

    void insert_left_child(int parent, int left_child)
    {
        for (int i = 1; i < count; i++)
        {
            if (arr[i] == parent)
            {
                if (2 * i < size)
                {
                    arr[2 * i] = left_child;
                    count++;
                    return;
                }
                else
                {
                    cout << "No space for left child:" << endl;
                    return;
                }
            }
        }

        cout << "Parent is not found:" << endl;
    }

    void insert_right_child(int parent, int right_child)
    {
        for (int i = 1; i < count; i++)
        {
            if (arr[i] == parent)
            {
                if (2 * i + 1 < size)
                {
                    arr[2 * i + 1] = right_child;
                    count++;
                    return;
                }
                else
                {
                    cout << "No space for right child:" << endl;
                    return;
                }
            }
        }

        cout << "Parent is not found:" << endl;
    }

    int parent_of(int any_child)
    {
        for (int i = 1; i < count; i++)
        {
            if (arr[i] == any_child)
            {
                if (i / 2 < size && i / 2 > 0)
                {
                    return arr[i / 2];
                }
                else
                {
                    break;
                }
            }
        }

        cout << "No parent found:" << endl;
        return -1;
    }

    int get_right_child(int parent)
    {
        for (int i = 1; i < count; i++)
        {
            if (arr[i] == parent)
            {
                if (i * 2 + 1 < size && i * 2 + 1 > 0)
                {
                    return arr[i * 2 + 1];
                }
                else
                {
                    break;
                }
            }
        }

        cout << "No right child found:" << endl;
        return -1;
    }

    int get_left_child(int parent)
    {
        for (int i = 1; i < count; i++)
        {
            if (arr[i] == parent)
            {
                if (i * 2 < size && i * 2 > 0)
                {
                    return arr[i * 2];
                }
                else
                {
                    break;
                }
            }
        }

        cout << "No left child found:" << endl;
        return -1;
    }

    void editParent(int any_child, int new_Parent)
    {
        for (int i = 1; i < count; i++)
        {
            if (arr[i] == any_child)
            {
                if (i / 2 > 0)
                {
                    arr[i / 2] = new_Parent;
                    return;
                }
                else
                    break;
            }
        }
        cout << "No Parent exit" << endl;
    }

    void editLeftChild(int parent, int new_left_child)
    {
        for (int i = 1; i < count; i++)
        {
            if (arr[i] == parent)
            {
                if (2 * i < count)
                {
                    arr[2 * i] = new_left_child;
                    return;
                }
                else
                    break;
            }
        }
        cout << "No Left Child exit" << endl;
    }

    void editRightChild(int parent, int new_right_child)
    {
        for (int i = 1; i < count; i++)
        {
            if (arr[i] == parent)
            {
                if (2 * i + 1 < count)
                {
                    arr[2 * i + 1] = new_right_child;
                    return;
                }
                else
                    break;
            }
        }
        cout << "No Right Child exit" << endl;
    }

    bool isFull()
    {
        return count == size;
    }
};

int main()
{
    int treeSize;
    cout << "Enter the size of the binary tree: ";
    cin >> treeSize;

    if (treeSize <= 0)
    {
        cout << "Tree size must be greater than 0." << endl;
        return 1;
    }

    Binary_Tree tree(treeSize);

    Queue nodesQueue;

    int root;
    cout << "Enter the root node value: ";
    cin >> root;
    tree.insert(root);
    nodesQueue.Enqueue(root);

    while (!nodesQueue.Is_Empty())
    {
        if (tree.isFull())
        {
            cout << "The binary tree is full." << endl;
            break;
        }

        int parent = nodesQueue.Peek_Front();
        nodesQueue.Dequeue();

        int leftChild, rightChild;
        cout << "Enter the left child value of parent " << parent << ": ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            tree.insert_left_child(parent, leftChild);
            nodesQueue.Enqueue(leftChild);
        }

        cout << "Enter the right child value of parent " << parent << ": ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            tree.insert_right_child(parent, rightChild);
            nodesQueue.Enqueue(rightChild);
        }

        // Show the results
        cout << "Parent Node: " << parent << endl;
        cout << "Left Child: " << tree.get_left_child(parent) << endl;
        cout << "Right Child: " << tree.get_right_child(parent) << endl;
    }

    int c = tree.parent_of(2);
    cout << "The Parent of 2 is: " << c << endl;
    int d = tree.get_left_child(4);
    cout << "The left child of 4 is: " << d << endl;

    int e = tree.get_right_child(4);
    cout << "The Right child of 4 is: " << e << endl;
    int new_left_child;

    cout << "Enter the value for new Left child of 4: " << endl;
    cin >> new_left_child;

    tree.editLeftChild(4, new_left_child);

    int left = tree.get_left_child(4);
    cout << "The New left child of 4 is: " << left << endl;

    return 0;
}
