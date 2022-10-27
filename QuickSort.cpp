#include <iostream>
#define MAX_SIZE 1001
using namespace std;

int cnt_com_Hoare = 0;
int cnt_swap_Hoare = 0;
int cnt_com_Romuto = 0;
int cnt_swap_Romuto = 0;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition_Hoare(int a[], int low, int high)
{
    int i, j;
    int pivot;
    pivot = a[low];
    i = low - 1;
    j = high + 1;
    while (true)
    {
        // move index markers i,j toward center
        // until we find a pair of mis-partitioned elements
        cnt_com_Hoare++;
        while (a[++i] < pivot)
            cnt_com_Hoare++;
        cnt_com_Hoare++;
        while (a[--j] > pivot)
            cnt_com_Hoare++;
        if (i < j)
        {
            swap(a[i], a[j]);
            cnt_swap_Hoare++;
        }
        else
            return j;
    }
}

int partition_Romuto(int a[], int low, int high)
{
    int i, j;
    int pivot, pivotPos, tmp;
    pivot = a[low];
    j = low;
    for (i = low + 1; i <= high; i++)
    {
        cnt_com_Romuto++;
        if (a[i] < pivot)
        {
            j++;
            /* swap */
            swap(a[i], a[j]);
            cnt_swap_Romuto++;
        }
    }
    pivotPos = j;
    /* swap */
    swap(a[pivotPos], a[low]);
    cnt_swap_Romuto++;
    return pivotPos;
}

void quickSort_Hoare(int v[], int low, int high)
{
    int pivotPos;
    if (high > low)
    {
        pivotPos = partition_Hoare(v, low, high);
        quickSort_Hoare(v, low, pivotPos);
        quickSort_Hoare(v, pivotPos + 1, high);
    }
}

void quickSort_Romuto(int v[], int low, int high)
{
    int pivotPos;
    if (high > low)
    {
        pivotPos = partition_Romuto(v, low, high);
        quickSort_Romuto(v, low, pivotPos - 1);
        quickSort_Romuto(v, pivotPos + 1, high);
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
        int b[MAX_SIZE];

        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> a[j];
            b[j] = a[j];
        }

        quickSort_Hoare(a, 0, num - 1);
        quickSort_Romuto(b, 0, num - 1);
        cout << cnt_swap_Hoare << " " << cnt_swap_Romuto << " " << cnt_com_Hoare << " " << cnt_com_Romuto << endl;
        cnt_com_Hoare = 0;
        cnt_swap_Hoare = 0;
        cnt_com_Romuto = 0;
        cnt_swap_Romuto = 0;
    }
    return 0;
}
