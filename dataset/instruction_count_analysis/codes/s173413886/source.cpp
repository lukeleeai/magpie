#include "bits/stdc++.h"

#include <iostream>

#include <string.h>

#include <stdio.h>

#include <map>

#include <vector>

#include <math.h>

#include <algorithm>

#include <queue>

#include <set>

#include <tuple>

using namespace std;



#define FOR(i,init,a) for(int i=init; i<a; i++)

#define rep(i,a) FOR(i,0,a)

#define rrep(i,a) for(int i=a; i>=0; i--)

#define rep1(i,a) for(int i=1; i<=a; i++)

#define cout1(a) cout << a << endl;

#define cout2(a,b) cout << a << " " << b << endl;

#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;

#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;

#define mem(a,n) memset( a, n, sizeof(a))

#define all(a) a.begin(),a.end()

#define chmin(a,b) a=min(a,b);

#define chmax(a,b) a=max(a,b);



typedef long long ll;

typedef long double ld;

typedef pair<int,int> pii;

const int INF = 1e9;

const int MOD = 1e9+7;

const ll LLINF = 1e18;

static const double pi = 3.141592653589793;



ll N,C;

ll X[100009], V[100009];

ll turnL[100009], turnR[100009];



int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);

    

    cin>>N>>C;

    rep(i,N) cin>>X[i]>>V[i];

    

    ll sum=0, mx=0;

    rep(i,N){

        sum+=V[i];

        chmax(mx,sum-X[i]);

        turnL[i]=mx;

    }

    

    sum=0, mx=0;

    rrep(i,N-1){

        sum+=V[i];

        chmax(mx,sum-(C-X[i]));

        turnR[i]=mx;

    }

    

    ll ans=0;

    rep(i,N){

        ll tmp=turnL[i];

        if(i<N-1) tmp+=max(0ll,turnR[i+1]-X[i]);

        chmax(ans,tmp);

    }

    

    rrep(i,N-1){

        ll tmp=turnR[i];

        if(i) tmp+=max(0ll,turnL[i-1]-(C-X[i]));

        chmax(ans,tmp);

    }

    

    cout1(ans)

}