#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a;
	cin >> a;
	int len = a.size();
	set <string> s;

	for (int j = 1; j <= len; j++) {
		for (int i = 0; i <= len-j; i++) {
			s.insert(a.substr(i, j));
		}
	}
	cout << s.size();
}