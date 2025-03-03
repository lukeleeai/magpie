#include"stdc++.h"

using namespace std;



#define int long long

typedef vector<int>vint;

typedef pair<int,int>pint;

typedef vector<pint>vpint;

#define rep(i,n) for(int i=0;i<(n);i++)

#define reps(i,f,n) for(int i=(f);i<(n);i++)

#define all(v) (v).begin(),(v).end()

#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

#define pb push_back

#define fi first

#define se second

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}

template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}



const int mod=1000000007;

int N,K;

int A[100];



inline void add(int &a,int b){

    a+=b;

    if(a>=mod)a-=mod;

}

int dp[111][111][256];



signed main(){

    cin>>N>>K;

    rep(i,N)cin>>A[i];

    dp[0][0][0]=1;



    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){

            for(int k=0;k<256;k++){

                add(dp[i+1][j+1][k^A[i]],dp[i][j][k]);

                add(dp[i+1][j][k],dp[i][j][k]);

            }

        }

    }

    int ans=0;

    int f=1;

    for(int i=1;i<=N;i++){

        f=f*i%mod;

        add(ans,dp[N][i][K]*f%mod);

    }

    cout<<ans<<endl;

    return 0;

}
