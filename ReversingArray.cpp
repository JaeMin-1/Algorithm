#include <iostream>
using namespace std;

void reverse(string &str, int l, int h);

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        string str;

        cin >> str;

        reverse(str, 0, str.length() - 1);
        cout << str << endl;
    }
    return 0;
}

void swap(string *a, string *b)
{
    string tmp = *a;
    *a = *b;
    *b = tmp;
}

// 주어진 문자열을 뒤집는 재귀 함수
// 참고 문자열이 참조 매개변수로 전달됩니다.
void reverse(string &str, int l, int h)
{
    if (l < h)
    {
        swap(str[l], str[h]);
        reverse(str, l + 1, h - 1);
    }
}