#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int count(int n, vector <int>& gwaja, int length) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += gwaja[i] / length;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;

    cin >> m >> n;
    vector<int> gwaja(n);

    int max_len = 0;

    for (int i = 0; i < n; i++) {
        cin >> gwaja[i];
        if (gwaja[i] > max_len) max_len = gwaja[i];
    }

    int left = 1;
    int right = max_len;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        int jogak = count(n, gwaja, mid); 
        if (jogak >= m) {
            answer = mid;         
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
