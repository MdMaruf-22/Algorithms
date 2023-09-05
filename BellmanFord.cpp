#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
struct Edge {
    int src, dest, weight;
};
void BellmanFord(vector<Edge>& edges, int V, int source) {
    vector<int> dist(V, INF);
    dist[source] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (const Edge& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    for (const Edge& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }
    cout << "Source Distance from source vertex" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " " << dist[i] << endl;
    }
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges[i] = {src, dest, weight};
    }
    int source;
    cin >> source;
    BellmanFord(edges, V, source);

    return 0;
}
