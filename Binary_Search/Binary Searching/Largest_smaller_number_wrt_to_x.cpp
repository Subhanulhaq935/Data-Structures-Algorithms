#include <iostream>
using namespace std;

int solve(int arr[], int n, int x)
{
    int l = 0;
    int h = n - 1;
    int ans = -1;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] > x)
        {
            h = mid - 1;
        }

        else if (arr[mid] <= x)
        {
            ans = mid;
            l = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[7] = {1, 2, 8, 10, 11, 12, 19};
    int a = solve(arr, 7, 9);
    cout << a;
    return 0;
}