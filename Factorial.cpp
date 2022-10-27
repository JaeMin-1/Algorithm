#include <iostream>

using namespace std;

int f(int n);

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;

        cin >> num;

        cout << f(num) % 1000;
        cout << endl;
    }
    return 0;
}

int f(int n)
{
    if (n <= 1)
        return 1;
    else
    {
        int fac = n * f(n - 1);
        while (true)
        {
            if (fac % 10 == 0)
                fac /= 10;
            else
                break;
        }
        return fac % 10000;
    }
}