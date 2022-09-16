#include <iostream>
#include "MergeSort.h"
using namespace std;

int main2(){

    int arr1[] = {7,9,2,1,3,5,6,8,4};
    int arr2[] = {7,9,2,1,3,5,6,8,4};

    mergeSort(arr1,0,8);
    mergeSort(arr2,sizeof(arr2)/sizeof(arr2[0]));

    for(int i : arr1) cout << i << " "; cout << endl;
    for(int i : arr2) cout << i << " "; cout << endl;

    return 0;
}