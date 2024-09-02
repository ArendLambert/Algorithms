#include <iostream> 
#include <vector> 
#include <queue> 
#include <limits> 
#include <algorithm> 

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<pair<int, int>> queries(K);

    for (int i = 0; i < K; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].emplace_back(b, t);
        graph[b].emplace_back(a, t);
    }

    for (auto& query : queries) {
        int S = query.first;
        int T = query.second;

        vector<int> dist(N + 1, INF);
        vector<int> parent(N + 1, -1);
        dist[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, S });

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d != dist[u]) continue;

            for (auto& edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({ dist[v], v });
                }
            }
        }

        if (dist[T] == INF) {
            cout << "NO\n";
        }
        else {
            cout << "YES " << dist[T];
            vector<int> path;
            for (int u = T; u != -1; u = parent[u]) {
                path.push_back(u);
            }
            reverse(path.begin(), path.end());
            cout << " " << path.size();
            for (int u : path) {
                cout << " " << u;
            }
            cout << "\n";
        }
    }

    return 0;
}
