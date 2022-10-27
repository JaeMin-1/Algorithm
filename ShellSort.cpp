#include <iostream>
#define MAX_SIZE 1000
using namespace std;

void ShellSort(int a[], int n);

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

        ShellSort(a, num);
        cout << endl;
    }

    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void ShellSort(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    int shrinkRatio = 2;
    int gap = n / shrinkRatio;

    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = a[i];
            for (int j = i; j >= gap; j -= gap)
            {
                if (a[j - gap] > tmp)
                {
                    countCmpOps += 1;
                    swap(a[j - gap], a[j]);
                    countSwaps += 1;
                    tmp = a[j - gap];
                }
                else
                {
                    countCmpOps += 1;
                    break;
                }
            }
        }
        gap /= shrinkRatio;
    }

    cout << countCmpOps << " " << countSwaps;
}