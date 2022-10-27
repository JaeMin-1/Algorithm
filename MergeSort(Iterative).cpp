#include <iostream>
#define MAX_SIZE 100
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
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
    {
        cnt++;
        if (tmp[i] <= tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }
    while (i <= mid)
        a[k++] = tmp[i++];
    while (j <= high)
        a[k++] = tmp[j++];
}

void mergeSortIterative(int v[], int n)
{
    int size = 1;
    while (size < n)
    {
        for (int i = 0; i < n; i += 2 * size)
        {
            int low = i;
            int mid = low + size - 1;
            int high = MIN(i + 2 * size - 1, n - 1);
            if (mid >= n - 1) // merge할 subarray가 1개일 경우
                break;
            merge(v, low, mid, high);
        }
        size *= 2;
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

        mergeSortIterative(a, num);
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}