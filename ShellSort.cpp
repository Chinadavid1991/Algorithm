//
// Created by feng on 2020/12/22.
//

#include "ShellSort.h"
#include "Common.h"

using namespace std;


void testShellSort(const int size) {
    const int N = size;
    int *arr = new int[N];
    for (int ix = 0; ix < N; ++ix) {
        arr[ix] = (int) random() % N;
    }

    ShellSort<int> sort(arr, N);
    long start = now();
    sort.sort();
    long end = now();
    cout << "ShellSort cost time:" << end - start << endl;
    delete[] arr;
}