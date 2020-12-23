#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph graph(10);
    for (int ix = 0; ix < 10; ++ix) {
        graph.connect(ix,(int)random()%10);
    }
    for(int edge : graph.adj(6)){
        cout << edge << endl;
    }
    cout << graph.edges() << endl;
    return 0;
}
