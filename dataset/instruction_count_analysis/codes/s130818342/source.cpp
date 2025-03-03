#include"stdc++.h"

using namespace std;

typedef long long ll;

vector<int> G[111111];

int ans=0;

int dfs(int v){

  if(!G[v].size()) return 0;

  int res=0;

  vector<int> vv;

  for(int i=0;i<(int)G[v].size();i++){

    int k=dfs(G[v][i]);

    res=max(res,k);

    vv.push_back(k);

  }

  sort(vv.begin(),vv.end());

  for(int i=0;i<(int)vv.size();i++){

    res=max(res,vv[i]+(int)vv.size()-i);

  }

  return res;

}

int main(){

  int n;

  cin>>n;

  int a[n];

  a[0]=-1;

  for(int i=1;i<n;i++){

    cin>>a[i];

    G[a[i]-1].push_back(i);

  }

  cout<<dfs(0)<<endl;

  return 0;

}
