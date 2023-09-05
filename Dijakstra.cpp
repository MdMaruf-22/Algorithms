#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
struct Edge {
    int dest, weight;
};
void Dijkstra(vector<vector<Edge>>& graph, int V, int source) {
    vector<int> dist(V, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (const Edge& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Node Distance from Node 1" << endl;
    for (int i = 0; i < V; i++) {
        cout << i + 1 << " " << dist[i] << endl;
    }
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<Edge>> graph(V);
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src - 1].push_back({dest - 1, weight});
    }
    int source = 0;
    Dijkstra(graph, V, source);
    return 0;
}
