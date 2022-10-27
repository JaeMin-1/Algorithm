#include <iostream>
#define MAX_SIZE 100
using namespace std;

int maxSubsequenceSum(int a[], int n, int *start, int *end)
{
    int i, j;
    int maxSum = 0, thisSum = 0;
    *start = *end = -1;
    for (i = 0, j = 0; j < n; j++)
    {
        thisSum += a[j];
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
            *start = i;
            *end = j;
        }
        else if (thisSum <= 0)
        {
            i = j + 1;
            thisSum = 0;
        }
    }
    cout << maxSum << " " << *start << " " << *end << endl;
}

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];

        int adr1;
        int adr2;

        cin >> num;
        for (int j = 0; j < num; j++)
            cin >> a[j];

        maxSubsequenceSum(a, num, &adr1, &adr2);
    }
    return 0;
}