#include <bits/stdc++.h>
using namespace std;
const int N=1000;
int parent[N];
void init(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
}
int find(int x){
    while(x!=parent[x]){
        x=parent[x];
    }
    return x;
}
void union_sets(int a,int b){
    int rootA=find(a);
    int rootB=find(b);
    if(rootA!=rootB){
        parent[rootA]=rootB;
    }
}
int main(){
    return 0;
}