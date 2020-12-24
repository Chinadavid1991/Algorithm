//
// Created by feng on 2020/12/23.
//

#include "Graph.h"

using namespace std;

void Graph::connect(int v, int w) {
    if (v == w || !_adj[v].insert(w).second) {
        return;
    }
    _adj[w].insert(v);
    _E++;
}

void Graph::disconnect(int v, int w) {
    if (v == w || _adj[v].erase(w) <= 0) {
        return;
    }
    _adj[w].erase(v);
    _E--;
}

const set<int> &Graph::adj(int v) {
    return _adj[v];
}

void testGraph() {
    const int N = 10;
    Graph graph(N);
    for (int ix = 0; ix < N; ++ix) {
        graph.connect(ix, (int) random() % N);
    }


    for (int edge : graph.adj(0)) {
        cout << edge << endl;
    }
    vector<int> vec;
    cout << graph.dfs(vec,0) << endl;

    cout << "graph edge size:" << graph.edges() << endl;
    cout << "graph vertices size:" << graph.vertices() << endl;
}