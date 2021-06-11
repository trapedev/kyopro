#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const ll mod = 1e9 + 7;
const int INF = 1000000001;
using Graph = vector<vector<int>>;

void bitFullReserch(int N){
    //{0, 1, 2, ... , N - 1}のN 個の部分集合を二進数で考える
    for(int bit = 0; bit < (1 << N); bit++){
        //整数値から「幾つか選ぶ方法」への復元
        for(int i = 0; i < N; i++){
            //iビット目のフラグが立っているかの判断
            //ここではiを選択するかの判定：iがbitに含まれているときtrue、そうでないときfalse
            if(bit & (1 << i)){

            }
        }
    }
}

int main(){
    return 0;
}