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



const int INF=1001001001001001001ll;



int N,C;

int X[555555],V[555555];

int S[555555];



int ans;



void solve()

{

    for(int i=0;i<N;i++) S[i+1]=S[i]+V[i];

    int ma=-INF;

    for(int i=N-1;i>=0;i--)

    {

        chmax(ans,S[i+1]-X[i]);

        chmax(ans,S[i+1]-2*X[i]+ma);

        chmax(ma,S[N]-S[i]+X[i]-C);

    }

}



signed main(){

    cin>>N>>C;

    vector<int> x(N),v(N);

    for(int i=0;i<N;i++) cin>>x[i]>>v[i];



    for(int t=0;t<2;t++)

    {

        for(int i=0;i<N;i++)

        {

            X[i]=x[i];

            V[i]=v[i];

        }

        solve();

        for(int i=0;i<N;i++) x[i]=C-x[i];

        reverse(all(x));

        reverse(all(v));

    }

    cout<<ans<<endl;

    return 0;

}
