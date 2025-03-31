#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct info {
    int idx;        // 처음 줄에 선 번호
    int line_num;   // m개의 줄 중 속한 줄의 번호
    int work_days;  // 근무 일수
    int urgency;    // 급한 정도
};

struct cmp { //우선순위큐 조건 설정
    bool operator()(const info& child, const info& parent) {
        if (parent.work_days != child.work_days) { 
            return parent.work_days > child.work_days; //더 많이 일한 사람부터
        }
        if (parent.urgency != child.urgency) {
            return parent.urgency > child.urgency; //더 급한 사람부터
        }
        return parent.line_num < child.line_num; //더 앞줄에 있는 사람부터 
    }
};

int simulation(int m, int k, vector<queue<info>>& lines) {
    // 각 줄의 선두들이 저장되는 우선순위 큐
    priority_queue<info, vector<info>, cmp> pq; //선두를 담을 우선순위 큐

    // 우선순위 큐 초기화
    for (int i = 0; i < m; i++) {
        if (!lines[i].empty()) { //줄이 비어있지 않다면
            pq.push(lines[i].front()); //선두를 우선순위 큐에 추가
            lines[i].pop();
        }
    }

    // k 차례가 오기 전 화장실을 사용한 사람의 수
    int count = 0;

    while (!pq.empty() && pq.top().idx != k) {  // k의 차례가 되기 전까지
        int line_num = pq.top().line_num; //우선순위 가장 높은 사람의 줄 번호
        pq.pop();  //우선순위 가장 높은 사람 화장실 이용

        if (!lines[line_num].empty()) { 
            pq.push(lines[line_num].front()); //방금의 줄 새 선두를 우선순위큐에 추가
            lines[line_num].pop(); //큐에서는 삭제
        }
        
        count++;
    }

    return count;
}

/**
 * [화장실의 규칙] - 우선순위 큐 & 시뮬레이션 문제
 *
 * 1. 각 사람은 (온 순서 % m) 번째 줄의 뒤에 서게 된다.
 * 2. 매 순간, 모든 줄의 앞 사람 중에 우선 순위가 가장 높은 사람부터 화장실을 이용한다.
 *
 * <우선순위>
 * 1. 근무 일자가 많은 사람
 * 2. 더 급한 사람
 * 3. 줄 번호가 앞선 사람
 *
 * ---
 * 1. 각 줄은 먼저 온 사람이 먼저 나가기 때문에, 큐를 이용해 저장한다.
 * 2. 모든 줄의 선두를 우선순위 큐에 넣고, 우선순위가 가장 앞선 사람부터 삭제한다.
 * 3. 어떤 줄의 선두가 화장실을 이용했으면, 그 줄의 선두를 우선 순위 큐에 넣는다.
 *
 * 이때, 0번부터 표기하므로 데카의 idx는 k가 된다.
 *
 * !주의! 큐에서 사람을 빼서 우선 순위 큐에 넣을 때, 항상 큐가 비어있지 않은지 확인
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, d, h;
    cin >> n >> m >> k;

    vector<queue<info>> lines(m, queue<info>()); //m개의 줄 담을 큐 만들기

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> d >> h;
        lines[i % m].push({ i, i % m, d, h }); //큐에 담기(줄 세우기)
    }

    // 연산 & 출력
    cout << simulation(m, k, lines);

    return 0;
}