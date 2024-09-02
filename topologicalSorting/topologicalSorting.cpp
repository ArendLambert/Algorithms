#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool topsort(vector<int>& order, int n, vector<int> adjacency[], int* degreeApproach[]) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        if (degreeApproach[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int current = q.top();
        q.pop();
        order.push_back(current);
        for (int current2 : adjacency[current]) {
            degreeApproach[current2]--;
            if (degreeApproach[current2] == 0) {
                q.push(current2);
            }
        }
    }
    return order.size() == n;
}

int main() {
    vector<int> adjacency[401];
    int* degreeApproach[401] = { 0 };
    vector<int> order;

    int n, m;
    int secindTopic, firstTopic;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> secindTopic >> firstTopic;
        adjacency[secindTopic].push_back(firstTopic);
        (degreeApproach[firstTopic])++;
    }

    if (topsort(order, n, adjacency, degreeApproach)) {
        for (int current : order) {
            cout << current << " ";
        }
    }
    else {
        cout << "bad course";
    }

    return 0;
}
