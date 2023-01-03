#include<iostream>
using namespace std;

int const N = 1000;
int a[N][N], s[N][N];

int main(){
    
    int m = 3, n = 4;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = i * j;
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    int x1 = 2, y1 = 2, x2 = 3, y2 = 3;
    cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;

    return 0;
}