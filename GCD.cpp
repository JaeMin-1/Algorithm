#include <iostream>
using namespace std;

int gcd(int a, int b);

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num1, num2;

        cin >> num1;
        cin >> num2;

        gcd(num1, num2);
        cout << endl;
    }
    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
        cout << a;
    else
        return gcd(b, a % b);
}