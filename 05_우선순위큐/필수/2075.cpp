//크기 n의 우선순위큐에 표 역순으로 집어넣고
//작은 수는 계속해서 쳐내다가 더 큰 수가 나오지 않으면 바꾸지 않도록

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int num;
	priority_queue<int, vector<int>, greater<int>> pq;
	//greater<int> 사용해서 최소힙 만듦

	for (int k = 0; k < n * n; k++) {
		cin >> num;
		
		if (pq.size() >= n) {//큐의 크기가 n이면 수를 교체할지 말지 체크
			if (pq.top() < num) //현재 top보다 num이 더 크면
				//가장 작은 수를 교체
			{
				pq.pop();
				pq.push(num);
			}
		}
		else pq.push(num); //큐의 크기가 n보다 작을 땐 그냥 저장
	}


	cout << pq.top();


}
