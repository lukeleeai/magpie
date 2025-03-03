#include "stdc++.h"

using namespace std;

#define N 100500

#define pb push_back

#define mp make_pair

#define fi first

#define se second

typedef long long ll;

const ll m = 1e9 + 7;

int n;

ll memo[N][5];

vector <int> adj[N];



ll mul(ll a , ll b) {

    return ((a % m) * (b % m)) % m;

}



ll add(ll a , ll b) {

    return ((a % m) + (b % m)) % m;

}



ll dp(int u , int color , int par) {

    ll &sol = memo[u][color];

    if (sol != -1) return sol;

    ll product = 1;

    for (int v : adj[u]) {

        if (v == par) continue;

        if (color == 0) {

            product = mul(product , add(dp(v , 0 , u) , dp(v , 1 , u)));

        } else {

            product = mul(product , dp(v , 0 , u));

        }

    }

    return sol = product;

}



int main() {

    scanf("%d" , &n);

    for (int i = 1 ; i < n ; i++) {

        int u,v; scanf("%d%d" , &u , &v);

        adj[u].pb(v);

        adj[v].pb(u);

    }

    memset (memo , -1 , sizeof memo);

    printf("%lld\n" , add(dp(1 , 0 , 1) , dp(1 , 1 , 1)));

}
