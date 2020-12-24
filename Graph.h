//
// Created by feng on 2020/12/23.
//

#ifndef ALGORITHM___GRAPH_H
#define ALGORITHM___GRAPH_H

#include <set>
#include <vector>
#include <iostream>
#include <deque>

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

    int depth_dfs(std::vector<int> &vec, int v) {
        bool *marked = new bool[_V]();
        int count = 0;
        count = depth_dfs(vec, v, marked, count);
        delete[] marked;
        return count;
    }

    int breadth_dfs(std::vector<int> &vec, int v) {
        bool *marked = new bool[_V]();
        int count = 0;
        std::deque<int> que;
        que.push_front(v);
        count = breadth_dfs(vec, que, marked, count);
        delete[] marked;
        return count;
    }

    virtual ~Graph() {
        delete[] _adj;
    }

private:
    int depth_dfs(std::vector<int> &vec, int v, bool *marked, int count) {
        marked[v] = true;
        vec.push_back(v);
        for (int e : _adj[v]) {
            if (!marked[e]) {
                count = depth_dfs(vec, e, marked, count);
            }
        }
        ++count;
        return count;
    }

    int breadth_dfs(std::vector<int> &vec, std::deque<int> &que, bool *marked, int count) {
        while (!que.empty()){
            int v = que.back();
            marked[v] = true;
            vec.push_back(v);
            for(int e : _adj[v]){
                if(!marked[e]){
                    que.push_front(e);
                }
            }
            que.pop_back();
            ++count;
        }
        return count;
    }
};

void testGraph();

#endif //ALGORITHM___GRAPH_H
