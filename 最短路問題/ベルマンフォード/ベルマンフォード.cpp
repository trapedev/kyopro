#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const ll mod = 1e9 + 7;
//const int INF = 1000000001;
//using Graph = vector<vector<int>>;

//無限大を表す値
const ll INF = 1LL << 60;

//辺を表す型、ここでは重みを表す型をlong long型とする
struct Edge
{
    int to; //隣接頂点番号
    ll w; //重み
    Edge(int to, ll w) : to(to), w(w) {}
};

//重み付きグラフを表す型
using Graph = vector<vector<Edge>>;

//緩和を実施する関数
template<class T>bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    else return false;
}

int main(){
    //頂点数、辺数、始点
    int N, M, s;
    cin >> N >> M >> s;

    //グラフ
    Graph G(N);
    for(int i = 0; i < M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        G[a].push_back(Edge(b, w));
    }

    //ベルマンフォード法
    bool exist_negative_cycle = false; //負閉路をもつかどうか
    vector<ll> dist(N, INF);
    dist[s] = 0;
    for(int iter = 0; iter < N; iter++){
        bool update = false; //更新が発生したか否かを表すフラグ
        for(int v = 0; v < N; v++){
            //dist[v] = INFの時の頂点vからの緩和を行わない
            if(dist[v] == INF){
                continue;
            }
            for(auto e : G[v]){
                //緩和処理を行い、更新されたらupdateをtrueにする
                if(chmin(dist[e.to], dist[v] + e.w)){
                    update = true;
                }
            }
        }

        //更新が行われなかったら、既に最短路が求められている
        if(!update){
            break;
        }

        //N回目の反復で更新が行われたならば、負閉路をもつ
        if(iter == N - 1 && update){
            exist_negative_cycle = true;
        }
    }

    //結果出力
    if(exist_negative_cycle){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        for(int v = 0; v < N; v++){
            if(dist[v] < INF){
                cout << dist[v] << endl;
            }
            else{
                cout << "INF" << endl;
            }
        }
    }
    return 0;
}