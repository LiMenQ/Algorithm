#include<iostream>
#include<vector>
using namespace std;

vector<int> mul(vector<int>& A, int b){
    vector<int> C;
    if(b == 0){
        C.push_back(0);
        return C;
    }
    int t = 0;
    for(int i = 0; i < A.size() || t; i++){
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

int main(){

    string a = "1314521435";
    int b = 42;
    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    vector<int> C = mul(A, b);
    for(int i = C.size() - 1; i >= 0; i--) cout << C[i];

    return 0;
}