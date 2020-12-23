//
// Created by feng on 2020/12/23.
//

#include "Graph.h"

using namespace std;

void Graph::connect(int v, int w) {
    if (!_adj[v].insert(w).second) {
        return;
    }
    _adj[w].insert(v);
    _E++;
}

void Graph::disconnect(int v, int w) {
    if (_adj[v].erase(w) <= 0) {
        return;
    }
    _adj[w].erase(v);
    _E--;
}

const set<int> &Graph::adj(int v) {
    return _adj[v];
}

void testGraph() {
    Graph graph(10);
    for (int ix = 0; ix < 10; ++ix) {
        graph.connect(ix, (int) random() % 10);
    }
    for (int edge : graph.adj(7)) {
        cout << edge << endl;
    }
    cout << "graph edge size:" << graph.edges() << endl;
}