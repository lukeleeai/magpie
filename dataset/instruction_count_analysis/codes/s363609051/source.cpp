#include"stdc++.h"

using namespace std;



#define int long long



#define rep(i,n) for(int i=0;i<(n);i++)

#define pb push_back

#define all(v) (v).begin(),(v).end()

#define fi first

#define se second

typedef vector<int>vint;

typedef pair<int,int>pint;

typedef vector<pint>vpint;



template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}

template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}



const int mod=1000000007;

inline void add(int &a,int b){

    a+=b;

    if(a>=mod)a-=mod;

}



int N,K;

int A[111];



int dp[111][111][256];



signed main(){

    cin>>N>>K;

    rep(i,N)cin>>A[i];



    dp[0][0][0]=1;

    for(int i=0;i<N;i++){

        for(int j=0;j<=i;j++){

            for(int k=0;k<256;k++){

                add(dp[i+1][j][k],dp[i][j][k]);

                add(dp[i+1][j+1][k^A[i]],dp[i][j][k]);

            }

        }

    }



    int ans=0;

    for(int i=0;i<=N;i++){

        int tmp=dp[N][i][K];

        for(int j=1;j<=i;j++)tmp=tmp*j%mod;

        add(ans,tmp);

    }

    cout<<ans<<endl;

    return 0;

}
