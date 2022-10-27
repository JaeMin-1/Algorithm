#include <iostream>
using namespace std;

int stack[11];
int sp = 0;
void hanoi(int n, int from, int by, int to);

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;

        cin >> num;

        sp = 0;
        hanoi(num, 1, 2, 3);
        cout << endl;
    }
    return 0;
}

void hanoi(int n, int from, int by, int to)
{
    if (n >= 1)
    {
        hanoi(n - 1, from, to, by);
        if (to == 3)
        {
            sp++;
            stack[sp] = n;
            printf("%d ", stack[sp]);
        }
        else if (from == 3)
        {
            sp--;
            printf("%d ", stack[sp]);
        }
        hanoi(n - 1, by, from, to);
    }
}
