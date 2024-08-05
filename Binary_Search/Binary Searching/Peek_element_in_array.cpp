#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int n = arr.size();
        int l = 0;
        int h = n - 1;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (mid > 0 && mid < n - 1)
            {
                if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                {
                    return mid;
                }
                else if (arr[mid] < arr[mid - 1])
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (mid == 0)
            {
                if (arr[mid] > arr[mid + 1])
                {
                    return mid;
                }
                else
                {
                    return mid + 1;
                }
            }
            else if (mid == n - 1)
            {
                if (arr[mid] > arr[mid - 1])
                {
                    return mid;
                }
                else
                {
                    return mid - 1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution solution;

    // Test case
    vector<int> arr = {1, 2};
    int peakIndex = solution.findPeakElement(arr);

    cout << "The peak element is at index: " << peakIndex << endl;
    cout << "The peak element is: " << arr[peakIndex] << endl;

    return 0;
}
