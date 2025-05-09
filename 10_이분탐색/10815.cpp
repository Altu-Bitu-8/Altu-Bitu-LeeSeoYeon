#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int i, vector<int>&card, vector<int>& nums) {
	int left = 0;
	int right = n - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (card[mid] == nums[i]) {
			return 1;
		}
		else if (card[mid] > nums[i]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		
	}
	return 0;


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	vector <int> card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	sort(card.begin(), card.end());

	cin >> m;
	vector <int> nums(m);
	for (int i = 0; i < m; i++) {
		cin >> nums[i];
		cout << binarySearch(n, i, card, nums) << ' ';
	}


}