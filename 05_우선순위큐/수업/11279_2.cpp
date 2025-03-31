//1. 배열에 자연수 x를 넣는다
//2. 배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다
//최대힙을 이용하여 다음 연산을 지원하는 프로그램 작성
#include <iostream>
#include <queue>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;

	priority_queue<int> pq; //배열도 가능하지만 웬만하면 벡터로 해라
	//첫번째 인덱스는 사용 안 할 거니까 0을 넣어두기
	priority_queue<int, vector<int>, greater<int>> sin_heap;



	while (n--) {
		cin >> x;
		switch (x) {
			case 0
				//삭제
				if (isEmpty(heap)) {
					cout << pq.top() << '\n';
					pq.pop();
				}
				else {
					cout << "0\n";
				}
			break;
			default:
				//삽입
				pq.push(x);
				break;
		}
	}
	return 0;


}