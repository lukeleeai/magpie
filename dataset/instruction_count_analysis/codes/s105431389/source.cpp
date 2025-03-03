#include"stdc++.h"

#define f first

#define s second 

#define mp make_pair

#define inf 1<<30

using namespace std;



int main()

{

  int N,M,L,a,b,c,d;

  int dis[101][101],th[101][101];

  int dp[101][101];



  while(1){

    cin>>N>>M>>L;

    if(N+M+L==0)break;

    for(int i=0;i<101;i++){

      for(int j=0;j<101;j++){

	dis[i][j]=th[i][j]=dp[i][j]=inf;

      }

    }

    for(int i=0;i<M;i++){

      cin>>a>>b>>c>>d;

      a--;b--;

      dis[a][b]=c;

      dis[b][a]=c;

      th[a][b]=d;

      th[b][a]=d;

    }

    int ans=inf;

    dp[0][L]=0;

    priority_queue<pair<int,pair<int,int> > > pq;

    pq.push(mp(0,mp(0,L)));

    while(!pq.empty()){

      pair<int,pair<int,int> > u=pq.top();

      pq.pop();

      u.f=(-1)*u.f;

      if(dp[u.s.f][u.s.s]<u.f)continue;

      if(u.s.f==N-1){

	ans=min(ans,u.f);

	continue;

      }

      

      for(int i=0;i<N;i++){

	if(dis[u.s.f][i]==inf)continue;

	int c=u.s.s-dis[u.s.f][i];

	if(0<=c){

	  if(u.f<dp[i][c]){

	    dp[i][c]=u.f;

	    pq.push(mp(u.f*(-1),mp(i,c)));

	  }

	}

	if(u.f+th[u.s.f][i]<dp[i][u.s.s]){

	  dp[i][u.s.s]=u.f+th[u.s.f][i];

	  pq.push(mp((u.f+th[u.s.f][i])*(-1),mp(i,u.s.s)));

	}

      }

    }

    cout<<ans<<endl;

  }

  return 0;

}