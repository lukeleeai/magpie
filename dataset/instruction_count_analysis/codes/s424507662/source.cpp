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



ll dfs(ll n_i, ll l_a, ll l_b, ll l_c){

    if(n_i >= n){

        //無から竹は作れない

        if(l_a*l_b*l_c == 0){

            return INF;

        }

        //合成魔法は使う本数−１*10のコストがかかる

        //合成した後の誤差は延長，短縮魔法を使う

        ll res = abs(a - l_a) + abs(b - l_b) + abs(c - l_c) - 30;

        return res;

    }



    ll res = INF;

    //使わない場合

    res = min(res, dfs(n_i+1, l_a, l_b, l_c));

    //A~Bいずれかに使う場合

    res = min(res, dfs(n_i+1, l_a+l[n_i], l_b, l_c) + 10);

    res = min(res, dfs(n_i+1, l_a, l_b+l[n_i], l_c) + 10);

    res = min(res, dfs(n_i+1, l_a, l_b, l_c+l[n_i]) + 10);



    return res;

}



int main(){

    cin >> n >> a >> b >> c;

    

    rep(i, n)cin >> l[i];



    cout << dfs(0, 0, 0, 0) << endl;

}