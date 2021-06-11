#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const ll mod = 1e9 + 7;
const int INF = 1000000001;
using Graph = vector<vector<int>>;

struct UnionFind
{
    vector<int> par, siz;
    
    //初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) { }
    
    //根を求める
    int root(int x) {
        if (par[x] == -1){
            return x;
        }
        else{
            return par[x] = root(par[x]);
        }
    }
    
    //xとyが同じグループに属するかどうか（根が一致するかどうか）
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    //xを含むグループと、yを含むグループの併合
    bool unite(int x, int y) {
        x = root(x); 
        y = root(y);
        if(x == y){
            return false;
        }

        if(siz[x] < siz[y]){
            swap(x, y);
        }
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    
    //xを含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }

};


int main(){
    return 0;
}