#include <iostream>
using namespace std;

class Binary_Tree {
    int *arr;
    int size;
    int count;

public:
    Binary_Tree(int s) {
        size = s;
        count = 1;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = -1;
        }
    }

    ~Binary_Tree() {
        delete[] arr;
    }

    void insert(int x) {
        if (count >= size) {
            cout << "Tree is Full" << endl;
            return;
        }
        arr[count] = x;
        count++;
    }

    void insert_left_child(int parent, int left_child) {
        for (int i = 1; i < count; i++) {
            if (arr[i] == parent) {
                if (2 * i < size) {
                    arr[2 * i] = left_child;
                    count++;
                    return;
                } else {
                    cout << "No space for left child:" << endl;
                    return;
                }
            }
        }
        cout << "Parent not found:" << endl;
    }

    void insert_right_child(int parent, int right_child) {
        for (int i = 1; i < count; i++) {
            if (arr[i] == parent) {
                if (2 * i + 1 < size) {
                    arr[2 * i + 1] = right_child;
                    count++;
                    return;
                } else {
                    cout << "No space for right child:" << endl;
                    return;
                }
            }
        }
        cout << "Parent not found:" << endl;
    }

    void inOrder(int index) {
        if (index >= size || arr[index] == -1)
            return;
        
        inOrder(2 * index);
        cout << arr[index] << " ";
        inOrder(2 * index + 1);
    }

    void preOrder(int index) {
        if (index >= size || arr[index] == -1)
            return;
        
        cout << arr[index] << " ";
        preOrder(2 * index);
        preOrder(2 * index + 1);
    }

    void postOrder(int index) {
        if (index >= size || arr[index] == -1)
            return;
        
        postOrder(2 * index);
        postOrder(2 * index + 1);
        cout << arr[index] << " ";
    }

    void levelOrder() {
        if (arr[1] == -1) return;
        
        for (int i = 1; i < count; i++) {
            if (arr[i] != -1) {
                cout << arr[i] << " ";
            }
        }
    }
};

int main() {
    int treeSize = 15;
    Binary_Tree tree(treeSize);

    tree.insert(1);  // root = 1

    tree.insert_left_child(1, 2);  // left child of 1 = 2
    tree.insert_right_child(1, 3); // right child of 1 = 3

    tree.insert_left_child(2, 4);  // left child of 2 = 4
    tree.insert_right_child(2, 5); // right child of 2 = 5

    tree.insert_left_child(3, 6);  // left child of 3 = 6
    tree.insert_right_child(3, 7); // right child of 3 = 7

    cout << "In-Order Traversal: ";
    tree.inOrder(1);
    cout << endl;

    cout << "Pre-Order Traversal: ";
    tree.preOrder(1);
    cout << endl;

    cout << "Post-Order Traversal: ";
    tree.postOrder(1);
    cout << endl;

    cout << "Level-Order Traversal: ";
    tree.levelOrder();
    cout << endl;

    return 0;
}
