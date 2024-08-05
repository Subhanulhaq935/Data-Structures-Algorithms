#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(int arr[], int n, int target)
    {
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == target)
                return mid;

            if (arr[left] <= arr[mid])
            {
                if (arr[left] <= target && target <= arr[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (arr[mid] <= target && target <= arr[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};