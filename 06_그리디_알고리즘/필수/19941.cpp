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
					//m�� 0~n-1 ������ ����� �����鼭 ���� H�� ��
					cnt++;
					table[m] = 'X'; //�ܹ��� �Ծ��ٰ� ó��
					break; //�δ� �ϳ��� ���� �� �����Ƿ� break
				}
			}
		}
	}

		cout << cnt;

}