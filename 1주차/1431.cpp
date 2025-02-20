//시리얼번호 string으로 받기
//A와 B의 길이가 다르면 짧은 것이 앞에 온다
//길이가 같다면 A의 모든(숫자만) 자리수의 합, B의 모든 자리수의 합을 비교해 작은 것이 먼저
//1, 2번도 같다면, 사전순으로 비교한다. 숫자가 알파벳보다 먼저다.

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