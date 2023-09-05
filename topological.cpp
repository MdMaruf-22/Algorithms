#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& order) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, order);
        }
    }
    order.push(node);
}
vector<int> topologicalSort(int numNodes, const vector<vector<int>>& graph) {
    vector<bool> visited(numNodes, false);
    stack<int> order;
    for (int node = 0; node < numNodes; node++) {
        if (!visited[node]) {
            dfs(node, graph, visited, order);
        }
    }
    vector<int> result;
    while (!order.empty()) {
        result.push_back(order.top());
        order.pop();
    }
    return result;
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<vector<int>> graph(numNodes);
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int> sortedOrder = topologicalSort(numNodes, graph);
    cout << "Topological Sorting: ";
    for (int node : sortedOrder) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
