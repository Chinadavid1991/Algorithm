#include <iostream>
#include "ListQue.h"
using namespace std;
int main() {
    ListQue<int> que;
    for(int i = 0;i < 20;++i){
        que.push(i);
        if(i % 2 == 0){
            que.pop();
        }
    }
    cout << que << endl;
    return 0;
}
