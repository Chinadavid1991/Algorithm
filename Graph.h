//
// Created by feng on 2020/12/23.
//

#ifndef ALGORITHM___GRAPH_H
#define ALGORITHM___GRAPH_H

#include <set>
#include <vector>
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

    int dfs(std::vector<int>& vec,int v){
        bool* marked = new bool[_V];
        int count = 0;
        count = dfs(vec,v,marked,count);
        delete[] marked;
        return count;
    }


    virtual ~Graph() {
        delete[] _adj;
    }

private:
    int dfs(std::vector<int>& vec,int v,bool* marked,int count){
        marked[v] = true;
        vec.push_back(v);
        for(int e : _adj[v]){
            if(!marked[e]){
                count = dfs(vec,e,marked,count);
            }
        }
        ++count;
        return count;
    }

};

void testGraph();

#endif //ALGORITHM___GRAPH_H
