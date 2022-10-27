#include <iostream>
#include <cmath>
#define MAX_SIZE 1000

using namespace std;
void combSort(int a[], int n);

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

        combSort(a, num);
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

void combSort(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    int gap = n;
    double shrink = 1.3;
    bool sorted = false;

    while (sorted == false)
    {
        gap = floor(gap / shrink);
        if (gap <= 1)
        {
            gap = 1;
            sorted = true;
        }

        int i = 0;
        while (i + gap < n)
        {
            countCmpOps += 1;
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                countSwaps += 1;
                sorted = false;
            }
            i = i + 1;
        }
    }

    cout << countCmpOps << " " << countSwaps;
}