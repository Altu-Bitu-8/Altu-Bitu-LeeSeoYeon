
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e5;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int case_num = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<vector<int>> map(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> map[i][j];

        vector<vector<int>> dist(n, vector<int>(n, INF));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        dist[0][0] = map[0][0];
        pq.push({ dist[0][0], {0, 0} });

        while (!pq.empty()) {
            int weight = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (weight > dist[x][y])
                continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int next_weight = weight + map[nx][ny];
                    if (next_weight < dist[nx][ny]) {
                        dist[nx][ny] = next_weight;
                        pq.push({ next_weight, {nx, ny} });
                    }
                }
            }
        }

        cout << "Problem " << case_num++ << ": " << dist[n - 1][n - 1] << '\n';
    }
    return 0;
}
