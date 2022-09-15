cmake_minimum_required(VERSION 3.23)
project(Sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sort main.cpp src/bubble_sort/main.cpp src/bubble_sort/BubbleSort.cpp src/bubble_sort/BubbleSort.h src/merge_sort/MergeSort.cpp src/merge_sort/MergeSort.h)
