#include <iostream>
#include "HeapSort.h"
using namespace std;
int main() {
    int arr[101] = {0};
    for(int ix = 0;ix <= 20;++ix){
        arr[ix] = ix;
    }
    HeapSort<int> sort(arr,21,1000);
    sort.sort();
    sort.print();
    return 0;
}
