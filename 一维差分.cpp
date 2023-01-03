#include<iostream>
using namespace std;

const int N = 1000;
int a[N], b[N];

void insert(int l, int r, int c){
    b[l] += c;
    b[r + 1] -= c;
}

int main(){

    for(int i = 1; i <= 10; i++) a[i] = i;
    for(int i = 1; i <= 10; i++) insert(i, i, a[i]);
    // for(int i = 1; i <= 10; i++) b[i] = a[i] - a[i - 1];

    insert(1, 10, 1);
    for(int i = 1; i <= 10; i++) b[i] += b[i - 1];
    for(int i = 1; i <= 10; i++) cout << b[i] << " ";

    return 0;
}