#include"stdc++.h"

using namespace std;

#define int long long

set<int> G[114514];

signed main(){

  int n;

  cin>>n;

  int a[n],b[n];

  for(int i=0;i<n-1;i++){

    cin>>a[i]>>b[i];

    a[i]--;b[i]--;

    G[a[i]].insert(b[i]);

    G[b[i]].insert(a[i]);

  }

  bool f=0;

  queue<int> q;

  for(int i=0;i<n;i++){

    int tmp=0;

    int k;

    for(int u:G[i]){

      if(G[u].size()==1){

	tmp++;

	k=u;

      }

    }

    f|=(tmp>=2);

    if(f){

      cout<<"First"<<endl;

      return 0;

    }

    if(G[i].size()==2&&tmp==1){

      G[i].erase(k);

      G[k].erase(i);

      int u=*G[i].begin();

      G[i].erase(u);

      G[u].erase(i);

      q.push(u);

      for(int v:G[u]) if(G[v].size()>1) q.push(v);

    }

  }

  while(!q.empty()){

    int i=q.front();q.pop();

    int tmp=0;

    int k;

    for(int u:G[i]){

      if(G[u].size()==1){

	tmp++;

	k=u;

      }

    }

    f|=(tmp>=2);

    if(f){

      cout<<"First"<<endl;

      return 0;

    }

    if(G[i].size()==2&&tmp==1){

      G[i].erase(k);

      G[k].erase(i);

      int u=*G[i].begin();

      G[i].erase(u);

      G[u].erase(i);

      q.push(u);

      for(int v:G[u]) if(G[v].size()>1) q.push(v);

    }

  }

  cout<<(f?"First":"Second")<<endl;

  return 0;

}
