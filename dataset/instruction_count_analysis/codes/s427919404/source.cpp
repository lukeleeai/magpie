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



int N;

int A[333][333];



const int INF=1001001001001001001ll;

int d[333][333];



signed main(){

    cin>>N;

    rep(i,N)rep(j,N)cin>>A[i][j];



    fill_n(*d,333*333,INF);

    rep(i,N)d[i][i]=0;

    rep(i,N)rep(j,N)chmin(d[i][j],A[i][j]);



    rep(k,N)rep(i,N)rep(j,N)chmin(d[i][j],d[i][k]+d[k][j]);



    rep(i,N)rep(j,N)if(d[i][j]!=A[i][j]){

    cout<<-1<<endl;

    return 0;}



    int ans=0;

    rep(i,N)for(int j=i+1;j<N;j++){

        bool f=false;

        rep(k,N){

            if(i==k||j==k)continue;

            if(d[i][k]+d[k][j]==d[i][j])f=true;

        }

        if(!f)ans+=d[i][j];

    }



    cout<<ans<<endl;

    return 0;

}
