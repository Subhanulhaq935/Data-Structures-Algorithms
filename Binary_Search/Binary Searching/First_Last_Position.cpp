#include <iostream>
using namespace std;

int first_position(int *arr, int n, int x)
{
    int l = 0;
    int h = n - 1;
    int first = -1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] == x)
        {
            first = mid;
            h = mid - 1;
        }

        else if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return first;
}

int last_position(int *arr, int n, int x)
{
    int l = 0;
    int h = n - 1;
    int last = -1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] == x)
        {
            last = mid;
            l = mid + 1;
        }

        else if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return last;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    int first = first_position(arr, n, 6);
    int last = last_position(arr, n, 6);

    cout<<"First Position is: "<<first <<" "<<"and " <<"Last position is: "<<last<<endl;
    return 0;
}
