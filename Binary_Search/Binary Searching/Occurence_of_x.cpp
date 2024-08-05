#include <iostream>
using namespace std;

int count(int arr[], int n, int x)
{
    int i = 0;
    int count = 0;
    while(i < n)
    {
        if(arr[i] == x)
        {
            while(arr[i] == x)
            {
                count++;
                i++;
            }

            break;
        }
        else
        {
            i++;
        }
    }
    return count;
}

int main()
{
    int arr[7] = {1, 1, 2, 2, 2, 2, 3};
    int c = count(arr, 7, 5);
    cout << c;

    return 0;
}