#include <iostream>
#define MAX_SIZE 1000
using namespace std;

void selectionSort(int a[], int n);

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

        selectionSort(a, num);
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

void selectionSort(int a[], int n)
{
    int countComOps = 0;
    int countSwaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int jMin = i;

        for (int j = i + 1; j < n; j++)
        {
            countComOps += 1;
            if (a[j] < a[jMin])
                jMin = j;
        }
        if (jMin != i)
        {
            swap(a[jMin], a[i]);
            countSwaps += 1;
        }
    }

    cout << countComOps << " " << countSwaps;
}
