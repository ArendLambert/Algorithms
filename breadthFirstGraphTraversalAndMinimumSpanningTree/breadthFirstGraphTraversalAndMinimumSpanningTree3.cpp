#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct City {
    int x, y, index;
};

struct Edge {
    int u, v;
    double weight;
};

bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

vector<int> parent;

int find(int city) {
    if (city != parent[city])
        parent[city] = find(parent[city]);
    return parent[city];
}

void unionCities(int city1, int city2) {
    parent[find(city1)] = find(city2);
}

double distance(City a, City b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int N;
    cin >> N;

    vector<City> cities(N);
    for (int i = 0; i < N; i++) {
        cin >> cities[i].x >> cities[i].y;
        cities[i].index = i;
    }

    vector<Edge> edges;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            edges.push_back({ i, j, distance(cities[i], cities[j]) });
        }
    }

    sort(edges.begin(), edges.end(), compareEdge);

    parent.resize(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        unionCities(u - 1, v - 1);
    }

    for (auto& edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            cout << edge.u + 1 << " " << edge.v + 1 << endl;
            unionCities(edge.u, edge.v);
        }
    }

    return 0;
}
