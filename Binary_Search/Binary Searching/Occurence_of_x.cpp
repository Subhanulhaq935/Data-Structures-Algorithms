#include <iostream>
#include <vector>
using namespace std;

int first_position(const vector<int> &arr, int n, int x)
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

int last_position(const vector<int> &arr, int n, int x)
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

int count_Occurances(const vector<int> arr, int n, int x)
{
    int first = first_position(arr, n, x);
    int last = last_position(arr, n, x);
    int count = last - first + 1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 6, 6, 6, 6};
    int n = arr.size();
    int x = 4;

    int first = first_position(arr, n, 6);
    int last = last_position(arr, n, 6);

    cout << "First Position is: " << first << " " << "and " << "Lasۨt position is: " << last << endl;
    int c = count_Occurances(arr, n, 6);
    cout << "Occurances of 6 is: " << c;

    return 0;
}
