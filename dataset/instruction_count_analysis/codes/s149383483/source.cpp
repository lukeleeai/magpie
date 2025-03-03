#include<iostream>

#include<stdio.h>

//#include "stdc++.h"

#include<vector>

#include<float.h>

#include<iomanip>

#include<algorithm>

#include<string>

#include<cstring>

#include<math.h>

#include<cmath>

#include<sstream>

#include<set>

#include<map>

#include<queue>

#include <cassert>

#include <cmath>

#include<cstdint>



#define INF 1e9

#define rep(i,n)for(int i=0;(i)<(int)(n);i++)

#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)

#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;

#define vec(type,n) vector<type>(n)

#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))

#define ALL(a)  (a).begin(),(a).end()



using namespace std;

using ll = long long;

using Graph = vector<vector<int>>;

using P = pair<ll, ll>;



ll cnt;

Graph G(200000);

vector<int> mem;

vector<int> seen(200000);



ll s, e;

void dfs(int v){

    cnt++;

    if(seen[v] > 0){

        s = seen[v];

        e = cnt;

        return;

    }

    seen[v] = cnt;

    mem.push_back(v);

    dfs(G[v][0]);

}



int main(){

    ll n, k;

    cin >> n >> k;

    rep(i, n){

        int a;

        cin >> a;

        a--;

        G[i].push_back(a);

    }

    dfs(0);

    s--;

  	k -= s;

    if(k < 0){

        k += s;

        cout << mem[k] + 1;

        return 0;

    }

  	k %= (e - s - 1);

  	cout << mem[s + k] + 1; 

}


