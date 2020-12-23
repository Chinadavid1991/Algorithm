#include <iostream>
#include "ShellSort.h"
#include "InsertSort.h"
#include "SelectSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
using namespace std;

int main() {
    const int size = 100000;
    testInsertSort(size);
    testSelectSort(size);

    testShellSort(size);
    testQuickSort(size);
    testHeapSort(size);
    testMergeSort(size);
    return 0;
}
