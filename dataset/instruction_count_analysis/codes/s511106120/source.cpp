#include "stdc++.h"

#define N 100001

using namespace std;

typedef pair<int,int> P;

vector<int> G[N];

vector<P> ans;

int cnt[N],dep[N];



void dfs(int pos,int pre){

  for(int i=0;i<G[pos].size();i++){

    int nx=G[pos][i];

    if(nx==pre||dep[nx]>dep[pos]) continue;



    if(dep[nx]!=-1&&dep[nx]<dep[pos])cnt[nx]--,cnt[pos]++;

    else{ 

      dep[nx]=dep[pos]+1;

      dfs(nx,pos);

      if(cnt[nx]==0) ans.push_back(P(min(pos,nx),max(pos,nx)));

      cnt[pos]+=cnt[nx];

    } 

  }

}





int main(){

  int n,m;

  cin>>n>>m;

  for(int i=0,a,b;i<m;i++){

    cin>>a>>b;

    G[a].push_back(b);

    G[b].push_back(a);

  }



  memset(dep,-1,sizeof(dep));

  dep[0]=0;

  dfs(0,-1);

  sort(ans.begin(),ans.end());

  for(int i=0;i<ans.size();i++)cout <<ans[i].first<<" "<<ans[i].second<<endl;



  return 0;

}