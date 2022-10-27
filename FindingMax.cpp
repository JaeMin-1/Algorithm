#include <iostream>
#define MAX_SIZE 100
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
using namespace std;

int recurMax(int a[], int left, int right)
{
    int half;
    if (left == right)
        return a[left];
    else
    {
        half = (left + right) / 2;
        return MAX(recurMax(a, left, half),
                   recurMax(a, half + 1, right));
    }
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

        int ac = recurMax(a, 0, num - 1);
        for (int k = 0; k < num; k++)
        {
            if (a[k] == ac)
            {
                a[k] == 0;
                break;
            }
        }

        cout << recurMax(a, 0, num - 1) << endl;
    }
    return 0;
}