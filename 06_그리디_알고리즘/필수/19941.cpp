#include <iostream>
#include <vector>


using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	int cnt = 0;
	vector <char> table(n);

	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}

	for (int j = 0; j < n; j++) {
		if (table[j] == 'P') {
			for (int m = j - k; m <= j + k; m++) {
				if ((m>=0)&&(m<n)&&(table[m] == 'H')) {
					//m이 0~n-1 범위를 벗어나지 않으면서 값이 H일 때
					cnt++;
					table[m] = 'X'; //햄버거 먹었다고 처리
					break; //인당 하나만 먹을 수 있으므로 break
				}
			}
		}
	}

		cout << cnt;

}