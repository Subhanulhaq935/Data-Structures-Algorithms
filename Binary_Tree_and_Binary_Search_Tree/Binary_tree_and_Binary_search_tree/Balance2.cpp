#include <iostream>
#include <stack>
#include <cmath>
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

    int height_iterative(int index) {
        if (index >= size || arr[index] == -1) {
            return 0;
        }

        stack<int> s;
        int max_height = 0;

        s.push(index);
        s.push(1); // Push initial height

        while (!s.empty()) {
            int current_height = s.top();
            s.pop();
            int node = s.top();
            s.pop();

            if (node >= size || arr[node] == -1) {
                continue;
            }

            if (current_height > max_height) {
                max_height = current_height;
            }

            s.push(2 * node + 1); // right child
            s.push(current_height + 1);
            s.push(2 * node); // left child
            s.push(current_height + 1);
        }

        return max_height;
    }

    bool isBalanced_iterative(int index) {
        if (index >= size || arr[index] == -1) {
            return true;
        }

        stack<int> s;
        s.push(index);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (node >= size || arr[node] == -1) {
                continue;
            }

            int left_height = height_iterative(2 * node);
            int right_height = height_iterative(2 * node + 1);

            if (abs(left_height - right_height) > 1) {
                return false;
            }

            s.push(2 * node + 1); // right child
            s.push(2 * node); // left child
        }

        return true;
    }
};

int main() {
    int treeSize = 10;
    Binary_Tree tree(treeSize);

    tree.insert(1); // root = 1

    tree.insert_left_child(1, 2);  // left child of 1 = 2
    tree.insert_right_child(1, 2); // right child of 1 = 2

    tree.insert_left_child(2, 3);  // left child of 2 (left) = 3
    tree.insert_right_child(2, 3); // right child of 2 (right) = 3

    tree.insert_left_child(3, 4);  // left child of 3 (left) = 4
    tree.insert_right_child(3, 4); // right child of 3 (right) = 4

    if (tree.isBalanced_iterative(1)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
