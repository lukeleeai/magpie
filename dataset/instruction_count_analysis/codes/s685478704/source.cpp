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



const int mod=924844033;

int fact[10000];



int N,K;

int dp[2][2010][2][2];

int d[2010];



int dp2[2010];

int tmp[2010];



inline void add(int &a,int b){

    a+=b;

    if(a>=mod)a-=mod;

    if(a<0)a+=mod;

}



void C(int n){

    memset(dp,0,sizeof(dp));

    dp[0][0][0][0]=1;

    rep(i,n){

        rep(j,i+1){

            rep(k,2){

                rep(l,2){

                    if(i&&k==0){

                        add(dp[(i+1)&1][j+1][l][0],dp[i&1][j][k][l]);

                    }

                    if(i+1!=n){

                        add(dp[(i+1)&1][j+1][l][1],dp[i&1][j][k][l]);

                    }

                    add(dp[(i+1)&1][j][l][0],dp[i&1][j][k][l]);

                    dp[i&1][j][k][l]=0;

                }

            }

        }

    }

    memset(d,0,sizeof(d));

    rep(i,n+1){

        rep(j,2)rep(k,2)add(d[i],dp[n&1][i][j][k]);

    }

}



signed main(){

    fact[0]=1;

    for(int i=1;i<10000;i++)fact[i]=fact[i-1]*i%mod;



    cin>>N>>K;



    dp2[0]=1;

    for(int i=0;i<K;i++){

        int cnt=(N-1-i)/K+1;

        C(cnt);

        memset(tmp,0,sizeof(tmp));

        rep(j,N+1){

            rep(k,cnt+1){

                if(j+k>N)break;

                add(tmp[j+k],dp2[j]*d[k]%mod);

            }

        }

        rep(j,N+1)dp2[j]=tmp[j];

    }



    for(int i=0;i<=N;i++){

        dp2[i]=dp2[i]*fact[N-i]%mod;

    }



    int ans=0;

    rep(i,N+1){

        if(i&1)add(ans,-dp2[i]);

        else add(ans,dp2[i]);

    }



    cout<<ans<<endl;

}
