#include <iostream>
#define MAX_SIZE 100
using namespace std;

// 연속된 서브 어레이의 최대 합을 찾는 함수
// 주어진 정수 어레이에서
int kadane(int arr[], int n)
{
    // 지금까지 찾은 최대 합 서브 어레이을 저장합니다.
    int max_total_sum = 0;

    // 현재 위치에서 끝나는 서브 어레이의 최대 합을 저장합니다.
    int max_now_sum = 0;

    // 주어진 어레이 순회
    for (int i = 0; i < n; i++)
    {
        // 인덱스 `i`에서 서브 어레이 "끝"의 최대 합계를 업데이트합니다.
        // 이전 인덱스 `i-1`에서 끝나는 최대 합계까지의 현재 요소)
        max_now_sum = max_now_sum + arr[i];

        // 최대 합계가 음수이면 0으로 설정합니다(이는
        // 빈 서브 어레이)
        max_now_sum = max(max_now_sum, 0);

        // 현재 서브 어레이 합계가 더 큰 것으로 확인되면 결과를 업데이트합니다.
        max_total_sum = max(max_total_sum, max_now_sum);
    }

    return max_total_sum;
}

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];

        cin >> num;
        for (int j = 0; j < num; j++)
            cin >> a[j];

        cout << kadane(a, num) << endl;
    }
    return 0;
}