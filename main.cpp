#include <iostream>
#include "SelectSort.h"
using namespace std;
int main() {
    int data[16] = {10,9,5,6,7,8,4,3,2,1,11,13,12,16,15,14};
    SelectSort<int, 16> sel(data);
    sel.sort();
    for(int x : data){
        cout << x << endl;
    }
    return 0;
}
