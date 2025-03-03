#include"stdc++.h"

#define f first

#define s second 

#define mp make_pair

#define inf 1<<30

using namespace std;



vector<pair<int,pair<int,int> > > v[101];



int main()

{

  int N,M,L,a,b,c,d;

  int dp[101][101];



  while(1){

    cin>>N>>M>>L;

    if(N+M+L==0)break;

    for(int i=0;i<101;i++){

      for(int j=0;j<101;j++){

	dp[i][j]=inf;

      }

      v[i].clear();

    }

    for(int i=0;i<M;i++){

      cin>>a>>b>>c>>d;

      a--;b--;

      v[a].push_back(mp(b,mp(c,d)));

      v[b].push_back(mp(a,mp(c,d)));

    }



    int ans=inf;

    dp[0][L]=0;

    priority_queue<pair<int,pair<int,int> > > pq;

    pq.push(mp(0,mp(0,L)));

    while(!pq.empty()){

      pair<int,pair<int,int> > u=pq.top();

      pq.pop();

      int now=u.s.f,money=u.s.s,cost=(-1)*u.f;

      if(dp[now][money]<cost)continue;

      if(now==N-1){

	ans=cost;

	break;

      }

      

      for(int i=0;i<v[now].size();i++){

	int next=v[now][i].f,dis=v[now][i].s.f,e=v[now][i].s.s;

	int c=money-dis;

	if(0<=c){

	  if(cost<dp[next][c]){

	    dp[next][c]=cost;

	    pq.push(mp(cost*(-1),mp(next,c)));

	  }

	}

	if(cost+e<dp[next][money]){

	  dp[next][money]=cost+e;

	  pq.push(mp((cost+e)*(-1),mp(next,money)));

	}

      }

    }

    cout<<ans<<endl;

  }

  return 0;

}