#include<iostream>
using namespace std;

int const N = 10;
int a[N] = {2,3,6,7,8,9,10,4,1,5}, tmp[N];

void MergeSort(int* a, int left, int right){
    if(left >= right) return;
    int mid = left + right >> 1;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    
    int i = left, j = mid + 1, k = 0;

    while(i <= mid && j <= right){
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }

    while(i <= mid) tmp[k++] = a[i++];
    while(j <= right) tmp[k++] = a[j++];
    
    for(i = left, k = 0; i <= right; i++, k++) a[i] = tmp[k];
}

int main(){

    MergeSort(a, 0, 9);

    for(int i = 0; i < 10; i++)
        cout << a[i] << " ";

    return 0;
}