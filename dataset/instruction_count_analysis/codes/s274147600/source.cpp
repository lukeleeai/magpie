#include <algorithm>

#include <bitset>

#include <cassert>

#include <chrono>

#include <climits>

#include <cmath>

#include <complex>

#include <cstring>

#include <deque>

#include <functional>

#include <iostream>

#include <list>

#include <map>

#include <numeric>

#include <queue>

#include <random>

#include <set>

#include <stack>

#include <unordered_map>

#include <unordered_set>

#include <vector>

#include <cstdint>

using namespace std;

typedef long long ll;

#define MP make_pair

#define PB push_back

#define inf (1LL<<60)

#define mod 1000000007

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){

    int n,m;

    while(cin >> n >> m && n!=0){

        vector<vector<ll> > L(n,vector<ll>(n,inf)),S(n,vector<ll>(n,inf));

        rep(i,n){

            L[i][i] = 0;

            S[i][i] = 0;

        }

        rep(i,m){

            int a,b;

            ll t;

            cin >> a >> b >> t;

            a--;b--;

            char c;

            cin >> c;

            if(c=='L'){

                L[a][b] = min(L[a][b],t);

                L[b][a] = min(L[b][a],t);

            }else{

                S[a][b] = min(S[a][b],t);

                S[b][a] = min(S[b][a],t);

            }

        }

        int rr;

        cin >> rr;

        vector<int> r(rr);

        rep(i,rr){

            cin >> r[i];

            r[i]--;

        }

        rep(k,n){

            rep(i,n){

                rep(j,n){

                    L[i][j] = min(L[i][j],L[i][k]+L[k][j]);

                    S[i][j] = min(S[i][j],S[i][k]+S[k][j]);

                }

            }

        }

        vector<vector<ll> > dp(rr,vector<ll>(n,inf));

        dp[0][r[0]] = 0;

        for(int i=1;i<rr;i++){

            int s = r[i-1];

            int t = r[i];

            rep(j,n){

                rep(k,n){

                    dp[i][k] = min(dp[i][k],dp[i-1][j]+L[s][j]+S[j][k]+L[k][t]);

                    if(j==k){

                        dp[i][k] = min(dp[i][k],dp[i-1][j]+L[s][t]);

                    }

                }

            }

        }

        ll mi = inf;

        rep(i,n){

            mi = min(mi,dp[rr-1][i]);

        }

        cout << mi << endl;

    }

    return 0;

}
