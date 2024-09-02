#include <iostream> 
#include <vector> 
#include <stack> 

using namespace std;

struct walkway {
    int from, to, ml;
};

void print(vector<int> d, vector<int> parent, vector<int> friends)
{
    for (auto i : friends) {
        cout << d[i] << " ";
        stack<int> path;
        int node = i;
        while (node != -1) {
            path.push(node);
            node = parent[node];
        }
        cout << path.size() << " ";
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
}

void BellmanFord(int n, vector<walkway> walkways, vector<int> friends)
{
    vector<int> d(n + 1, INT_MAX);
    d[1] = 0;
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < n - 1; i++) {
        for (auto& walkway : walkways) {
            if (d[walkway.from] != INT_MAX && d[walkway.from] + walkway.ml < d[walkway.to]) {
                d[walkway.to] = d[walkway.from] + walkway.ml;
                parent[walkway.to] = walkway.from;
            }
        }
    }
    print(d, parent, friends);
}


int main() {
    int n, m, k; // вершин, дорожек, друзей 
    cin >> n >> m >> k;

    vector<int> friends(k);
    for (int i = 0; i < k; i++) {
        cin >> friends[i];
    }

    vector<walkway> walkways(m);
    for (int i = 0; i < m; i++) {
        cin >> walkways[i].from >> walkways[i].to >> walkways[i].ml;
    }

    BellmanFord(n, walkways, friends);

    return 0;
}
