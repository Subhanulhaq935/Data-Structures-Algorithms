class Solution
{
public:
    int findMin(int *arr, int n)
    {

        int l = 0;
        int h = n - 1;
        int min = __INT16_MAX__;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arr[l] <= arr[mid])
            {
                if (arr[l] < min)
                {
                    min = arr[l];
                }
                l = mid + 1;
            }
            else
            {
                if (arr[mid] < min)
                {
                    min = arr[mid];
                }
                h = mid - 1;
            }
        }
        return min;
    }
};