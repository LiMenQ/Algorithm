#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 假定有一个无限长的数轴，数轴上每个坐标上的数都是 0。
// 现在，我们首先进行 n 次操作，每次操作将某一位置 x 上的数加 c。
// 接下来，进行 m 次询问，每个询问包含两个整数 l 和 r，你需要求出在区间 [l,r] 之间的所有数的和。

typedef pair<int, int> PII;
int const N = 3 * 1e5 + 10;
int a[N], s[N];
vector<int> C;
vector<PII> add, query;

vector<int>::iterator unique(vector<int>& C){
    int j = 1;
    for(int i = 1; i < C.size(); i++){
        if(C[i] != C[i - 1]) C[j++] = C[i];
    }
    return C.begin() + j;
}

int find(int x){
    int l = 0, r = C.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(C[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1; // 方便前缀和
}

int main(){

    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        C.push_back(x);
    }

    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        C.push_back(l);
        C.push_back(r);
    }
    
    // 对数组排序 去重
    sort(C.begin(), C.end());
    C.erase(unique(C), C.end());

    for(auto item : add){
        int x = find(item.first);
        a[x] += item.second;
    }
    
    for(int i = 1; i <= C.size(); i++){
        s[i] = s[i - 1] + a[i];
    }

    for(auto item : query){
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}