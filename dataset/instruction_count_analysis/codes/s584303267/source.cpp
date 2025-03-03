#include "bits/stdc++.h"

#define REP(i,n,N) for(int i=(n); i<(N); i++)

#define RREP(i,n,N) for(ll i=(N-1); i>=n; i--)

#define CK(n,a,b) ((a)<=(n)&&(n)<(b))

#define ALL(v) (v).begin(),(v).end()

#define p(s) cout<<(s)<<endl

#define p2(a,b) cout<<(a)<<" "<<(b)<<endl

#define v2(T) vector<vector<T>>

typedef long long ll;

using namespace std;

const ll mod=1e9+7;

const int inf=1e9;



int dp[1010][1010];

int N;

int C[1010], W[1010];

int sum[1010];

int main() {

    cin>>N;

    REP(i,0,N){

        cin>>C[i]>>W[i];

    }

    REP(i,0,N) REP(j,i,N) dp[i][j] = j-i+1;

    REP(i,0,N) sum[i+1] = sum[i] + W[i];

    REP(k,1,N){

        REP(L,0,N-k){

            int R = L + k;

            if(dp[L+1][R]==1 && sum[R+1]-sum[L+1] <= C[L]){

                dp[L][R] = min(dp[L][R], dp[L+1][R]);

            }

            if(dp[L][R-1]==1 && sum[R]-sum[L] <= C[R]){

                dp[L][R] = min(dp[L][R], dp[L][R-1]);

            }

            REP(i,L,R) {

                dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R]);

            }

        }

    }

    p(dp[0][N-1]);



    return 0;

}
