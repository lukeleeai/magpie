

#include"stdc++.h"

using namespace std;

#define inf 1000000000

#define INF 100000000000000

#define ll long long

#define ull unsigned long long

#define M (int)(1e9+7)

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

#define PB push_back

#define EB emplace_back



int h,w;

char s[100][100];

int t[100][100];

int ans=0;

int main(){

  cin>>h>>w;

  rep(i,h){

    cin>>s[i];

    rep(j,w){

      t[i][j]=inf;

      if(s[i][j]=='.')

        ans++;

    }

  }

  t[0][0]=0;

  queue<P> q;

  q.push(P(0,0));

  while(!q.empty()){

    int a=q.front().F,b=q.front().S;

    q.pop();

    rep(i,4){

      int x=a+vx[i],y=b+vy[i];

      if(!(0<=x&&x<w&&0<=y&&y<h)) continue;

      if(s[y][x]=='.'&&t[y][x]>t[b][a]+1){

        t[y][x]=t[b][a]+1;

        q.push(P(x,y));

      }

    }

  }



  if(t[h-1][w-1]==inf)

    cout<<-1<<endl;

  else

    cout<<ans-1-t[h-1][w-1]<<endl;

}
