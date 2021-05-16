#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const ll mod = 1e9 + 7;
const int INF = 1000000001;
using Graph = vector<vector<int>>;

//巡回セールスマン問題
/*
問題
頂点数nの重み付き有向グラフが距離行列d(i,j)として与えられる(辺がない場合はINF)。
頂点0からスタートして全ての頂点を丁度一度ずつめぐって帰ってくる閉路のうち、重みの
総和の最小値を求めなさい。

制約
・2≦n≦5
・0≦d(i,j)≦1000

考察
既に訪れた頂点集合(スタート地点0は未訪問とする)がS、現在vにいる状態から残りの全ての
頂点をめぐって頂点0に帰るようなパスの重みの総和の最小値をdp[S][v]とする。
vからはまだ訪れていない頂点u∉Sに移動する事ができるので、次の漸化式が成立する。

初めは0
・dp[V][0] = 0
遷移先のuから、未訪問の頂点を通って頂点0に帰るようなパスの重みの総和の最小値にv-u間の
重みを加算したものがdp[S][v]に相当するので、
・dp[S][v] = min(dp[S∪{u})[u] + d(v,u)|u∉S)
*/

//実装

//入力
int n;
int d[20][20];

//メモ化テーブル
int dp[1 << 20][20];

//既に訪れた頂点がS、現在位置がv
int rec(int S, int v){
    //既に訪れていて、値が定まっているならその値を返す
    if(dp[S][v] >= 0){
        return dp[S][v];
    }

    if(S == (1 << n) - 1 && v == 0){
        //全ての頂点を訪れて戻ってきた
        return dp[S][v] = 0;
    }

    int res = INF;

    //各頂点について調べる
    for(int u = 0; u < n; u++){
        //頂点uを訪れたことがない場合
        if(!(S >> u & 1)){
            //次にuに移動し、その最小値を取っていく
            res = min(res, rec(S | 1 << u, u) + d[v][u]);
        }
    }

    //dpテーブルに記録し、その値を返す
    return dp[S][v] = res;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, 0));
}

int main(){
    return 0;
}