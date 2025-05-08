#include <iostream>
#include <vector>

using namespace std;

int answer = 1e7;  // 최대 비용 1 000 000 * 최대 도시 수 10

void backtracking(int cnt, int n, int curr_city, int sum, vector<bool>& check, vector<vector<int>>& cost) {
    if (sum >= answer) {  // 현재 최솟값보다 커진 경우
        return;
    }

    if (cnt == n) {
        if (cost[curr_city][0] != 0) {  // 출발 도시로 다시 돌아갈 수 있는가?
            answer = min(answer, sum + cost[curr_city][0]); //답 갱신
        }
        return;
    }

    for (int next_city = 0; next_city < n; next_city++) { //다음에 방문할 도시 찾기
        if (check[next_city] || cost[curr_city][next_city] == 0) { //이미 방문한 도시라면 넘어가기
            continue;
        }

        check[next_city] = true;//방문 체크
        backtracking(cnt + 1, n, next_city, sum + cost[curr_city][next_city], check, cost);
        check[next_city] = false;//방문 상태 초기화
    }
}

int main() {
    // 입력
    int n;
    cin >> n;

    vector<bool> check(n, false);//방문했는지 체크하는 벡터
    vector<vector<int>> cost(n, vector<int>(n));//방문 비용 벡터

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // 연산
    check[0] = true;
    backtracking(1, n, 0, 0, check, cost);

    cout << answer;
}