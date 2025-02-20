//�ø����ȣ string���� �ޱ�
//A�� B�� ���̰� �ٸ��� ª�� ���� �տ� �´�
//���̰� ���ٸ� A�� ���(���ڸ�) �ڸ����� ��, B�� ��� �ڸ����� ���� ���� ���� ���� ����
//1, 2���� ���ٸ�, ���������� ���Ѵ�. ���ڰ� ���ĺ����� ������.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stringSum(string a) {
	int sum = 0;
	for (char c : a) {
		if (isdigit(c)) {
			sum += c - '0';
		}
	}
	return sum;
}

bool comp(const string& a1, const string& a2) {
	if (a1.size() != a2.size()) {
		return a1.size() < a2.size();
	}
	if (stringSum(a1) != stringSum(a2)) {
		return stringSum(a1) < stringSum(a2);
	}
	return a1 < a2;
}



int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end(), comp);
	
	for (const string& s : a) {
		cout << s << endl;
	}
}