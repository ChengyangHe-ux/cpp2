#include <bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]){
                parent[rootY]=rootX;
            }else if(rank[rootX]<rank[rootY]){
                parent[rootX]=rootY;
            }else{
                parent[rootY]=rootX;
                rank[rootX]++;
            }
        }
    }
    bool isSameSet(int x,int y){
        return find(x)==find(y);
    }

};
int main(){
    int N,M;
    cin>>N>>M;

    DSU dsu(N);
    for(int i=0;i<M;i++){
        int Z,X,Y;
        cin>>Z>>X>>Y;
        if(Z==1){
            dsu.unite(X,Y);
        }else if(Z==2){
            if(dsu.isSameSet(X,Y)){
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
    }



    return 0;
}