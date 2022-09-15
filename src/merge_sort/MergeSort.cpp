#include <iostream>
#include <algorithm>
#include "MergeSort.h"

using namespace std;

//���ڵݹ�Ĺ鲢�����Զ����µĹ鲢����

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
    delete [] temp; //�ͷ��ڴ�,����ָ���������,������delete []
}

//�����鲢����:
void MergeSort(int arr[], int low, int high) { //0 <= lo <= hi <= size-1
    if (low >= high) { return; } //��ֹ�ݹ������,�����г���Ϊ1

//    �Ż�һ����С��ģ������ʹ�ò�������
//    �ò�ͬ�ķ�������С��ģ�����ܸĽ�������ݹ��㷨������
//    ��Ϊ�ݹ��ʹС��ģ�����з�������̫��Ƶ��,���ԸĽ������ǵĴ��������ܸĽ������㷨
//    ��Ϊ��������ǳ���,���һ����˵��С�����ϱȹ鲢�������,�����Ż���ʹ�鲢���������ʱ������10%��15%
//    �� if (low >= high) { return; } ����:
//    if(high - low <= 10) { // ���鳤��С��10��ʱ��
//        InsertSort(int arr[], int low,int high) // �л�����������
//        return;
//    }

    int mid = low + (high - low) / 2;  //ȡ�������м��Ԫ��
    MergeSort(arr, low, mid);  //�����ߵݹ�
    MergeSort(arr, mid + 1, high);  //���Ұ�ߵݹ�

//    �Ż���: ���Դ��������������Ұ���Ƿ�������
//    ͨ�����Դ��������������Ұ���Ƿ��Ѿ�����,�����������±���ϲ������ĵ���
//    if(a[mid]<=a[mid+1]) return; // ���ⲻ��Ҫ�Ĺ鲢

    merge(arr, low, mid, high);  //�ϲ�
}
