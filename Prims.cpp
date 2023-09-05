#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

struct CompareEdges {
    bool operator()(const Edge& a, const Edge& b) const {
        return a.weight > b.weight;
    }
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edges(e);
    for (int i = 0; i < e; i++) {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        edges[i] = {v1, v2, weight};
    }
    vector<Edge> minimumSpanningTree;
    priority_queue<Edge, vector<Edge>, CompareEdges> pq;
    vector<bool> visited(n + 1, false);
    int startVertex = 1;
    visited[startVertex] = true;
    for (const Edge& edge : edges) {
        if (edge.u == startVertex)
            pq.push(edge);
    }
    while (!pq.empty() && minimumSpanningTree.size() < n - 1) {
        Edge minEdge = pq.top();
        pq.pop();
        if (visited[minEdge.v])
            continue;
        minimumSpanningTree.push_back(minEdge);
        visited[minEdge.v] = true;
        for (const Edge& edge : edges) {
            if (edge.u == minEdge.v && !visited[edge.v])
                pq.push(edge);
        }
    }
    for (const Edge& edge : minimumSpanningTree)
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;

    return 0;
}
