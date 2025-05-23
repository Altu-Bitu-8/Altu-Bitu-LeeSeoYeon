#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
int answer;

void dfs(int cur, int target, int distance) {
    if (cur == target) {
        answer = distance;
        return;
    }
    visited[cur] = true;
    for (auto [next, cost] : graph[cur]) {
        if (!visited[next]) {
            dfs(next, target, distance + cost);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({ b, d });
        graph[b].push_back({ a, d });
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        visited.assign(n + 1, false);
        answer = -1; // 초기화 중요!
        dfs(u, v, 0);
        cout << answer << '\n';
    }

    return 0;
}
