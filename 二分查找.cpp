#include<iostream>
using namespace std;

int BinarySearch1(int* a, int left, int right, int x){
    while(left < right){
        int mid = left + right >> 1;
        if(a[mid] >= x) right = mid;
        else left = mid + 1;
    }
    if(a[left] != x) return -1;
    return left;
}

int BinarySearch2(int* a, int left, int right, int x){
    while(left < right){
        int mid = left + right + 1 >> 1;
        if(a[mid] <= x) left = mid;
        else right = mid - 1;
    }
    if(a[left] != x) return -1;
    return left;
}

double my_sqrt(double x){
    if(x <= 0) return 0; 
    double l = 0, r = x;
    if(r < 1) r = 1;
    while(r - l > 1e-6){
        double mid = (l + r) / 2;
        if(mid * mid >= x) r = mid;
        else l = mid;
    }
    return l;
}

int main(){

    int a[] = {1,2,3,4,5,6,8,10,12};
    int ret1 = BinarySearch1(a, 0, 8, 10);
    int ret2 = BinarySearch2(a, 0, 8, 10);

    cout << ret1 << " " << ret2 << endl;
    cout << my_sqrt(0.01) << endl;

    return 0;
}