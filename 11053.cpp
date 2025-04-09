#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가장 긴 증가 부분 수열(LIS)의 길이를 계산하는 함수
int getLISLength(int n, vector<int>& num) { //입력받은 수열과 원소 개수를 넘겨받음
    vector<int> ans(n, 1);//LIS의 길이를 저장할 배열

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) { // 현재 인덱스 이전 요소 모두 확인
            if (num[i] > num[j]) { //뒷 원소가 앞 원소보다 크다면
                ans[i] = max(ans[i], ans[j] + 1); // 최대 수열 길이 갱신
            }
        }
    }

    return *max_element(ans.begin(), ans.end()); //ans에서 최댓값 반환
}

int main()
{
    // 입력
    int n;
    cin >> n;

    vector<int> num(n); //입력받은 수들을 저장하는 배열 생성
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // 연산 & 출력
    cout << getLISLength(n, num);

    return 0;
}