#include <iostream>
using namespace std;

int Search_insert(int arr[], int n, int x)
{
    int l = 0;
    int h = n - 1;

    if (arr[l] > x)
    {
        return l;
    }
    if (arr[h] < x)
    {
        return h + 1;
    }

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == x)
        {
            return mid;
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
    return l;
}

int main()
{
    int nums[9] = {1, 2 , 3, 4, 5, 6, 8, 9, 10};
    int c = Search_insert(nums, 10, 7);
    cout << c;
    return 0;
}
