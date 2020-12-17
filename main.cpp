#include <iostream>
#include "ArrayStack.h"
using namespace std;
int main() {
    ArrayStack<int> stack(10);
    for(int i = 0;i < 100;++i){
        stack.push(i);
    }
    cout << stack << endl;
    return 0;
}
