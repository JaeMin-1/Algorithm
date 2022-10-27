#include <iostream>
#include <limits>
#define MAX 100
using namespace std;

template <class T>
T Max(T a, T b)
{
    return a > b ? (a - b) : (b - a);
}
int dp[10000001];
int bottomUp(int weight[], int diff);

int main()
{
    int stone, left, right;
    int num;
    int arr[7] = {1, 2, 5, 10, 20, 50, 100};
    dp[1] = dp[2] = dp[5] = dp[10] = dp[20] = dp[50] = dp[100] = 1;
    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        scanf("%d", &num);
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &stone);
            if (i == 0)
                left = stone;
            else if (i == 1)
                right = stone;
            else
            {
                if (left > right)
                    right += stone;
                else if (left < right)
                    left += stone;
                else
                    left += stone;
            }
        }

        int diff = Max(left, right);
        int count = 0;
        // int min[MAX] = {0};

        // for(int k = 6; k >=0; k--){
        //     while(diff >= arr[k]){
        //         diff -= arr[k];
        //         count++;
        //     }
        // }

        cout << bottomUp(arr, diff) << '\n';
    }
    return 0;
}

int bottomUp(int weight[], int diff)
{
    if (diff < 0)
        return INT32_MAX;
    else if (dp[diff] != 0)
        return dp[diff];
    else if (diff == 0)
        return 0;
    else
    {
        int min = INT32_MAX;
        for (int i = 0; i < 7; i++)
        {
            int tmp = bottomUp(weight, diff - weight[i]);
            if (min >= tmp)
                min = tmp;
        }
        dp[diff] = min + 1;
        return dp[diff];
    }
}