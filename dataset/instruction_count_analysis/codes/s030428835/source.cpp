#include"stdc++.h"

using namespace std;

using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}

template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}





struct FastIO{

  FastIO(){

    cin.tie(0);

    ios::sync_with_stdio(0);

  }

}fastio_beet;





template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}



//INSERT ABOVE HERE

signed main(){

  int n;

  cin>>n;

  vector< set<int> > G(n);

  for(int i=1;i<n;i++){

    int a,b;

    cin>>a>>b;

    a--;b--;

    G[a].emplace(b);

    G[b].emplace(a);

  }



  vector<int> ls(n);

  for(int i=0;i<n;i++) ls[i]=G[i].size()==1;



  vector<int> cs(n);

  for(int v=0;v<n;v++)

    for(int u:G[v])

      cs[v]+=ls[u];



  for(int i=0;i<n;i++)

    if(cs[i]>=2) drop("First");



  queue<int> que;

  for(int i=0;i<n;i++)

    if(G[i].size()==2&&cs[i]) que.emplace(i);



  while(!que.empty()){

    int v=que.front();que.pop();

    for(int u:G[v]){

      G[u].erase(v);

      if(G[u].size()==1){

        ls[u]=1;

        int p=*G[u].begin();

        cs[p]+=ls[u];

        if(cs[p]>=2) drop("First");

        if(G[p].size()==2&&cs[p])

          que.emplace(p);

      }

      if(G[u].size()==2&&cs[u])

        que.emplace(u);

    }



    G[v].clear();

  }



  drop("Second");

  return 0;

}
