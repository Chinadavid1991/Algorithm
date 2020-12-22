//
// Created by feng on 2020/12/21.
//

#include "RBTree.h"
using namespace std;
void testRBTree(){
    RBTree<int,std::string> tree;
    for(size_t ix = 0;ix < 100;++ix){
        tree.insert(ix,std::to_string(ix));
    }
    cout << tree << endl;
}

