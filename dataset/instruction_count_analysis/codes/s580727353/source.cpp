#include <iostream>

#include <vector>

#include <algorithm>

#include <string>

#include <map>

#include <cmath>

#include <queue>

#include <numeric>

#include <climits>

#include <iterator>

#include <iomanip>

#include <stack>

#include <set>

#include <cstdio>

#include <bitset>

#include <functional>

#include <tuple>

#include <list>

#include <deque>

#include <sstream>

using namespace std;

const constexpr int INF = 1e9;

#define FOR(i, a, n) for (ll i = (ll)a; i<(ll)n; ++i)

#define REP(i, n) FOR(i, 0, n)



typedef long long ll;

typedef vector<int> VI;

const constexpr ll MOD = 1e9+7;

struct Less{

   bool operator()(const pair<string, int>&a, const pair<string, int>&b){

        if(a.first==b.first){

            return a.second < b.second;

        }

       return a.first < b.first;

    }

};



ll extGCD(ll a, ll b, ll& x, ll& y){

    if(b==0){

        x=1;

        y=0;

        return a;

    }

    ll d = extGCD(b, a%b, y, x);

    y -= a/b*x;

    return d;

}

ll GCD(ll a, ll b){

    if(a<b) swap(a, b);

    if(b==0) return a;

    return GCD(b, a%b);

}

int par[100010], rr[100010];

void init(){

    for(int i=0; i<100010; ++i){

        par[i]=i;

        rr[i]=0;

    }

}

int root(int x){

    return par[x] == x ? x:par[x] = root(par[x]);

}

bool same(int x, int y){

    return root(x)==root(y);

}

void unite(int x, int y){

    x = root(x);

    y = root(y);

    if(x==y) return ;

    

    if(rr[x]<rr[y]){

        par[x] = y;

    }else{

        par[y] = x;

        if(rr[x]==rr[y]) rr[x]++;

    }

}



ll pow_mod(ll x, ll n){

    ll res = 1;

    while(n>0){

        if(n&1){

            res = res*x%MOD;

        }

        x = x*x%MOD;

        n>>=1;

    }

    return res;

}

int p[11], c[11];

int main() {

    int D, G; cin >> D >> G;

    REP(i, D) cin >> p[i] >> c[i];

    

    int minV=INF;

    for(int bit=0; bit<(1<<D); ++bit){

        int sum=0;

        int cnt=0;

        for(int i=0; i<D; ++i) {

            if(1&(bit>>i)){ 

                sum += 100*(i+1)*p[i]+c[i];

                cnt += p[i];

            }

        }

        if(sum>=G){

            minV = min(minV, cnt);

        }else{

            int max_idx=0;

            for(int i=0; i<D; ++i){

                if(1&(bit>>i)) continue;    

                max_idx=i;

            }

            

            for(int i=0; i<p[max_idx]; ++i){

                if(sum+100*(max_idx+1)*i>=G){

                    minV = min(minV, cnt+i);

                }

            }

        }

    }

    cout << minV << endl;

    return 0;

}