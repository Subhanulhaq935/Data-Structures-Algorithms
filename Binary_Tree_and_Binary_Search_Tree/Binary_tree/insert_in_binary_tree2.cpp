#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node() : data(-1), left(NULL), right(NULL) {}

    Node(int x) : data(x), left(NULL), right(NULL) {}

    Node *getLeft()
    {
        return left;
    }

    Node *getRight()
    {
        return right;
    }

    int getData() // Method to get data of the node
    {
        return data;
    }

    friend class Tree;
};

class Tree
{
    Node *root;

public:
    Tree() : root(NULL) {}

    Node *getRoot()
    {
        return root;
    }

    Node *findNode(Node *node, int value)
    {
        if (node == NULL)
            return NULL;

        if (node->data == value)
            return node;

        Node *leftResult = findNode(node->left, value);
        if (leftResult != NULL)
            return leftResult;

        return findNode(node->right, value);
    }

    void insert(int x, Node *p, char pos)
    {
        Node *temp = new Node(x);

        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            if (p == NULL)
            {
                cout << "Parent is NULL:" << endl;
                return;
            }

            if (pos == 'L')
            {
                if (p->left != NULL)
                {
                    cout << "Left Node already exists." << endl;
                    return;
                }
                else
                {
                    p->left = temp;
                }
            }
            else if (pos == 'R')
            {
                if (p->right != NULL)
                {
                    cout << "Right Node already exists." << endl;
                    return;
                }
                else
                {
                    p->right = temp;
                }
            }
        }
    }

    void pre_Order(Node *r)
    {
        if (r == NULL)
            return;
        cout << r->data << ",";
        pre_Order(r->left);
        pre_Order(r->right);
    }

    void Pre_order()
    {
        pre_Order(root);
    }

    void in_order(Node *r)
    {
        if (r == NULL)
            return;
        in_order(r->left);
        cout << r->data << ",";
        in_order(r->right);
    }

    void IN_ORDER()
    {
        in_order(root);
    }

    void post_order(Node *r)
    {
        if (r == NULL)
            return;
        post_order(r->left);
        post_order(r->right);
        cout << r->data << ",";
    }

    void POST_ORDER()
    {
        post_order(root);
    }

    void print(Node *node, int depth = 0)
    {
        if (node == NULL)
            return;

        print(node->right, depth + 1);

        for (int i = 0; i < depth; ++i)
            cout << "\t";

        cout << node->data << endl;

        print(node->left, depth + 1);
    }
};

int main()
{
    Tree t;
    int value, parentValue;
    char pos;
    char choice;

    cout << "Enter the root node value: ";
    cin >> value;
    t.insert(value, NULL, 'L'); // Insert the root node

    do
    {
        cout << "Enter the parent node value: ";
        cin >> parentValue;

        Node *parentNode = t.findNode(t.getRoot(), parentValue); // Find the parent node

        if (parentNode == NULL)
        {
            cout << "Parent node not found!" << endl;
            continue;
        }

        cout << "Enter the value to insert: ";
        cin >> value;

        cout << "Enter position (L for left, R for right): ";
        cin >> pos;

        t.insert(value, parentNode, pos);

        cout << "Do you want to insert another node? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Print the tree structure
    cout << "Tree structure:" << endl;
    t.print(t.getRoot());

    cout << endl;

    cout << "Pre_Order is: ";
    t.Pre_order();

    cout << endl;

    cout << "In_Order is: ";
    t.IN_ORDER();

    cout << endl;

    cout << "Post_Order is: ";
    t.POST_ORDER();

    return 0; // Exit the program
}
