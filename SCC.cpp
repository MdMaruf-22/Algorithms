#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

class Graph {
    int V; 
    list<int>* adj;

    void SCCUtil(int u, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& stackMember, vector<vector<int>>& result);

public:
    Graph(int V);
    void addEdge(int v, int w);
    vector<vector<int>> findSCCs();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::SCCUtil(int u, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& stackMember, vector<vector<int>>& result) {
    static int time = 0;

    disc[u] = low[u] = ++time;
    st.push(u);
    stackMember[u] = true;

    list<int>::iterator it;
    for (it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = *it;
        if (disc[v] == -1) {
            SCCUtil(v, disc, low, st, stackMember, result);
            low[u] = min(low[u], low[v]);
        }
        else if (stackMember[v] == true) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        vector<int> component;
        while (st.top() != u) {
            int v = st.top();
            component.push_back(v);
            stackMember[v] = false;
            st.pop();
        }

        int v = st.top();
        component.push_back(v);
        stackMember[v] = false;
        st.pop();

        result.push_back(component);
    }
}

vector<vector<int>> Graph::findSCCs() {
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<bool> stackMember(V, false);
    stack<int> st;
    vector<vector<int>> result;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            SCCUtil(i, disc, low, st, stackMember, result);
        }
    }

    return result;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);
    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < E; i++) {
        int source, destination;
        cin >> source >> destination;
        g.addEdge(source, destination);
    }

    vector<vector<int>> sccs = g.findSCCs();

    cout << "Strongly Connected Components:" << endl;
    for (const auto& scc : sccs) {
        for (const auto& vertex : scc) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
