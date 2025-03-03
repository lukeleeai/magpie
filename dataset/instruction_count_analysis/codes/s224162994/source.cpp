#include <iostream>

#include <string>

#include <vector>

#include <queue>

#include <set>

#include <map>

#include <utility>

#include <stack>

#include <numeric>

#include <algorithm>

#include <tuple>

#include <stdio.h>

#include <bitset>

#include <limits.h>

#include <complex>

#include <deque>

#include <iomanip>

#include <list>

#include <cstring>

using namespace std;

#define pi pair<int,int>

#define pl pair<long long,long long>

#define chmax(a,b) (a<b ? a=b:0)

#define chmin(a,b) (a>b ? a=b:0)

#define en cout << endl //セミコロンつけろ

//#define MM 1000000000

//#define MOD MM+7

typedef long long ll;

const int MM = 1e9;

const int MOD = MM+7;

const long double PI = acos(-1);

const long long INF = 1e15;

int dx[8] = {-1,0,1,0,-1,-1,1,1};

int dy[8] = {0,-1,0,1,-1,1,1,-1};

// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

template<typename T>

T GCD(T u,T v){

    return v ? GCD(v,u%v) : u;

}

template<typename T>

T LCM(T x,T y){

    T gc = GCD(x,y);

    return x*y/gc;

}

void Exit(){

    cout << -1 << endl;

    exit(0);

}





vector<vector<int> > g;

vector<int> dp,ckd;



auto func(int crr){

    if (ckd.at(crr) == 2) return dp.at(crr);

    ckd.at(crr) = 1;

    for (auto nxt : g[crr]){

        if (ckd[nxt] == 1) Exit();

        dp[crr] = max(dp[crr],func(nxt) + 1);

    }

    ckd[crr] = 2;

    return dp[crr];

}



auto encode(int i,int j){

    if (i < j) swap(i,j);

    return i*(i-1)/2 + j + 1;

}



int main(){

    int n; cin >> n;

    auto N = n*(n-1)/2;

    g.resize(N+1);

    for (int i = 0; i < n; i++){

        auto prev = 0;

        for (int j = 0; j < n-1; j++){

            int x; cin >> x; x--;

            auto crr = encode(i,x);

            g[prev].emplace_back(crr);

            prev = crr;

        }

    }

    dp.resize(N+1,0);

    ckd.resize(N+1,0);

    auto ret = func(0);

    cout << ret << endl;

}
