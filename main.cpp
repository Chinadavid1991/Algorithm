#include <iostream>
#include "HeapSort.h"
using namespace std;
int main() {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    HeapSort<int> sort(arr,10);
    return 0;
}
