#include <iostream>
#define MAX_SIZE 100
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

int MCSS(int a[], int left, int right)
{
    if (left == right)
        return a[left];
    int mid = (left + right) / 2;

    int leftMaxSum = 0, rightMaxSum = 0, thisSum = 0;
    for (int i = mid; i >= left; i--)
    {
        thisSum += a[i];
        leftMaxSum = MAX(leftMaxSum, thisSum);
    }

    thisSum = 0;
    for (int j = mid + 1; j <= right; j++)
    {
        thisSum += a[j];
        rightMaxSum = MAX(rightMaxSum, thisSum);
    }

    int single = MAX(MCSS(a, left, mid), MCSS(a, mid + 1, right));
    return MAX(leftMaxSum + rightMaxSum, single);
}

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];

        cin >> num;
        for (int j = 0; j < num; j++)
            cin >> a[j];
        if (MCSS(a, 0, num - 1) < 0)
            cout << 0 << endl;
        else
            cout << MCSS(a, 0, num - 1) << endl;
    }
    return 0;
}