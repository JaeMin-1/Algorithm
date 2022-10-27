#include <iostream>
#define MAX_SIZE 1000

using namespace std;
void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);

int main()
{
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE], b[MAX_SIZE];

        cin >> num;
        for (int j = 0; j < num; j++)
            cin >> b[j];

        copyArray(a, b, num);
        bubbleSort(a, num);

        copyArray(a, b, num);
        bubbleSortImproved1(a, num);

        copyArray(a, b, num);
        bubbleSortImproved2(a, num);
        cout << endl;
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수
    // bubble sort 알고리즘 구현
    for (int pass = 1; pass < n; pass++)
        for (int i = 1; i <= n - pass; i++)
        {
            countCmpOps += 1;
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                countSwaps += 1;
            }
        }
    cout << countCmpOps << " " << countSwaps << " ";
}

void bubbleSortImproved1(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수
    // bubble sort의 개선된 알고리즘 (1) 구현
    for (int pass = 1; pass < n; pass++) // pass = 1,2,…,n-1
    {
        bool swapped = false; // 이번 pass에서 데이터 교환했는지 유무
        for (int i = 1; i <= n - pass; i++)
        {
            countCmpOps += 1;
            if (a[i - 1] > a[i]) // > : 비교 연산자
            {
                swap(a[i - 1], a[i]);
                swapped = true; // 데이터 교환했음
                countSwaps += 1;
            }
        }
        if (swapped == false) // 이번 pass에서 데이터를 교환하지 않았다면
            break;            // 데이터가 정렬되어 있음. 따라서 종료함
    }
    cout << countCmpOps << " " << countSwaps << " ";
}

void bubbleSortImproved2(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수
    // bubble sort의 개선된 알고리즘 (2) 구현
    int lastSwappedPos = n;
    while (lastSwappedPos > 0) // 마지막으로 교환한 데이터의 위치
    {
        int swappedPos = 0; // 이번 pass에서 데이터 교환한 위치
        for (int i = 1; i < lastSwappedPos; i++)
        { // 직전 pass에서 교환한 마지막 위치까지만 실행
            countCmpOps += 1;
            if (a[i - 1] > a[i]) // > : 비교 연산자
            {
                swap(a[i - 1], a[i]);
                countSwaps += 1;
                swappedPos = i; // 데이터 교환한 위치
            }
        }
        lastSwappedPos = swappedPos; // 이번 pass에서 교환한 마지막 데이터의 위치
                                     // 다음 pass에서는 이 위치 바로 앞까지만 실행하면 됨
    }
    cout << countCmpOps << " " << countSwaps;
}

void copyArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}