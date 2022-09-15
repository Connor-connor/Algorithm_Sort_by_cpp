#include <iostream>
#include <algorithm>
#include "MergeSort.h"

using namespace std;

//基于递归的归并排序（自顶向下的归并排序）

//二路归并：
void merge(int arr[], int low, int mid, int high) { //low为数组第一个元素下标,high为最后一个元素下标
    //low为第1有序区的第1个元素,i指向第1个元素,mid为第1有序区的最后1个元素
    int i = low, j = mid + 1, k = 0;  //mid+1为第2有序区第1个元素,j指向第1个元素
    int *temp = new int[high - low + 1]; //temp数组暂存合并的有序序列
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) //较小的先存入temp中
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid) //若比较完之后,第一个有序区仍有剩余,则直接复制到t数组中
        temp[k++] = arr[i++];
    while (j <= high) //同上
        temp[k++] = arr[j++];
    for (i = low, k = 0; i <= high; i++, k++) //将排好序的存回arr中low到high这区间
        arr[i] = temp[k];
    delete [] temp; //释放内存,由于指向的是数组,必须用delete []
}

//向量归并排序:
void MergeSort(int arr[], int low, int high) { //0 <= lo <= hi <= size-1
    if (low >= high) { return; } //终止递归的条件,子序列长度为1

//    优化一：对小规模子数组使用插入排序
//    用不同的方法处理小规模问题能改进大多数递归算法的性能
//    因为递归会使小规模问题中方法调用太过频繁,所以改进对它们的处理方法就能改进整个算法
//    因为插入排序非常简单,因此一般来说在小数组上比归并排序更快,这种优化能使归并排序的运行时间缩短10%到15%
//    将 if (low >= high) { return; } 换成:
//    if(high - low <= 10) { // 数组长度小于10的时候
//        InsertSort(int arr[], int low,int high) // 切换到插入排序
//        return;
//    }

    int mid = low + (high - low) / 2;  //取得序列中间的元素
    MergeSort(arr, low, mid);  //对左半边递归
    MergeSort(arr, mid + 1, high);  //对右半边递归

//    优化二: 测试待排序序列中左右半边是否已有序
//    通过测试待排序序列中左右半边是否已经有序,在有序的情况下避免合并方法的调用
//    if(a[mid]<=a[mid+1]) return; // 避免不必要的归并

    merge(arr, low, mid, high);  //合并
}
