#include <iostream>
#define DIFF(a, b) (((a) > (b)) ? (a - b) : (b - a))
using namespace std;
int cnt = 0;
int arr[7] = {1, 2, 5, 10, 20, 50, 100};

int NumberOfWeights(int diff)
{
    for (int k = 6; k >= 0; k--)
    {
        while (diff >= arr[k])
        {
            diff -= arr[k];
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num, pebble;
        int left = 0;
        int right = 0;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> pebble;
            if (j == 0)
                left = pebble;
            else if (j == 1)
                right = pebble;
            else
            {
                if (left > right)
                    right += pebble;
                else if (left < right)
                    left += pebble;
                else
                    left += pebble;
            }
        }
        int diff = DIFF(left, right);
        cout << NumberOfWeights(diff) << endl;
        cnt = 0;
    }
    return 0;
}