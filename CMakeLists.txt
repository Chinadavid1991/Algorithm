cmake_minimum_required(VERSION 3.15)
project(Algorithm__)

set(CMAKE_CXX_STANDARD 11)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )
add_executable(Algorithm__ main.cpp SelectSort.h SparseArray.cpp SparseArray.h
        ArrayQue.cpp ArrayQue.h ListQue.cpp ListQue.h ArrayStack.cpp ArrayStack.h
        ListTable.cpp ListTable.h BinaryTree.cpp BinaryTree.h ArrayHeap.cpp
        ArrayHeap.h HeapSort.cpp HeapSort.h MaxPriorityQue.cpp MaxPriorityQue.h
        RBTree.cpp RBTree.h InsertSort.h InsertSort.cpp ShellSort.cpp ShellSort.h Graph.cpp Graph.h SelectSort.cpp MergeSort.cpp MergeSort.h QuickSort.cpp QuickSort.h Common.cpp Common.h)