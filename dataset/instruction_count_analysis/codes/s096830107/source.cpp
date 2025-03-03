/*

これを入れて実行

g++ code.cpp

./a.out

 */

 

#include <iostream>

#include <cstdio>

#include <stdio.h>

#include <vector>

#include <string>

#include <cstring>

#include <queue>

#include <deque>

#include <stack>

#include <algorithm>

#include <utility>

#include <set>

#include <map>

#include <unordered_map>

#include <unordered_set>

#include <cmath>

#include <math.h>

#include <tuple>

#include <iomanip>

#include <bitset>

#include <functional>

#include <cassert>

#include <random>



#define all(x) (x).begin(),(x).end()

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 

using namespace std;

typedef long long ll;

typedef long double ld;

 

int dy4[4] = {-1, 0, +1, 0};

int dx4[4] = {0, +1, 0, -1};

int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

 

const long long INF = 1LL << 60;

const ll MOD = 1e9 + 7;

 

bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){

    return f.second > s.second;

}

 

ll gcd(ll a, ll b){

	if (b == 0)return a;

	return gcd(b, a % b);

}

 

ll lcm(ll a, ll b){

    return a / gcd(a, b) * b;

}



ll conbinationMemo[100][100];



void cmemoInit(){

    rep(i, 100){

        rep(j, 100){

            conbinationMemo[i][j] = -1;

        }

    }

}

 

ll nCr(ll n, ll r){

    if(conbinationMemo[n][r] != -1) return conbinationMemo[n][r];

    if(r == 0 || r == n){

        return 1;

    } else if(r == 1){

        return n;

    }

    return conbinationMemo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1));

}

 

ll nPr(ll n, ll r){

    r = n - r;

    ll ret = 1;

    for (ll i = n; i >= r + 1; i--) ret *= i;

    return ret;

}

//-----------------------ここから-----------

struct LazySegmentTree{

    ll segTreeSize = 1;

    vector<ll> node;

    vector<ll> lazy;

    vector<bool> lazyf;



    void initRSQ(vector<ll> vec){

        while(segTreeSize < (ll)vec.size()){

            segTreeSize *= 2;

        }

        node.resize(2 * segTreeSize - 1, 0);

        lazy.resize(2 * segTreeSize - 1, 0);

        for(ll i = 0; i < (ll)vec.size(); i++){

            node[i + segTreeSize - 1] = vec[i];

        }

        for(ll i = segTreeSize - 2; i >= 0; i--){

            node[i] = node[2 * i + 1] + node[2 * i + 2];

        }

    }





    void evalRSQ(ll idx, ll l, ll r){

        if(lazy[idx] != 0){

            node[idx] += lazy[idx];

            if(r - l > 1){

                lazy[2*idx+1] += lazy[idx] / 2;

                lazy[2*idx+2] += lazy[idx] / 2;

            }

            lazy[idx] = 0;

        }

    }





    void updateRSQ(ll l, ll r, ll val, ll idx = 0, ll nowl = 0, ll nowr = -1){

        if(nowr < 0) nowr = segTreeSize;



        evalRSQ(idx, nowl, nowr);



        if(r <= nowl || nowr <= l) return;



        if(l <= nowl && nowr <= r){

            lazy[idx] = (nowr - nowl) * val;

            evalRSQ(idx, nowl, nowr);

        } else {

            updateRSQ(l, r, val, 2*idx+1, nowl, (nowl+nowr)/2);

            updateRSQ(l, r, val, 2*idx+2, (nowl + nowr) / 2, nowr);

            node[idx] = node[2*idx+1] + node[2*idx+2];

        }

    }

    void addRSQ(ll l, ll r, ll val, ll idx = 0, ll nowl = 0, ll nowr = -1){

        if(nowr < 0) nowr = segTreeSize;



        evalRSQ(idx, nowl, nowr);



        if(r <= nowl || nowr <= l) return;



        if(l <= nowl && nowr <= r){

            lazy[idx] += (nowr - nowl) * val;

            evalRSQ(idx, nowl, nowr);

        } else {

            addRSQ(l, r, val, 2*idx+1, nowl, (nowl+nowr)/2);

            addRSQ(l, r, val, 2*idx+2, (nowl + nowr) / 2, nowr);

            node[idx] = node[2*idx+1] + node[2*idx+2];

        }

    }





    ll getRSQ(ll l, ll r, ll idx = 0, ll nowl = 0, ll nowr = -1){

        if(nowr < 0) nowr = segTreeSize;

        if(r <= nowl || nowr <= l) return 0;



        evalRSQ(idx, nowl, nowr);

        if(l <= nowl && nowr <= r){

            return node[idx];

        }



        return getRSQ(l, r, 2*idx+1, nowl, (nowl + nowr)/2) + getRSQ(l, r, 2*idx+2, (nowl + nowr)/2, nowr);

    }

};

ll mod = 998244353;

int main(void){

    ll n, k;

    cin >> n >> k;

    vector<pair<ll,ll>> vec;

    rep(i, k){

        ll l, r;

        cin >> l >> r;

        vec.push_back({l, r});

    }

    sort(all(vec));



    LazySegmentTree s;

    vector<ll> tmp(n, 0);

    tmp[0] = 1;

    s.initRSQ(tmp);

    rep(i, n){

        ll now = s.getRSQ(i, i + 1);

        now %= mod;

        //cout << "now" << now << endl;

        rep(j, k){

            if(i + vec[j].first >= n) break;

            //cout << j << endl;

            s.addRSQ(i + vec[j].first, min(n, i + vec[j].second + 1), now);

        }

    }

    cout << s.getRSQ(n - 1, n) % mod << endl;

}


