#include "stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)

#define Rep(i,n) for(int i=1;i<=n;i++)

const ll MOD = 1000000007;

long long modinv(long long a, long long m=MOD) {

    long long b = m, u = 1, v = 0;

    while (b) {

        long long t = a / b;

        a -= t * b; swap(a, b);

        u -= t * v; swap(u, v);

    }

    u %= m; 

    if (u < 0) u += m;

    return u;

    /*MODの割り算の際に

    a/＝b;

    を

    a *= modinv(b,MOD);

    とする。

        */

}

const int MAXN = 200001;

string S[MAXN];



int main(){

    int N;cin >> N;

    rep(i,N)cin >> S[i];

    map<string,int> ma;

    ll ans = 0;

    rep(i,N){

        if(ma[S[i]]>0){

            ma[S[i]]++;

        }

        else {

            ma[S[i]] = 1;

            ans ++;

        }

    }



    cout <<ans << endl;

    







    return 0;

}