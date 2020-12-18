//
// Created by feng on 2020/12/17.
//

#include "BinaryTree.h"
#include <iostream>
using namespace std;
void testBinaryTree(){
    BinaryTree<int,std::string> tree;
    for(int ix : {100,90,120,80,110,150,125,140,145,130,105,108,104,160,75,200,175,148,95,100}){
        tree.insert(ix,std::to_string(ix));
    }
    tree.remove(120);
    cout << tree << endl;
    cout << tree.parent(140)->value << endl;
}