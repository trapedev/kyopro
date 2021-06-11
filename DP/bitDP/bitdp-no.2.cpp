#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const ll mod = 1e9 + 7;
const int INF = 1000000001;
using Graph = vector<vector<int>>;

//入力
int n, m, a, b;
int t[30];
int d[30][30];

//dp[S][v] : 残っている乗車券がS、現在位置vという状態に至るまでの最小コスト
double dp[1 << 10][30];

void solve(){
    for(int i = 0; i < (1 << n); i++){
        //十分大きな値で初期化
        fill(dp[i], dp[i] + m, INF);
    }

    dp[(1 << n) - 1][a - 1] = 0;
    double res = INF;

    for(int S = (1 << n) - 1; S >= 0; S--){
        res = min(res, dp[S][b - 1]);
        for(int v = 0; v < m; v++){
            for(int i = 0; i < n; i++){
                if(S >> i & 1){
                    for(int u = 0; u < m; u++){
                        if(d[v][u] >= 0){
                            //乗車券iを使って、vからuへ移動
                            dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + (double)d[v][u] / t[i]);
                        }
                    }
                }
            }
        }
    }
    if(res == INF){
        cout << "Impossible" << endl;
    }
    else{
        printf("%.3f\n", res);
    }
}

int main(){
    return 0;
}