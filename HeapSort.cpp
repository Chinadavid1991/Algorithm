//
// Created by feng on 2020/12/18.
//

#include "HeapSort.h"
#include "Common.h"

using namespace std;

void testHeapSort(const int size) {
    const int N = size;
    int *arr = new int[N];
    for (int ix = 0; ix < N; ++ix) {
        arr[ix] = (int) random() % N;
    }
    HeapSort<int> sort(arr, N, N);
    long start = now();
    sort.sort();
    long end = now();
    cout << "HeapSort cost time:" << end - start << endl;
    delete[] arr;
}