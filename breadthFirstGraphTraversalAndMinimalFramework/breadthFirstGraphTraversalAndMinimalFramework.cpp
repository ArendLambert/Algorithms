#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
vector<vector<int>> adj;
vector<int> dist;

void shortest_path(int n, int m) {
    dist.assign(n + 1, INF);
    dist[1] = 0;
    queue<int> q;
    vector<int> in_queue(n + 1, false);
    q.push(1);
    in_queue[1] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        in_queue[v] = false;

        for (int u : adj[v]) {
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                if (!in_queue[u]) {
                    q.push(u);
                    in_queue[u] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
    }

    shortest_path(n, m);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1 << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
