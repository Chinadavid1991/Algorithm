//
// Created by feng on 2020/12/23.
//

#include "MergeSort.h"
using namespace std;
void testMergeSort() {
    constexpr int N = 100;
    int arr[N];
    for (int &ix : arr) {
        ix = (int) random() % N;
    }
    MergeSort<int, N> sort(arr);
    sort.sort();
    cout << "[";
    for (size_t ix = 0; ix < N; ++ix) {
        if (ix == N - 1) {
            cout << arr[ix] << "]";
        }
        else {
            cout << arr[ix] << ",";
        }

    }
    cout << endl;
}
