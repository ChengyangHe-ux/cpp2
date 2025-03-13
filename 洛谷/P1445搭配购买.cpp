#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node{
    int money;
    int value;
};

// 并查集结构
class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路径压缩
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main(){
    int n,m,w;
    cin>>n>>m>>w;
    //存储数据
    vector<Node> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i].money;
        cin>>s[i].value;
    }
    map<int,int> must;
    for(int i=0;i<m;i++){
        int x1,x2;
        cin>>x1>>x2;
        must[x1]=x2;
    }

    // 初始化并查集
    UnionFind uf(n);
    for (const auto& p : must) {
        uf.unite(p.first - 1, p.second - 1); // 假设输入的物品编号是从1开始的
    }

    return 0;
}