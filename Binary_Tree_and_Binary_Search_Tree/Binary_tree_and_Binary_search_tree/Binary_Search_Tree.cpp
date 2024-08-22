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

    // ! 3 Different methods of Insertion:

    // Insert method to add a node to the tree
    // void insert(int value)
    // {
    //     if (root == NULL)
    //     {
    //         root = new Node(value);
    //     }
    //     else
    //     {
    //         Node *curr = root;
    //         while (true)
    //         {
    //             if (value <= curr->data)
    //             {
    //                 if (curr->left != NULL)
    //                     curr = curr->left;
    //                 else
    //                 {
    //                     curr->left = new Node(value);
    //                     break;
    //                 }
    //             }
    //             else
    //             {
    //                 if (curr->right != NULL)
    //                     curr = curr->right;
    //                 else
    //                 {
    //                     curr->right = new Node(value);
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }

    // Node *Insert(Node *r, int value)
    // {
    //     if (r == NULL)
    //     {
    //         return new Node(value);
    //     }
    //     else
    //     {
    //         Node *curr = r;
    //         while (true)
    //         {
    //             if (value <= curr->data)
    //             {
    //                 if (curr->left != NULL)
    //                     curr = curr->left;
    //                 else
    //                 {
    //                     curr->left = new Node(value);
    //                     break;
    //                 }
    //             }
    //             else
    //             {
    //                 if (curr->right != NULL)
    //                     curr = curr->right;
    //                 else
    //                 {
    //                     curr->right = new Node(value);
    //                     break;
    //                 }
    //             }
    //         }

    //         return r;
    //     }
    // }

    Node *Insert(Node *r, int value)
    {
        if (r == NULL)
        {
            return new Node(value);
        }

        if (value <= r->data)
        {
            r->left = Insert(r->left, value);
        }

        else
        {
            r->right = Insert(r->right, value);
        }

        return r;
    }

    void insert(int value)
    {
        root = Insert(root, value);
    }

    // Print the tree in a structured format
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

    Node *search(Node *r, int value)
    {
        while (r != NULL && r->data != value)
        {
            if (value > r->data)
                r = r->right;
            else
            {
                r = r->left;
            }
        }
        return r;
    }

    Node *del(Node *r, int value)
    {
        if (r == NULL)
            return NULL;
        else if (r->data == value)
            return helper(r);

        Node *dummy = r;
        while (r != NULL)
        {
            if (r->data > value)
            {
                if (r->left != NULL && r->left->data == value)
                {
                    r->left = helper(r->left);
                    break;
                }
                else
                {
                    r = r->left;
                }
            }

            else
            {
                if (r->right != NULL && r->right->data == value)
                {
                    r->right = helper(r->right);
                    break;
                }
                else
                {
                    r = r->right;
                }
            }
        }

        return dummy;
    }

    Node *helper(Node *r)
    {
        if (r->right == NULL)
            return r->left;
        else if (r->left == NULL)
            return r->right;

        else
        {
            Node *rightchild = r->right;
            Node *lastright = findlastright(r->left);
            lastright->right = rightchild;
            return r->left;
        }
    }

    Node *findlastright(Node *r)
    {
        if (r->right == NULL)
            return r;
        findlastright(r->right);
    }
};

int main()
{
    Tree t;
    int rootValue;

    cout << "Enter the root value: ";
    cin >> rootValue;

    // !Insert the root value
    t.insert(rootValue);

    int value;
    while (true)
    {
        cout << "Enter a value to insert into the tree (-43 to exit): ";
        cin >> value;
        if (value == -43)
            break;
        t.insert(value);
    }

    // !Print the tree structure
    cout << "Tree structure:" << endl;
    t.print(t.getRoot());

    cout << "Preorder Traversal: ";
    t.Pre_order();
    cout << endl;

    cout << "Inorder Traversal: ";
    t.IN_ORDER();
    cout << endl;

    // !Searching for a value in the tree
    cout << "Enter the value to search: ";
    int v;
    cin >> v;

    Node *sear = t.search(t.getRoot(), v);
    if (sear != NULL)
    {
        cout << "Value is Found" << endl;
    }
    else
    {
        cout << "Value is Not Found" << endl;
    }

    // !Deleting a value from the tree
    cout << "Enter the value to be deleted: ";
    int delValue;
    cin >> delValue;

    t.del(t.getRoot(), delValue);

    // !Print the tree structure after deletion
    cout << "Tree structure after deletion:" << endl;
    t.print(t.getRoot());

    cout << "Inorder Traversal after the deletion is: ";
    t.IN_ORDER();
    cout << endl;

    return 0;
}
