#include "stdc++.h"

#define ALL(A) (A).begin(),(A).end()

#define maxn 1000



using namespace std;



int cap[maxn][maxn],N;



bool dfs(vector<int> &vis,int i,int t){

  if(i==t)return true;

  vis[i]=1;

  for(int j=0;j<N;j++)

    if(!vis[j] && cap[i][j]>0 && dfs(vis,j,t)){

      cap[i][j]--,cap[j][i]++;

      return true;

    }

  return false;

}



int max_flow(int s, int t){

  vector<int>vis(N);

  for(int flow=0;;flow++,fill(ALL(vis),0))

    if(!dfs(vis,s,t))return flow;

}



int main(void){ 

  int e,a,b,c;

  cin >> N >> e;

  for(int i=0;i<e;i++){

    cin >> a >> b >> c;

    cap[a][b]=c;

  }

  cout << max_flow(0,N-1) << endl;;

}