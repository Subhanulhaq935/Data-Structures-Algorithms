#include <iostream>
using namespace std;

int *findFirstAndLastPosition(int arr[], int n, int x)
{
    int first = -1;
    int last = -1;
    int i = 0;

    while (i < n)
    {
        if (arr[i] == x)
        {
            first = i;
            while (arr[i] == x)
            {
                i++;
            }
            last = i - 1;
            break;
        }

        i++;
    }

    int *temp = new int[2];
    temp[0] = first;
    temp[1] = last;

    return temp;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    int *result = findFirstAndLastPosition(arr, n, x);

    cout << "First position: " << result[0] << endl;
    cout << "Last position: " << result[1] << endl;
    
    delete[] result;

    return 0;
}
