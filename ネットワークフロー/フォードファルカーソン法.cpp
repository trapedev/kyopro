#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const ll mod = 1e9 + 7;
//const int INF = 1000000001;
//using Graph = vector<vector<int>>;

//グラフを表す構造体
struct Graph
{
    //辺を表す構造体
    //rev:逆辺(to, from)がG[to]の中で何番目の要素か
    //cap:辺(from, to)の容量
    struct Edge
    {
        int rev, from, to, cap;
        Edge(int r, int f, int t, int c):
            rev(r), from(f), to(t), cap(c) {}
    };
    
    //隣接リスト
    vector<vector<Edge>> list;

    //N: 頂点数
    Graph(int N = 0): list(N) {}

    //グラフの頂点数取得
    size_t size(){
        return list.size();
    }

    //GraphインスタンスをGとして、
    //G.list[v]をG[v]とかけるようにしておく
    vector<Edge> &operator [] (int i){
        return list[i];
    }

    //辺e=(u, v)の逆辺(v, u)を取得する
    Edge& redge(const Edge &e){
        return list[e.to][e.rev];
    }

    //辺e=(u, v)に流量fのフローを流す
    //e=(u, v)の流量がfだけ減少する
    //この時逆辺(v, u)の流量を増やす
    void run_flow(Edge &e, int f){
        e.cap -= f;
        redge(e).cap += f;
    }

    //頂点fromから頂点toへ容量capの辺を張る
    //この時toからfromへも容量0の辺を張っておく
    void addedge(int from, int to, int cap){
        int fromrev = (int)list[from].size();
        int torev = (int)list[to].size();
        list[from].push_back(Edge(torev, from, to, cap));
        list[to].push_back(Edge(fromrev, to, from, 0));
    }
};

struct FordFulkerson{
    static const int INF = 1 << 30; //無限大を表す値を適切に
    vector<int> seen;

    FordFulkerson() {}

    //残余グラフ上でs-tパスを見つける(深さ優先探索)
    //返り値はs-tパス上の容量の最小値(見つからなかったら0)
    //f: sからvへ到達した過程の各辺の容量の最小値
    int fodfs(Graph &G, int v, int t, int f){
        //終端tに達したら到達したらリターン
        if(v == t) return f;

        //深さ優先探索
        seen[v] = true;
        for(auto &e : G[v]){
            if(seen[e.to]) continue;

            //容量0の辺は実際には存在しない
            if(e.cap == 0) continue;

            //s-tパスを探す
            //見つかったらflowはパス上の最小容量
            //見つからなかったらf = 0
            int flow = fodfs(G, e.to, t, min(f, e.cap));

            //s-tパスが見つからなかったら次辺を探す
            if(flow == 0) continue;

            //辺eに容量flowのフローを探す
            G.run_flow(e, flow);

            //s-tパスを見つかったらパス上最小容量を表す
            return flow;
        }

        //s-tパスが見つからなかったことを示す
        return 0;
    }

    //グラフGのs-t間の最大流量を求める
    //ただしリターン時にGは残余グラフになる
    int solve(Graph &G, int s, int t){
        int res = 0;

        //残余グラフにs-tパスが無くなるまで反復
        while (true)
        {
            seen.assign((int)G.size(), 0);
            int flow = fodfs(G, s, t, INF);

            //s-tパスが見つからなかったら終了
            if(flow == 0) return res;

            //答えを加算
            res += flow;
        }

        //no rearch
        return 0;
    }
};

int main(){
    //グラフの入力
    //N: 頂点数、M: 辺数
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for(int i = 0; i < M; i++){
        int u, v, c;
        cin >> u >> v >> c;

        //容量cの辺(u, v)を張る
        G.addedge(u, v, c);
    }

    //フォード・ファルカーソン法
    FordFulkerson ff;
    int s = 0, t = N - 1;
    cout << ff.solve(G, s, t) << endl;
    return 0;
}