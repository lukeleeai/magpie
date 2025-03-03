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



const int mod=924844033;



int dp[2222][2222][2];



int N,K;



int fact[2222];



int tmp[2222];

int dp2[2222];



inline void add(int &a,int b){

    a+=b;

    if(a>=mod)a-=mod;

}



signed main(){

    cin>>N>>K;

    fact[0]=1;

    for(int i=1;i<2222;i++)fact[i]=fact[i-1]*i%mod;



    dp2[0]=1;

    for(int i=0;i<2*K&&i<N;i++){

        int n=(N-i)/(2*K)+1;

        if((N-i)%(2*K)==0)n--;



        int flag1=0,flag2=0;

        if(i-K>=0)flag1=true;

        if(i+(n-1)*2*K+K<N)flag2=true;

        rep(j,n+1)rep(k,n+1)rep(l,2)dp[j][k][l]=0;

        dp[0][0][1-flag1]=1;

        rep(j,n){

            rep(k,n+1){

                rep(l,2){

                    add(dp[j+1][k][0],dp[j][k][l]);

                    add(dp[j+1][k+1][1],dp[j][k][l]);

                    if(l==0)add(dp[j+1][k+1][0],dp[j][k][l]);

                }

            }

        }

        memset(tmp,0,sizeof(tmp));

        rep(j,N+1){

            rep(k,n+1){

                if(j+k<=N)add(tmp[j+k],dp2[j]*(dp[n][k][0]+dp[n][k][1]*flag2)%mod);

            }

        }

        rep(j,N+1)dp2[j]=tmp[j];

    }



    rep(j,N+1)dp2[j]=dp2[j]*fact[N-j]%mod;



    int ans=0;

    rep(i,N+1){

        if(i&1)ans=(ans-dp2[i]+mod)%mod;

        else ans=(ans+dp2[i])%mod;

    }

    cout<<ans<<endl;

    return 0;

}
