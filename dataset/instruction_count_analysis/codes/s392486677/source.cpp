#include <stdio.h>

#include <iostream>

#include <algorithm>

#include <string>

#include <iomanip>

#include <math.h>

#include <utility>

#include <vector>

#include <map>

#include <unordered_map>

#include <cstdlib>

#include <stack>

#include <queue>

#define div1 1000000007

const long long INF = 1LL << 60;

using namespace std;

using ll = long long;

using ld = long double;

// a>b -> a==b;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// a<b -> a==b;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(void)

{

    ll N, i, x, l, t, ans=0;

    

    cin >> N;



    vector<pair<ll,ll>> p(N);



    for(i=0; i<N; i++){

        cin >> x >> l;

        p[i].first = x+l; // 終

        p[i].second = x-l; // 始

    }



    sort(p.begin(), p.end());



    t = -10000000000;



    for(i=0; i<N; i++){

        if(t <= p[i].second){

            ans++;

            t = p[i].first;

        }

    }



    cout << ans << endl;



    return 0;

}