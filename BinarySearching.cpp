#include <iostream>
#define MAX_SIZE 100
using namespace std;

int binarySearch(int a[], int left, int right, int value)
{
    int mid;
    if (left > right)
        return -1; /* not found */
    else
    {
        mid = (left + right) / 2;
        if (a[mid] == value)
            return mid;
        else if (a[mid] > value)
            return binarySearch(a, left, mid - 1, value);
        else
            return binarySearch(a, mid + 1, right, value);
    }
}

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num, k;
        int a[MAX_SIZE];

        cin >> num;
        cin >> k;
        for (int j = 0; j < num; j++)
            cin >> a[j];

        cout << binarySearch(a, 0, num - 1, k) << endl;
    }
    return 0;
}