//
// Created by feng on 2020/12/23.
//

#ifndef ALGORITHM___GRAPH_H
#define ALGORITHM___GRAPH_H

#include <set>
#include <iostream>
class Graph {
    const int _V;
    int _E;
    std::set<int> *_adj;
public:
    explicit Graph(int v) : _V(v), _E(0), _adj(new std::set<int>[_V]) {}

    int vertices() const { return _V; }

    int edges() const { return _E; }

    void connect(int v, int w);

    void disconnect(int v, int w);

    const std::set<int> &adj(int v);

    virtual ~Graph() {
        delete[] _adj;
    }


};
void testGraph();

#endif //ALGORITHM___GRAPH_H
