//0이 아닌 정수를 배열에 넣는다.
//배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
//절댓값이 가장 작은 값이 여러개일 땐 가장 작은 수를 출력하고 그 값을 제거한다.
//프로그램은 비어있는 배열에서 시작

#include <iostream>
#include <queue>

using namespace std;

struct cmp { //비교 구조체. 스왑이 될 때 true를 뱉는 구조체
	bool operator()(const int &child, const int &parent) {
		if (abs(child) != abs(parent)) {
			return abs(parent) > abs(child);
		}
		return parent > child; 
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;

	priority_queue<int, vector<int>, cmp> pq;

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