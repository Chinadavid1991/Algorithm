//
// Created by feng on 2020/12/23.
//

#ifndef ALGORITHM___GRAPH_H
#define ALGORITHM___GRAPH_H

#include <set>
#include <vector>
#include <iostream>
#include <memory.h>
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

    int deep_dfs(std::vector<int> &vec, int v) {
        bool *marked = new bool[_V]();
        int count = 0;
        count = deep_dfs(vec, v, marked, count);
        delete[] marked;
        return count;
    }
    int depth_dfs(std::vector<int> &vec, int v){
        bool *marked = new bool[_V]();
        for(int ix = 0;ix < _V;++ix){
            std::cout << marked[ix] << std::endl;
        }
        int count = 0;
        marked[v] = true;
        vec.push_back(v);
        count++;
        count = depth_dfs(vec, v, marked, count);
        delete[] marked;
        return count;
    }

    virtual ~Graph() {
        delete[] _adj;
    }

private:
    int deep_dfs(std::vector<int> &vec, int v, bool *marked, int count) {
        marked[v] = true;
        vec.push_back(v);
        for (int e : _adj[v]) {
            if (!marked[e]) {
                count = deep_dfs(vec, e, marked, count);
            }
        }
        ++count;
        return count;
    }
    int depth_dfs(std::vector<int> &vec, int v, bool *marked, int count){
        std::vector<int> search;
        for(int e : _adj[v]){
            if(!marked[e]){
                marked[e] = true;
                vec.push_back(v);
                ++count;
                search.push_back(e);
            }
        }
        for(int e : search){
            count = depth_dfs(vec, e, marked, count);
        }
        return count;
    }
};

void testGraph();

#endif //ALGORITHM___GRAPH_H
