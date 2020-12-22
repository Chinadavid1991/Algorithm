#include <iostream>
#include "RBTree.h"
using namespace std;
int main() {
    RBTree<int,std::string> tree;
    for(size_t ix = 0;ix < 100;++ix){
        tree.insert(ix,std::to_string(ix));
    }
    cout << tree.isBalance() << endl;

    return 0;
}
