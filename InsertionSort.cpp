#include <iostream>
#define MAX_SIZE 1000
using namespace std;

void insertionSort(int a[], int n);

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

        insertionSort(a, num);
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

void insertionSort(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (a[j - 1] > a[j])
            {
                countCmpOps += 1;
                swap(a[j - 1], a[j]);
                countSwaps += 1;
            }
            else
            {
                countCmpOps += 1;
                break;
            }
        }
    }

    cout << countCmpOps << " " << countSwaps;
}