#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const int INF = 1000000001;
const ll mod = 1e9 + 7;

//O(√N)の素因数分解関数
//典型90:No.75より
vector<ll> primeFactors(ll N){
    vector<ll> ans;
    ll n = N;
    for(ll i = 2; i*i <= N; i++){
        while (n%i == 0)
        {
            n /= i;
            ans.push_back(i);
        }
    }

    if(n != 1LL){
        ans.push_back(n);
    }
    return ans;
}

int main(){
    ll N;
    cin >> N;

    for(auto x : primeFactors(N)){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}