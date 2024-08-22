#include <iostream>
using namespace std;

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
        cout << "Parent not found:" << endl;
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
        cout << "Parent not found:" << endl;
    }

    int height(int index)
    {
        if (index >= size || arr[index] == -1)
        {
            return 0;
        }
        int left_height = height(2 * index);
        int right_height = height(2 * index + 1);

        int max_height;
        if (left_height > right_height)
        {
            max_height = left_height;
        }
        else
        {
            max_height = right_height;
        }

        return max_height + 1;
    }

    bool isBalanced(int index)
    {
        if (index >= size || arr[index] == -1)
        {
            return true;
        }
        int left_height = height(2 * index);
        int right_height = height(2 * index + 1);

        if (left_height - right_height > 1 || right_height - left_height > 1)
        {
            return false;
        }

        if (!isBalanced(2 * index) || !isBalanced(2 * index + 1))
        {
            return false;
        }

        return true;
    }
};

int main()
{
    int treeSize = 10;
    Binary_Tree tree(treeSize);

    tree.insert(1); // root = 1

    tree.insert_left_child(1, 2);  // left child of 1 = 2
    tree.insert_right_child(1, 2); // right child of 1 = 2

    tree.insert_left_child(2, 3);  // left child of 2 (left) = 3
    tree.insert_right_child(2, 3); // right child of 2 (right) = 3

    tree.insert_left_child(3, 4);  // left child of 3 (left) = 4
    tree.insert_right_child(3, 4); // right child of 3 (right) = 4

    if (tree.isBalanced(1))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}



// Height Calculation:
// Height Calculation for Node 1 (Index 1):

// Left Subtree (Index 2):

// Height Calculation for Node 2 (Index 2):
// Left Subtree (Index 4):
// Height Calculation for Node 3 (Index 4):
// Left Subtree (Index 8):
// Contains 4 (Leaf Node), so height is 1.
// Right Subtree (Index 9):
// Empty (-1), so height is 0.
// Height of Node 3 at Index 4 is 2 (max(1, 0) + 1).
// Right Subtree (Index 5):
// Empty (-1), so height is 0.
// Height of Node 2 at Index 2 is 3 (max(2, 0) + 1).
// Right Subtree (Index 3):

// Height Calculation for Node 2 (Index 3):
// Left Subtree (Index 6):
// Empty (-1), so height is 0.
// Right Subtree (Index 7):
// Height Calculation for Node 3 (Index 7):
// Left Subtree (Index 14):
// Empty (-1), so height is 0.
// Right Subtree (Index 15):
// Empty (-1), so height is 0.
// Height of Node 3 at Index 7 is 1 (max(0, 0) + 1).
// Height of Node 2 at Index 3 is 2 (max(0, 1) + 1).
// Overall Height of Tree from Node 1:

// Left subtree height is 3.
// Right subtree height is 2.
// Height difference is 1 (3 - 2), which is within the acceptable range for balance.
// Balance Check:

// For the balance check, the heights of the left and right subtrees are compared at each node.

// For Node 1 (Index 1):

// Left Height: 3
// Right Height: 2
// Difference: 1 (within the acceptable range).
// For Node 2 (Index 2):

// Left Height: 2
// Right Height: 0
// Difference: 2 (outside the acceptable range, making this subtree unbalanced).
// Final Balance Check:
// Although Node 1 passes the balance check, Node 2 at Index 2 fails the balance check because the difference in height between its subtrees is 2, which is greater than 1.

// Conclusion:
// The tree is not balanced because one of its subtrees (Node 2 at Index 2) is unbalanced. Therefore, the output should be: "The tree is not balanced."