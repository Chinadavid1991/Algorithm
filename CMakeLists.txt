cmake_minimum_required(VERSION 3.15)
project(Algorithm__)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm__ main.cpp SelectSort.h SparseArray.cpp SparseArray.h
        ArrayQue.cpp ArrayQue.h ListQue.cpp ListQue.h ArrayStack.cpp ArrayStack.h
        ListTable.cpp ListTable.h BinaryTree.cpp BinaryTree.h ArrayHeap.cpp
        ArrayHeap.h HeapSort.cpp HeapSort.h MaxPriorityQue.cpp MaxPriorityQue.h
        RBTree.cpp RBTree.h InsertSort.h InsertSort.cpp)