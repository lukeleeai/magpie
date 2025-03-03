#include<iostream>

#include<vector>

#include<algorithm>

#include<cctype>

#include<utility>

#include<string>

#include<cstring>

#include<cmath>

#include <numeric>

#include<queue>

#include<climits>





#define REP(i, n) for(int i = 0;i < n;i++)

#define REPR(i, n) for(int i = n;i >= 0;i--)

#define FOR(i, m, n) for(int i = m;i < n;i++)

#define FORR(i, m, n) for(int i = m;i >= n;i--)

#define SORT(v, n) sort(v, v+n);

#define VSORT(v) sort(v.begin(), v.end());

#define llong long long

#define pb(a) push_back(a)

#define INF ((LLONG_MAX) / (2))

using namespace std;

typedef pair<int, int> P;

typedef pair<llong, llong> LP;

typedef pair<int, P> PP;

typedef pair<llong, LP> LPP;

typedef long long int ll;

typedef pair<ll,int> LL_IP;



//#define INF 3e9



#define MAX_V 110

#define MAX_E 10000



typedef struct edge{

    ll from;

    ll to;

    ll cost;

}EDGE;





/*頂点sから各頂点への最短距離を求めること、頂点sから到達できる負閉路があれば真が返る、目的地が決まっていないバージョン*/

/*V-1回の更新で各ノードへの最短距離は求められるが、V回目の更新が起こった場合は負閉路が存在していることになる*/

bool shortest_path(ll v,ll e,ll s,vector<EDGE>& arr,vector<ll>& d){

    /*頂点の個数、辺の個数、始点となる頂点、辺の情報、最短距離*/

    for(ll i = 0;i < d.size();i++){

        d[i] = INF;

    }

    d[s]=0;

    

    for(ll i = 0;i < v;i++){

        for(ll j = 0;j < e;j++){

            EDGE tmp = arr[j];

            if(d[tmp.from] != INF && d[tmp.to] > d[tmp.from] + tmp.cost){

                d[tmp.to] = d[tmp.from] + tmp.cost;

                if(i == v-1){

                    return true;

                }



            }

        }

    }

    return false;

}





/*負のコストがあるか調べる（蟻本）*/

/*これは始点から到達可能か否かに関わらずグラフ内に負閉路が存在するときに真が返る*/

bool find_nagative_loop(ll v,ll e,vector<EDGE>& arr,vector<ll>& d){

    /*頂点の個数、辺の個数、辺の情報、最短距離*/

    //全ての最短経路を0で初期化

    for(ll i = 0;i < d.size();i++){

        d[i] = 0;

    }



    for(ll i = 0;i < v;i++){

        for(ll j = 0;j < e;j++){

            EDGE tmp = arr[j];

            if(d[tmp.to] > d[tmp.from] + tmp.cost){

                d[tmp.to] = d[tmp.from] + tmp.cost;

                if(i == v-1){

                    return true;

                }

            }

        }

    }

    return false;

}





int main(){



    ll v,e;/*v:頂点の個数、e:辺の個数、r:始点となる頂点の番号*/

    cin >> v >> e;

    vector<EDGE> arr(MAX_E);/*辺の情報を格納*/

    vector<ll> d(MAX_V,0);/*負の閉路があるかの判定、0で初期化*/



    REP(i,e){

        cin >> arr[i].from >> arr[i].to >> arr[i].cost;

    }



    bool exist_negative_cycle = find_nagative_loop(v,e,arr,d);/*ここでは負閉路があるかどうかを判定する*/

    if(exist_negative_cycle){

        /*負の閉路が存在する場合*/

        cout << "NEGATIVE CYCLE" << endl;

    }else{

        /*負閉路がないので各頂点からの最短距離を求める*/

        for(ll i = 0;i < v;i++){



            shortest_path(v,e,i,arr,d);



            for(ll i = 0;i < v;i++){

                if(i == 0){

                    /*最初の出力のみ*/

                    if(d[i] == INF){

                        cout << "INF";

                    }else{

                        cout << d[i];

                    }

                }else{

                    if(d[i] == INF){

                        cout << " " << "INF";

                    }else{

                        cout << " " << d[i];

                    }

                }

               

            }

            cout << endl;

        }

    }

    return 0;

}
