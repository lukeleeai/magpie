#include "stdc++.h"

 

#define rep(i,n) for(ll i=0;i<n;++i)

#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)

#define ALL(a) (a).begin(),(a).end()



using namespace std;

using ll  = long long;

using pll = pair<ll, ll>;



const ll MOD  = 1e9 + 7;

const ll LINF = 1LL << 62;

const int INF = 1e9 + 7;



ll n, a, b, c;

vector<ll> l(10);



//long to binary

string ternary(ll n){

    if(n == 2)return "2";

    else if(n == 1)return "1";

    else if(n == 0)return "0";



    return ternary(n/3)  + ternary(n%3);

}



ll dfs(ll n_i, string ter, vector<ll> cost, vector<ll> len){

    if(n_i >= n){

        //無から竹は作れない

        if(len[0]*len[1]*len[2] == 0){

            return INF;

        }

        //合成魔法は使う本数−１*10のコストがかかる

        rep(i, 3)cost[i] = 10 * max((ll)0, cost[i]-1);

        ll res = cost[0] + cost[1] + cost[2];



        //合成した後の誤差は延長，短縮魔法を使う

        res += abs(a - len[0]) + abs(b - len[1]) + abs(c - len[2]);

        return res;

    }



    string ter_bit = "012"; 

    ll res = INF;

    //使わない場合

    res = min(res, dfs(n_i+1, ter, cost, len));

    rep(i, 3){

        if(ter[n_i] == ter_bit[i]){

            //合成する場合

            cost[i]++;

            len[i] += l[n_i];

            res = min(res, dfs(n_i+1, ter, cost, len));

        }

    }



    return res;

}



int main(){

    cin >> n >> a >> b >> c;

    

    rep(i, n)cin >> l[i];



    ll ans = INF;

    vector<ll> cost(3, 0), len(3, 0);

    rep(i, pow(3, n)){

        //3進数，０〜２が竹A~Cに対応

        string ter = ternary(i);

        while(ter.size() != n)ter = '0' + ter;

        ans = min(ans, dfs(0, ter, cost, len));

    }



    cout << ans << endl;

}