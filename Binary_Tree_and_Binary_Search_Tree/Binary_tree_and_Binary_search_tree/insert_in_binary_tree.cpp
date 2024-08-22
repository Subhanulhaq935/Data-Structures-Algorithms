#include <iostream>
#include <queue>
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

    void Level_order(Node *r)
    {
        if (r == NULL)
            return;

        else
        {
            queue<Node *> q;
            q.push(r);
            while (!q.empty())
            {
                Node *temp = q.front();
                q.pop();

                cout << temp->data << ",";

                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
        }
    }

    void LEVEL_ORDER()
    {
        Level_order(root);
    }

    //     void print(Node *node, int depth = 0)
    // {
    //     if (node == NULL)
    //         return;

    // ! Print the current node with appropriate indentation
    //     for (int i = 0; i < depth; ++i)
    //         cout << "\t";

    //     cout << node->data << endl;

    //    ! Recur for the left and right children
    //     print(node->left, depth + 1);
    //     print(node->right, depth + 1);
    // }
};

int main()
{
    Tree t; // !Create a Tree object

    //  !Insert the root node with value 1
    t.insert(1, NULL, 'L');

    // !Insert the left child (2) and right child (3) of the root node
    t.insert(2, t.getRoot(), 'L'); // !Insert 2 as the left child of the root
    t.insert(3, t.getRoot(), 'R'); // !Insert 3 as the right child of the root

    // !Insert children for node 2
    t.insert(4, t.getRoot()->getLeft(), 'L'); // !Insert 4 as the left child of node 2
    t.insert(5, t.getRoot()->getLeft(), 'R'); // !Insert 5 as the right child of node 2

    // !Insert children for node 3
    t.insert(6, t.getRoot()->getRight(), 'L'); // !Insert 6 as the left child of node 3
    t.insert(7, t.getRoot()->getRight(), 'R'); // !Insert 7 as the right child of node 3

    // !Insert children for node 4
    t.insert(8, t.getRoot()->getLeft()->getLeft(), 'L'); // !Insert 8 as the left child of node 4
    t.insert(9, t.getRoot()->getLeft()->getLeft(), 'R'); // !Insert 9 as the right child of node 4

    // !Insert children for node 5
    t.insert(10, t.getRoot()->getLeft()->getRight(), 'L'); // !Insert 10 as the left child of node 5
    t.insert(11, t.getRoot()->getLeft()->getRight(), 'R'); // !Insert 11 as the right child of node 5

    // !Insert children for node 6
    t.insert(12, t.getRoot()->getRight()->getLeft(), 'L'); // !Insert 12 as the left child of node 6
    t.insert(13, t.getRoot()->getRight()->getLeft(), 'R'); // !Insert 13 as the right child of node 6

    // !Insert children for node 7
    t.insert(14, t.getRoot()->getRight()->getRight(), 'L'); // !Insert 14 as the left child of node 7
    t.insert(15, t.getRoot()->getRight()->getRight(), 'R'); // !Insert 15 as the right child of node 7

    // !Print the tree structure
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

    cout << endl;
    cout << "Level_Order is: ";
    t.LEVEL_ORDER();

    return 0; // Exit the program
}
