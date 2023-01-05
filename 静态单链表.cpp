#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int head, index, a[N], n[N];

void init(){
    head = -1;
    index = 0;
}

void insert_head(int x){
    a[index] = x;
    n[index] = head;
    head = index++;
}

// k下标的数后面插入x  k >= 0
void insert_node(int k, int x){
    a[index] = x;
    n[index] = n[k];
    n[k] = index++;    
}

// 删除k下标的数后面的数 k == -1 删除头指针
void remove_node(int k){
    if(k == -1){
        head = n[head];
        return;
    }
    n[k] = n[n[k]];
}

int main(){

    init();
    insert_head(9);
    insert_node(0, 1);
    remove_node(0);
    remove_node(-1);
    insert_head(6);
    insert_node(2, 6);
    insert_node(3, 5);
    insert_node(3, 5);
    insert_node(2, 4);
    remove_node(5);

    for(int i = head; i != -1; i = n[i]){
        cout << a[i] << " ";
    }

    return 0;
}