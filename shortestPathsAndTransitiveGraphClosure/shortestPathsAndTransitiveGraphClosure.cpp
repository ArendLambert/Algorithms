#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std;

const int INF = 99999999;

int dijkstra(int start, int end, const vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != -1 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({ -dist[v], v });
            }
        }
    }
    return dist[end] == INF ? -1 : dist[end];
}

int main() {
    int n, from, to, u, v, k;
    cin >> n >> from >> to;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));

    while (cin >> u >> v >> k) {
        graph[u][v] = graph[v][u] = k;
    }

    int dist = dijkstra(from, to, graph);

    if (dist == -1) {
        cout << "no" << endl;
    }
    else {
        cout << dist << endl;
    }
    return 0;
}
