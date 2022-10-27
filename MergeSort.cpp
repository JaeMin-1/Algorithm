#include <iostream>
#define MAX_SIZE 100
using namespace std;
int cnt = 0;

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[MAX_SIZE];
    for (i = low; i <= high; i++)
        tmp[i] = a[i];
    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
        if (tmp[i] <= tmp[j])
        {
            a[k++] = tmp[i++];
            cnt++;
        }
        else
        {
            a[k++] = tmp[j++];
            cnt++;
        }
    while (i <= mid)
        a[k++] = tmp[i++];
    while (j <= high)
        a[k++] = tmp[j++];
}

void mergeSort(int v[], int low, int high)
{

    int mid;
    if (low == high)
        return; /* base case */
    mid = (low + high) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
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

        mergeSort(a, 0, num - 1);
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}