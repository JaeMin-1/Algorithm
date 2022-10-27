#include <iostream>
#define MAX_SIZE 30
using namespace std;

int fib(int n);

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;

        cin >> num;

        cout << fib(num);
        cout << endl;
    }
    return 0;
}

int fib(int n)
{
    if (n <= 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}