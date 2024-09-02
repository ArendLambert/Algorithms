#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> maze(m);
    for (int i = 0; i < m; i++) {
        cin >> maze[i];
    }

    pair<int, int> start, finish;
    vector<vector<int>> dist(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == 'S') {
                start = { i, j };
                dist[i][j] = 0;
            }
            else if (maze[i][j] == 'F') {
                finish = { i, j };
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = v.first + dx[i];
            int ny = v.second + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] != 'X' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[v.first][v.second] + 1;
                q.push({ nx, ny });
            }
        }
    }

    cout << dist[finish.first][finish.second] << endl;

    return 0;
}
