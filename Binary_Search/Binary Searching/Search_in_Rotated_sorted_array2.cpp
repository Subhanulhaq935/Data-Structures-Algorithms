class Solution
{
public:
    bool search(int arr[], int n, int target)
    {
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == target)
                return true;

            if (arr[left] == arr[mid] && arr[mid] == arr[right])
            {
                left++;
                right--;
                continue;
            }

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
        return false;
    }
};