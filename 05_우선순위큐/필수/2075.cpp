//크기 n의 우선순위큐에 표 역순으로 집어넣고
//작은 수는 계속해서 쳐내다가 더 큰 수가 나오지 않으면 바꾸지 않도록

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp { // 가장 작은 수가 top이 되도록 바꿈
	bool operator()(const int& child, const int& parent) {
		return parent < child;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> input(n * n); //입력받은 표를 저장할 배열
	priority_queue<int, vector<int>, cmp> pq; //우선순위큐

	for (int k = 0; k < n * n; k++) {
		cin >> input[k];
		//배열에 역순으로 저장함... 이렇게 하고 중간에 조건을 넣으면 표 전부를 검증할 필요 없이
		//좀더 효율적으로 할 수 있을것같은데
		//그건 아직 생각중이라 일단 역순으로 넣었음...

	}

	for (int i = n * n - 1; i >= 0; i--) {
		if (pq.size() >= n) { //큐의 크기가 n이면 수를 교체할지 말지 체크
			if (pq.top() < input[i]) //현재 top보다 input이 더 크면
				//가장 작은 수를 교체
			{
				pq.pop();
				pq.push(input[i]);
			}
		}
		else pq.push(input[i]); //큐의 크기가 n보다 작을 땐 그냥 저장
	}

	cout << pq.top();


}
