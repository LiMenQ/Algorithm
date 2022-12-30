#include<iostream>
using namespace std;

void QuickSort(int* a, int left, int right){
    if(left >= right) return;
    int x = a[left + right >> 1];
    int i = left - 1, j = right + 1;
    while(i < j){
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) swap(a[i], a[j]);
    }
    QuickSort(a, left, j);
    QuickSort(a, j + 1, right);
}


int main(){

    int a[] = {6,5,4,2,1,0,9,3,7,8};
    QuickSort(a, 0, 9);

    for(int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}