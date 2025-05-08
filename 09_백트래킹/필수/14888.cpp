#include <iostream>
#include <vector>

using namespace std;

int answer[2] = {}; 
bool isFirst = true;

void backtracking(int idx, int n, int result, vector <int> &a, vector<int> &check) {

	if (idx == n) {
		if (isFirst) {
			answer[0] = result;
			answer[1] = result;
			isFirst = false;
		}
		else{
			answer[0] = max(answer[0], result);
			answer[1] = min(answer[1], result);
		}
		
		return;
	}
	
		for (int i = 0; i < 4; i++) {
			if (check[i] == 0) {
				continue;
			}

			int result2 = result;

			switch (i) {
			case 0:
				result2 += a[idx];
				break;
			case 1:
				result2 -= a[idx];
				break;
			case 2:
				result2 *= a[idx];
				break;
			case 3:
				if (result2 < 0) {
					result2 *= -1;
					result2 /= a[idx];
					result2 *= -1;
					break;
				}
				result2 /= a[idx];
				break;
			}
			check[i]--;
			backtracking(idx+1, n, result2, a, check);
			check[i]++;
		}
	}





int main() {


	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> check(4);
	for (int i = 0; i < 4; i++) {
		cin >> check[i];
	}


	backtracking(1, n, a[0], a, check);
	cout << answer[0] << "\n" << answer[1];

}