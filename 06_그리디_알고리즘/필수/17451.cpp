#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	long long min = v[n - 1];
	// 마지막에 필요한 연료량을 기준으로 역순으로 올라가기

	for (int i = n - 2; i >= 0; i--) {
		if (min % v[i] == 0) {
			continue;
		}
		else {
			min = ((min + v[i] - 1) / v[i]) * v[i]; //올림 계산식
		}
	}

	cout << min;
	return 0;
}
