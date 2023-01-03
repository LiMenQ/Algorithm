#include<iostream>
using namespace std;

// [l, r] = S[r] - S[l - 1] (1 <= l r <= n)
int a[1000], s[1000];

int main(){

    for(int i = 1; i <= 10; i++) a[i] = i;
    for(int i = 1; i <= 10; i++) s[i] = s[i - 1] + a[i];
    
    int l = 1, r = 6;
    int res = s[r] - s[l - 1];
    cout << res << endl;

    return 0;
}