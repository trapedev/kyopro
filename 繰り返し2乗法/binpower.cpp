#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const ll mod = 1e9 + 7;
const int INF = 1000000001;
using Graph = vector<vector<int>>;

//繰り返し二乗法
//https://atcoder.jp/contests/typical90/tasks/typical90_bq
int binpower(int a, ll b){
    int ans = 1;
    while (b != 0)
    {
        if(b%2 == 1){
            ans = (ll)(ans)*a%mod;
        }
        a = (ll)(a)*a%mod;
        b /= 2;
    }
    return ans;
}

int main(){
    ll N;
    int K;
    cin >> N >> K;
    if(K == 1){
        cout << (N == 1 ? 1 : 0) << endl;
    }
    else if(N == 1){
        cout << K%mod << endl;
    }
    else if(N == 2){
        cout << (ll)(K)*(K - 1)%mod << endl;
    }
    else{
        cout << (ll)(K)*(K - 1)%mod*binpower(K - 2, N - 2)%mod << endl;
    }
    return 0;
}