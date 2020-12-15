#include <iostream>
#include "SelectSort.h"
using namespace std;
int main() {
    int data[20] = {10,9,5,6,7,8,4,3,2,1,11,13,12,16,15,14,17,18,19,20};
    SelectSort<int, sizeof(data)/ sizeof(int)> sel(data);
    sel.sort();
    for(int x : data){
        cout << x << endl;
    }
    return 0;
}
