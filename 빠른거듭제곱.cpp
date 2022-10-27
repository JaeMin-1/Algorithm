#include <iostream>
using namespace std;

int p(int x, int n)
{
    int y;
    if (n == 0)
        return 1.0;
    else if (n % 2 == 1)
    {
        y = p(x, (n - 1) / 2);
        return x * y % 1000 * y % 1000;
    }
    else
    {
        y = p(x, n / 2);
        return y * y % 1000;
    }
}

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int x, n;

        cin >> x;
        cin >> n;

        cout << p(x, n) % 1000 << endl;
    }
    return 0;
}