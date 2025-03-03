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







int main(){

    int n, m;

    cin >> n >> m;

    vector<ll> v(n);

    map<ll, ll>mp;

    ll res = 0;

    rep(i, n){

        int a;

        cin >> a;

        if(i == 0)v[i] = a;

        else v[i] = v[i - 1] + a;

        v[i] %= m;

        mp[v[i]]++;

        if(v[i] == 0)res++;

    }

    for(auto m : mp){

        res += (m.second) * (m.second - 1) / 2;

    }

    cout << res << endl;

}
