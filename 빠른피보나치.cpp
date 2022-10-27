#include <iostream>
using namespace std;

int *MulArr(int a[2][2], int b[2][2])
{
    int arr[2][2];
    arr[0][0] = (a[0][0] * b[0][0] % 1000 + a[0][1] * b[1][0] % 1000) % 1000;
    arr[1][0] = (a[0][0] * b[0][1] % 1000 + a[0][1] * b[1][1] % 1000) % 1000;
    arr[0][1] = (a[1][0] * b[0][0] % 1000 + a[1][1] * b[1][0] % 1000) % 1000;
    arr[1][1] = (a[1][0] * b[0][1] % 1000 + a[1][1] * b[1][1] % 1000) % 1000;
    return arr[2][2];
}

int fib[2][2] = {
    {1, 1},
    {1, 0}};

int *p(int n)
{
    int y;
    if (n == 1)
        return (int *)fib;
    else if (n % 2 == 1)
    {
        y = p((n - 1) / 2);

        return x * y % 1000 * y % 1000;
    }
    else
    {
        y = p(n / 2);
        return y * y % 1000;
    }
}

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;

        cin >> num;

        cout << p(num);
        cout << endl;
    }
    return 0;
}