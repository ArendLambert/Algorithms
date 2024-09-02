#include <iostream> 
#include <vector> 
#include <cmath> 

using namespace std;

struct Point {
    int x, y;
};

struct Match {
    Point p1, p2;
};

bool intersect(const Match& m1, const Match& m2) {
    int t1 = (m2.p1.x - m1.p1.x) * (m1.p2.y - m1.p1.y) - (m2.p1.y - m1.p1.y) * (m1.p2.x - m1.p1.x);
    int t2 = (m2.p2.x - m1.p1.x) * (m1.p2.y - m1.p1.y) - (m2.p2.y - m1.p1.y) * (m1.p2.x - m1.p1.x);
    int t3 = (m1.p1.x - m2.p1.x) * (m2.p2.y - m2.p1.y) - (m1.p1.y - m2.p1.y) * (m2.p2.x - m2.p1.x);
    int t4 = (m1.p2.x - m2.p1.x) * (m2.p2.y - m2.p1.y) - (m1.p2.y - m2.p1.y) * (m2.p2.x - m2.p1.x);

    if (t1 * t2 < 0 && t3 * t4 < 0) return true;

    if (t1 == 0 && ((m2.p1.x - m1.p1.x) * (m2.p1.x - m1.p2.x) <= 0 && (m2.p1.y - m1.p1.y) * (m2.p1.y - m1.p2.y) <= 0)) return true;
    if (t2 == 0 && ((m2.p2.x - m1.p1.x) * (m2.p2.x - m1.p2.x) <= 0 && (m2.p2.y - m1.p1.y) * (m2.p2.y - m1.p2.y) <= 0)) return true;
    if (t3 == 0 && ((m1.p1.x - m2.p1.x) * (m1.p1.x - m2.p2.x) <= 0 && (m1.p1.y - m2.p1.y) * (m1.p1.y - m2.p2.y) <= 0)) return true;
    if (t4 == 0 && ((m1.p2.x - m2.p1.x) * (m1.p2.x - m2.p2.x) <= 0 && (m1.p2.y - m2.p1.y) * (m1.p2.y - m2.p2.y) <= 0)) return true;

    return false;
}

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    int n;
    while (cin >> n, n != 0) {
        vector<Match> matches(n + 1);
        for (int i = 1; i <= n;i++) {
            cin >> matches[i].p1.x >> matches[i].p1.y >> matches[i].p2.x >> matches[i].p2.y;
        }
        vector<vector<int>> adj(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (intersect(matches[i], matches[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int a, b;
        while (cin >> a >> b, a != 0 && b != 0) {
            vector<bool> visited(n + 1);
            dfs(a, adj, visited);
            cout << (visited[b] ? "CONNECTED\n" : "NOT CONNECTED\n");
        }
    }

    return 0;
}
