#include<iostream>
using namespace std;

int const N = 1000;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main(){

    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++) a[i][j] = i * j;
    }

    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++) insert(i, j, i, j, a[i][j]);
    }

    insert(1, 1, 10, 10, 1);
    
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++) 
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    }

    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}