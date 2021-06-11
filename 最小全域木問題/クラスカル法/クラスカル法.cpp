#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const ll mod = 1e9 + 7;
const int INF = 1000000001;
using Graph = vector<vector<int>>;

struct UnionFind {
    vector<int> par, siz;
    
    UnionFind(int n) : par(n, -1), siz(n, 1) { }
    
    int root(int x) {
        if (par[x] == -1){
            return x;
        }
        else{
            return par[x] = root(par[x]);
        }
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
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
    
    int size(int x) {
        return siz[root(x)];
    }
};

using Edge = pair<int, pair<int, int>>;

int main(){
    //入力
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M); //辺集合
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u, v));
    }

    //各辺を、辺の重みが小さい順にソート
    //pairはデフォルトで(第1要素、第2要素)の辞書順比較
    sort(edges.begin(), edges.end());

    //クラスカル法
    ll res = 0;
    UnionFind uf(N);

    for(int i = 0; i < M; i++){
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        //辺(u,v)の追加によってサイクルが形成されるときは追加しない
        if(uf.issame(u, v)){
            continue;
        }

        //辺(u,v)を追加する
        res += w;
        uf.unite(u, v);
    }

    cout << res << endl;
    return 0;
}