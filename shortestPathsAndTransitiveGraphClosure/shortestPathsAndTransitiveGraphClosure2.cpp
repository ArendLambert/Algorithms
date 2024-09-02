#include <iostream> 
#include<vector> 
#include <queue> 
#include <string> 

using namespace std;

const int INF = INT_MAX;

int main()
{
    int N, M, P, K;
    cin >> N >> M >> P >> K;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, -1));
    for (int i = 0; i < M; i++)
    {
        int n1, n2, L;
        cin >> n1 >> n2 >> L;
        if (graph[n1][n2] != -1)
        {
            if (graph[n1][n2] > L)
            {
                graph[n1][n2] = L;
                graph[n2][n1] = L;
            }
        }
        else
        {
            graph[n1][n2] = L;
            graph[n2][n1] = L;
        }
    }
    vector<vector<int>> answer(N + 1, vector<int>(N + 1, INF));
    vector<vector<int>> quantity(N + 1, vector<int>(N + 1, 0));
    vector<vector<string>> help(N + 1, vector<string>(N + 1, ""));
    for (int i = 0; i < P; i++)
    {
        int S, T;
        cin >> S >> T;
        if (answer[S][T] == INF)
        {
            help[S][S] = to_string(S) + " ";
            vector<bool> visited(N + 1, false);
            quantity[S][S] = 1;
            answer[S][S] = 0;
            priority_queue<pair<int, int>> pq;
            pq.push({ 0, S });
            while (!pq.empty())
            {
                int u = pq.top().second;
                pq.pop();
                if (visited[u]) continue;
                visited[u] = true;
                for (int v = 0; v < N + 1; v++)
                {
                    if (graph[u][v] != -1 && answer[S][u] + graph[u][v] < answer[S][v])
                    {
                        answer[S][v] = answer[S][u] + graph[u][v];
                        help[S][v] = help[S][u] + to_string(v) + " ";
                        quantity[S][v] = quantity[S][u] + 1;
                        pq.push({ -answer[S][v], v });
                    }
                }
            }
        }
        cout << answer[S][T] << " " << quantity[S][T] << " " << help[S][T] << "\n";
    }
    for (int i = 0; i < K; i++)
    {
        int S, T;
        cin >> S >> T;
        if (answer[S][T] == INF)
        {
            vector<bool> visited(N + 1, false);
            answer[S][S] = 0;
            priority_queue<pair<int, int>> pq;
            pq.push({ 0, S });
            while (!pq.empty())
            {
                int u = pq.top().second;
                pq.pop();
                if (visited[u]) continue;
                visited[u] = true;
                for (int v = 0; v < N + 1; v++)
                {
                    if (graph[u][v] != -1 && answer[S][u] + graph[u][v] < answer[S][v])
                    {
                        answer[S][v] = answer[S][u] + graph[u][v];
                        pq.push({ -answer[S][v], v });
                    }
                }
            }
        }
        cout << answer[S][T] << "\n";
    }
    for (int i = 0; i < N + 1; i++)
    {
        answer[i].clear();
        help[i].clear();
        quantity[i].clear();
        graph[i].clear();
    }
    answer.clear();
    help.clear();
    quantity.clear();
    graph.clear();
    return 0;
}
