#include"stdc++.h"

using namespace std;

 

int n, x, y, res, fir=1, rt, f[101000];

vector<int>G[101000];

 

void dfs(int x,int fff){

  int isrt=0;

  if (G[x].size()>2&&fir) fir=0, isrt=1;

  for (auto y:G[x]) if (y!=fff) dfs(y,x);

  int t=max(0,(int)G[x].size()+isrt-2-f[x]);

  f[fff]+=!!f[x]|!!t;

  res+=t;

}

 

int main(){

  cin>>n;

  for (int i=n-1;i--;){

    scanf("%d%d",&x,&y); ++x; ++y;

    G[x].push_back(y); G[y].push_back(x);

  }

  for (rt=1;G[rt].size()!=1;++rt); dfs(rt,0);

  cout<<max(res,1);

}