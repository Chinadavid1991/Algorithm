//
// Created by feng on 2020/12/23.
//

#include "MergeSort.h"
#include "Common.h"

using namespace std;

void testMergeSort(const int size) {
    const int N = size;
    int *arr = new int[N];
    for (int ix = 0; ix < N; ++ix) {
        arr[ix] = (int) random() % N;
    }

    MergeSort<int> sort(arr, N);
    long start = now();
    sort.sort();
    long end = now();
    cout << "MergeSort cost time:" << end - start << endl;
    delete[] arr;
}
