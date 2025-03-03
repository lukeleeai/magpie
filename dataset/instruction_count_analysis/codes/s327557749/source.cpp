#include <iostream>

#include <algorithm>

#include <string>

#include <vector>

#include <math.h>

#include <queue>

#define MOD 1000000007

typedef long long ll;

using namespace std;



#define INFTY (1<<30)

#define MAX 100010



int n;

vector<pair<int,int>> adj[MAX];



void dijkstra(){

  priority_queue<pair<int,int>> PQ;

  int d[MAX];

  for(int i=0;i<n;i++) d[i]=INFTY;



  d[1]=0;

  PQ.push(make_pair(0,1));



  while(!PQ.empty()){

    pair<int,int> f=PQ.top();

    //cout<<f.first<<" "<<f.second<<endl;

    PQ.pop();

    int u=f.second;



    if(d[u]<f.first*(-1)) continue;



    for(int j=0;j<adj[u].size();j++){

      int v=adj[u][j].first;

      if(d[v]>d[u]+adj[u][j].second){

        d[v]=d[u]+adj[u][j].second;

        PQ.push(make_pair(d[v]*(-1),v));

      }

    }

  }



  cout<<d[0]+1<<endl;

  /*for(int i=0;i<n;i++){

    cout<<i<<" "<<(d[i]==INFTY?-1:d[i])<<endl;

  }*/

}



int main(){

  cin>>n;

  for(int i=1;i<n;i++){

    adj[i].push_back(make_pair((i+1)%n,1));

    adj[i].push_back(make_pair((i*10)%n,0));

    //cout<<i<<" "<<(i+1)%n<<" "<<i*10%n<<endl;

  }

  dijkstra();

  return 0;

}
