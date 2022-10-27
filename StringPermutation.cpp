#include <iostream>
using namespace std;

int countNum = 0;
void per(string str, int i, int n);

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        string str;
        cin >> str;

        per(str, 0, str.length());
        cout << countNum << endl;
        countNum = 0;
    }
    return 0;
}

void swap(string *a, string *b)
{
    string tmp = *a;
    *a = *b;
    *b = tmp;
}

void per(string str, int i, int n)
{
    if (i == n - 1)
    {
        int w = 0;
        for (int k = 0; k < n; k++)
        {
            int asci = int(str[k]) - 97;
            if (k % 2 != 0)
                asci = -asci;
            w += asci;
        }
        if (w > 0)
            countNum += 1;
    }

    for (int j = i; j < n; j++)
    {
        swap(str[i], str[j]);
        per(str, i + 1, n);
        swap(str[i], str[j]);
    }
}