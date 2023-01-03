#include<iostream>
using namespace std;

const int N = 1000;
int a[N] = {1, 2, 2, 3, 5}, b[N];

int main(){ 

    // 最长连续不重复子序列
    int n = 5;
    int ret = 0;
    for(int i = 0, j = 0; i < n; i++){
        b[a[i]]++;
        while(b[a[i]] > 1) b[a[j++]]--;
        ret = max(ret, i - j + 1);
    }

    cout << ret << endl;

    return 0;
}