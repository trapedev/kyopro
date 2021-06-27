#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const ll mod = 1e9 + 7;
const int INF = 1000000001;
using Graph = vector<vector<int>>;

//https://qiita.com/drken/items/4a7869c5e304883f539b#3-%E6%B7%B1%E3%81%95%E5%84%AA%E5%85%88%E6%8E%A2%E7%B4%A2-dfs-%E3%81%A8%E5%B9%85%E5%84%AA%E5%85%88%E6%8E%A2%E7%B4%A2-bfs
//https://qiita.com/drken/items/a803d4fc4a727e02f7ba

vector<bool> seen;
vector<int> first_order; //行きがけ順
vector<int> last_order; //帰りがけ順

//dfsのテンプレ
void dfs(const Graph &G, int v){

    seen[v] = true; //vを訪問済みにする

    //vからいける各頂点next_vについて
    for(auto next_v : G[v]){
        if(seen[next_v]){
            //next_vが訪問済みだったらスルー
            continue;
        }
        //再帰的に探索
        dfs(G, next_v);
    }
}

//行きがけ順と帰りがけ順を考慮したdfs
/*
void dfs(const Graph &G, int v, int& first_ptr, int& last_ptr){
    //行きがけ順をインクリメントしながらメモ
    first_order[v] = first_ptr++;

    seen[v] = true; //vを訪問済みにする

    //vからいける各頂点next_vについて
    for(auto next_v : G[v]){
        if(seen[next_v]){
            //next_vが訪問済みだったらスルー
            continue;
        }
        //再帰的に探索
        dfs(G, next_v, first_ptr, last_ptr);
    }

    //帰りがけ順をインクリメントしながらメモ
    last_order[v] = last_ptr++;
}
*/

int main(){
    //頂点数と辺数
    int N, M;
    cin >> N >> M;

    //グラフ入力受け取り(ここでは無向グラフを想定)
    Graph G(N);

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //頂点0をスタートとした探索
    seen.assign(N, false); //全頂点を「未訪問」に初期化
    dfs(G, 0);

    /*
    first_order.resize(N);
    last_order.resize(N);
    int first_ptr = 0, last_ptr = 0;
    dfs(G, 0, first_ptr, last_ptr);
    */

    return 0;
}