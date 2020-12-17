//
// Created by feng on 2020/12/17.
//

#include "ArrayStack.h"
using namespace std;
void testArrayStack(){
    ArrayStack<int> stack(100);
    for(int i = 0;i < 100;++i){
        stack.push(i);
        if(i % 2 == 0){
            stack.pop();
        }
    }
    cout << stack << endl;
}