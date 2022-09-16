#include <iostream>
#include <algorithm>
#include "MergeSort.h"

using namespace std;

//��·�鲢��
void merge(int arr[], int low, int mid, int high) { //lowΪ�����һ��Ԫ���±�,highΪ���һ��Ԫ���±�
    //lowΪ��1�������ĵ�1��Ԫ��,iָ���1��Ԫ��,midΪ��1�����������1��Ԫ��
    int i = low, j = mid + 1, k = 0;  //mid+1Ϊ��2��������1��Ԫ��,jָ���1��Ԫ��
    int *temp = new int[high - low + 1]; //temp�����ݴ�ϲ�����������
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) //��С���ȴ���temp��
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid) //���Ƚ���֮��,��һ������������ʣ��,��ֱ�Ӹ��Ƶ�t������
        temp[k++] = arr[i++];
    while (j <= high) //ͬ��
        temp[k++] = arr[j++];
    for (i = low, k = 0; i <= high; i++, k++) //���ź���Ĵ��arr��low��high������
        arr[i] = temp[k];
    delete[] temp; //�ͷ��ڴ�,����ָ���������,������delete []
}

//�鲢����:(��Ϊ����)
//1.���ڵݹ�Ĺ鲢�����Զ����£�
void mergeSort(int arr[], int low, int high) { //0 <= lo <= hi <= size-1
    if (low >= high) { return; } //��ֹ�ݹ������,�����г���Ϊ1
//    ���ڵݹ�鲢������Ż�����:
//    �Ż�һ����С��ģ������ʹ�ò�������
//    �ò�ͬ�ķ�������С��ģ�����ܸĽ�������ݹ��㷨������
//    ��Ϊ�ݹ��ʹС��ģ�����з�������̫��Ƶ��,���ԸĽ������ǵĴ��������ܸĽ������㷨
//    ��Ϊ��������ǳ���,���һ����˵��С�����ϱȹ鲢�������,�����Ż���ʹ�鲢���������ʱ������10%��15%
//    �� if (low >= high) { return; } ����:
//    if(high - low <= 10) { // ���鳤��С��10��ʱ��
//        InsertSort(int arr[], int low,int high) // �л�����������
//        return;
//    }
    int mid = low + ((high - low) >> 1);  //ȡ�������м��Ԫ��
    mergeSort(arr, low, mid);  //�����ߵݹ�
    mergeSort(arr, mid + 1, high);  //���Ұ�ߵݹ�
//    �Ż���: ���Դ��������������Ұ���Ƿ�������
//    ͨ�����Դ��������������Ұ���Ƿ��Ѿ�����,�����������±���ϲ������ĵ���
//    if(a[mid]<=a[mid+1]) return; // ���ⲻ��Ҫ�Ĺ鲢
    merge(arr, low, mid, high);  //�ϲ�
}
//    �Ż���:ȥ��ԭ�������е���������Ŀ��� //TODO: û����
//    ����:https://zhuanlan.zhihu.com/p/74820690
//    Java��:https://www.cnblogs.com/penghuwan/p/7940440.html#_label6_0


//2.����ѭ���Ĺ鲢�����Ե����ϣ�
//src/image/mergeSort_2.png
void mergeSort(int a[],int n) {
    int mid,high;
    for (int size = 1; size < n; size *= 2) {
        //  low+size=mid+1,Ϊ�ڶ���������һ��Ԫ�أ��� < N��ȷ�����һ�κϲ���2������
        for (int low = 0; low + size < n; low += 2 * size) {
            mid = low + size - 1;
            high = low + 2 * size - 1;
            if (high > n - 1) high = n - 1;
            merge(a, low, mid, high);
        }
    }
}