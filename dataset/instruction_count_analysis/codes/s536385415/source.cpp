#include"stdc++.h"

using namespace std;

#define ALL(x) x.begin(),x.end()

#define rep(i,n) for(int i=0;i<n;i++)

#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 

#define INF 1000000000

#define mod 1000000007

typedef long long ll;

const ll LINF = 1001002003004005006ll;

int dx[]={1,0,-1,0};

int dy[]={0,1,0,-1};

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



signed main(){

    cin.tie(0);

    ios::sync_with_stdio(0);



    int n,k;cin>>n>>k;

    vector<ll> h(n+1);

    rep(i,n) cin>>h[i+1];



    //まず，ある列を操作すること，その列を完全に消すことは同値(これは自分で気づけた)

    //消す列を選ぶ

    //うまくDPするために

    //必要な情報はDPのindex(次元？)に持たせる

    //何回操作したかとか，あと何回操作したかとかをDPに持たせるのはとても自然な考えだけど，もう一つ

    //今回，ある状況での部分解は削除しなかった最後の列に依るんだからそこを持ったほうがいいとわかる

    //なるほどなぁ

    ll dp[310][310];

    rep(i,310)rep(j,310) dp[i][j]=LINF;

    dp[0][0]=0;

    // dp[i][j] : 最後にi列を使った，サイズがj

    // dp[i][j]=min(k=1 to i-1  dp[k][j-1]+max(0,h[i]-h[k]))



    for(int j=1;j<=n-k;j++){

        for(int i=1;i<=n;i++){

            for(int k=0;k<i;k++){

                chmin(dp[i][j],dp[k][j-1]+max(0ll,h[i]-h[k]));

            }

        }

    }

    ll ans=LINF;

    rep(i,n+1){

        chmin(ans,dp[i][n-k]);

    }

    cout<<ans<<endl;

    return 0;

}
