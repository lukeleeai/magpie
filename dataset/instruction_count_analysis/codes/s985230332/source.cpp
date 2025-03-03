#include"stdc++.h"

using namespace std;

#define inf 1000000000

#define INF 1000000000000000

#define ll long long

#define ull unsigned long long

#define M 1000000007

#define P pair<int,int>

#define PLL pair<ll,ll>

#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)

#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)

#define rep(i,n) FOR(i,0,n)

#define rrep(i,n) RFOR(i,n,0)

#define all(a) a.begin(),a.end()

#define IN(a,n) rep(i,n){ cin>>a[i]; }

const int vx[4] = {0,1,0,-1};

const int vy[4] = {1,0,-1,0};

#define PI 3.14159265

#define F first

#define S second

#define int ll



int n,m;

string s[1000];

int r,t;



signed main(){

  cin>>n>>m;

  rep(i,n){

    cin>>s[i];

  }



  rep(i,n){

    rep(j,m){

      if(s[i][j]=='.') r++;

      else t++;

    }

  }



  queue<P> q;

  q.push(P(0,0));

  int c[1000][1000];

  rep(i,1000){

    rep(j,1000){

      c[i][j]=inf;

    }

  }

  c[0][0]=0;

  while(q.size()){

    int a=q.front().F;

    int b=q.front().S;

    q.pop();

    rep(i,4){

      int x=a+vx[i];

      int y=b+vy[i];

      if(!(0<=x&&x<m&&0<=y&&y<n))continue;

      if(s[y][x]=='#') continue;

      if(c[y][x]>c[b][a]+1){

        c[y][x] = c[b][a]+1;

        q.push(P(x,y));

      }

    }

  }



  if(c[n-1][m-1]==inf){

    cout<<-1<<endl;

    return 0;

  }



  cout<<r-1-c[n-1][m-1]<<endl;

}