#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
void FloydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (graph[i][j] != 0)
                dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    cout << "Node Distance from every other node" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << i + 1 << " " << j + 1 << " INF" << endl;
            else
                cout << i + 1 << " " << j + 1 << " " << dist[i][j] << endl;
        }
    }
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src - 1][dest - 1] = weight;
    }
    FloydWarshall(graph, V);
    return 0;
}
