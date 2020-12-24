//
// Created by feng on 2020/12/23.
//

#include "Graph.h"

using namespace std;

void Graph::connect(int v, int e) {
    if (v == e || !_adj[v].insert(e).second) {
        return;
    }
    _adj[e].insert(v);
    _E++;
}



void Graph::disconnect(int v, int e) {
    if (v == e || _adj[v].erase(e) <= 0) {
        return;
    }
    _adj[e].erase(v);
    _E--;
}
void Graph::connect(int v, std::initializer_list<int> edges) {
    for(int e : edges){
        connect(v,e);
    }
}
const set<int> &Graph::adj(int v) {
    return _adj[v];
}



void testGraph() {
    const int N = 8;
    Graph graph(N);

    graph.connect(0,{0,1,2,5});
    graph.connect(2,{0,1,2,3,4});
    graph.connect(3,{2,4,5});
    graph.connect(4,{2,3,6});
    graph.connect(5,{0,3,7});
    graph.connect(6,7);
    graph.disconnect(2,1);
    graph.disconnect(3,4);
    graph.disconnect(7,6);


    for (int edge : graph.adj(0)) {
        cout << "vertices 0 connect:" << edge << endl;
    }

    cout << "graph edge size:" << graph.edges() << endl;
    cout << "graph vertices size:" << graph.vertices() << endl;

    graph.path_dfs(0,2);
}