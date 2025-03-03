#include "stdc++.h"

#define N 501

#define M 50001

#define MAX_N N

#define rank Asdfiasofsad

using namespace std;



class UF{

public:

  int par[MAX_N],rank[MAX_N];

  UF(){for(int i=0;i<MAX_N;i++)par[i]=i,rank[i]=0;}

  UF(int n){for(int i=0;i<n;i++)par[i]=i,rank[i]=0;}

  

  int find(int x){

    if(par[x]==x)return x;

    return par[x]=find(par[x]);

  }

  

  void unite(int x,int y){

    x=find(x), y=find(y);

    if(x==y)return;

    if(rank[x]<rank[y])par[x]=y;

    else{

      par[y]=x;

      if(rank[x]==rank[y])rank[x]++;

    }

  }



  bool same(int x,int y){return find(x)==find(y);}

};



typedef pair<int,int> P;

typedef pair<int,P> PP;

vector<PP> edge;

int n,m;



int kruskal(int used[M]){

  UF U;

  int res=0;

  for(int i=0;i<m;i++){

    int a=edge[i].second.first;

    int b=edge[i].second.second;

    int c=edge[i].first;

    if(U.same(a,b)||used[i])continue;

    used[i]=1;

    U.unite(a,b);

    res+=c;

  }

  for(int i=0;i<n;i++)if(!U.same(0,i))return -1;

  return res;

}



int main(){

  cin>>n>>m;

  int sum=0;

  for(int i=0,a,b,c;i<m;i++){

    cin>>a>>b>>c;

    edge.push_back(PP(c,P(a-1,b-1)));

    sum+=c;

  }



  sort(edge.begin(),edge.end());

  int used[M]={},cnt=m,mncost=kruskal(used);

  for(int i=0;i<m;i++){

    int used2[M]={};

    used2[i]=1;

    if(!used[i]||kruskal(used2)==mncost)cnt--,sum-=edge[i].first;

  }

  cout<<cnt<<" "<<sum<<endl;

  return 0;

}