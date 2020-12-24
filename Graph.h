//
// Created by feng on 2020/12/23.
//

#ifndef ALGORITHM___GRAPH_H
#define ALGORITHM___GRAPH_H

#include <set>
#include <vector>
#include <iostream>
#include <deque>
#include <stack>
#include <initializer_list>

class Graph {
    const int _V;
    int _E;
    std::set<int> *_adj;
public:
    explicit Graph(int v) : _V(v), _E(0), _adj(new std::set<int>[_V]) {}

    int vertices() const { return _V; }

    int edges() const { return _E; }

    void connect(int v, int w);
    void connect(int v,std::initializer_list<int> edges);
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
        marked[v] = true;
        count = breadth_dfs(vec, que, marked, count);
        delete[] marked;
        return count;
    }

    void path_dfs(int start,int end){
        bool *marked = new bool[_V]();
        std::stack<int> path;
        path_dfs(start,end,path,marked);
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
            vec.push_back(v);
            for(int e : _adj[v]){
                if(!marked[e]){
                    que.push_front(e);
                    marked[e] = true;
                }
            }
            que.pop_back();
            ++count;
        }
        return count;
    }

    void path_dfs(int start,int end,std::stack<int>& path,bool* marked){
        if(start == end){
            //打印路径信息
            std::stack<int> s(path);
            if(!s.empty()){
                std::cout << "show path:" << end << "<-";
            }
            else{
                std::cout << "show path:" << end;
            }
            while (!s.empty()){
                if(s.size() > 1){
                    std::cout << s.top() << "<-";
                }
                else{
                    std::cout << s.top();
                }
                s.pop();
            }
            std::cout << std::endl;
        }
        else{
            path.push(start);
            marked[start] = true;
            for(int e : _adj[start]){
                if(marked[e]){
                    continue;
                }
                path_dfs(e,end,path,marked);
            }
            path.pop();
            marked[start] = false;
        }
    }
};

void testGraph();

#endif //ALGORITHM___GRAPH_H
