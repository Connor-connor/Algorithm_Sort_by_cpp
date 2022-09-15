#include <iostream>
#include "BubbleSort.h"
using namespace std;

int main(){
    int arr0[] = {1,2,3,6,4,5,7,8,9};
    int arr1A[] = {1,2,3,6,4,5,7,8,9};
    int arr1B[] = {1,2,3,6,4,5,7,8,9};
    int arr2[] = {1,2,3,6,4,5,7,8,9};

    bubbleSort_0(arr0,sizeof(arr0)/sizeof(arr0[0]));
    bubbleSort_1A(arr1A,sizeof(arr1A)/sizeof(arr1A[0]));
    bubbleSort_1B(arr1B,sizeof(arr1B)/sizeof(arr1B[0]));
    bubbleSort_2(arr2,sizeof(arr2)/sizeof(arr2[0]));

    for(int i : arr0) cout << i << " "; cout << endl;
    for(int i : arr1A) cout << i << " "; cout << endl;
    for(int i : arr1B) cout << i << " "; cout << endl;
    for(int i : arr2) cout << i << " "; cout << endl;

    return 0;
}
