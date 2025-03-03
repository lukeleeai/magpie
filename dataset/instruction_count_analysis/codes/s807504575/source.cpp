#include <string.h>

#include <algorithm>

#include <cstdio>

#define max_n 100

#define max_m 1000

#define max_l 1000

#define min_int(a,b)  ( ((a)<(b) ) ? (a) : (b) )

using namespace std;

class Req{

public:

  char house;

  int time;

};

class LessReq {

public:

    bool operator()(const Req& x, const Req& y) const {

        return x.time < y.time; 

    }

};

int n,m,l;

int dist[max_n][max_n];

Req reqs[max_l];

//リクエストx配送後に、リクエストy配送可能かを示す有向グラフ（DAG）

int req_graph[max_l][max_l];

int num_child[max_l];//各リクエストxの子の数

int parent[max_l]; //被覆パスにおけるリクエストxの親

int till[max_l];

bool visited[max_l];

 

//すべての宅間の最短距離を算出、distに記録

void compute_dist(){

  register int i,j,k;

   

  for(i=0;i<n;i++) dist[i][i] = 0;

  for(k=0;k<n;k++){

    for(i=0;i<k;i++){

      for(j=i+1;j<k;j++){  //i<j<k

        if(dist[i][k] < 0) continue;

        if(dist[j][k] < 0) continue;

        if(dist[i][j] < 0) dist[i][j] = dist[i][k]+dist[j][k];

        else dist[i][j] = min_int(dist[i][j],dist[i][k]+dist[j][k]);

      }

      for(j=k+1;j<n;j++){  //i<k<j

        if(dist[i][k] < 0) continue;

        if(dist[k][j] < 0) continue;

        if(dist[i][j] < 0) dist[i][j] = dist[i][k]+dist[k][j];

        else dist[i][j] = min_int(dist[i][j],dist[i][k]+dist[k][j]);

      }

    }

    for(i=k+1;i<n;i++){

      for(j=i+1;j<n;j++){  //k<i<j

        if(dist[k][i] < 0) continue;

        if(dist[k][j] < 0) continue;

        if(dist[i][j] < 0) dist[i][j] = dist[k][i]+dist[k][j];

        else dist[i][j] = min_int(dist[i][j],dist[k][i]+dist[k][j]);

      }      

    }

  }

  for(i=0;i<n;i++)for(j=i+1;j<n;j++){

    dist[j][i] = dist[i][j];

  }

}

//req_graphの構成

void compute_req_graph(){

  int i,j,h1,h2;

 

  memset(num_child,0,l*sizeof(int));

  for(i=0;i<l;i++) for(j=i+1;j<l;j++){

      h1 = reqs[i].house; h2 = reqs[j].house;      

      if((dist[h1][h2] >= 0)

         && (dist[h1][h2] <= reqs[j].time - reqs[i].time)){

        req_graph[i][num_child[i]++] = j;

      }      

  } 

}

 

int find(int i, bool root){

  int child, x, found;

  //親権の空いている子を探す

  visited[i] = true;  

  if(till[i] < num_child[i]){    

    while((++(till[i])) < num_child[i]){

      child = req_graph[i][num_child[i]-till[i]-1];

      if(parent[child] >= 0) continue;

      parent[child] = i; //childを自分の子とする

      return child;

    }

  }

  //他の親から親権を譲ってもらえる子を探す  

  for(int j = num_child[i]-1;j >=0; j--){

    child = req_graph[i][j];

    x = parent[child]; //x: childのパス上の親

    if(visited[x]) continue;

    found = find(x,false); //xからchildの親権をもらう交渉

    if(found < 0) continue;

    parent[child] = i; //childの親権獲得

    return child;

  }

  return -1;

}

//req_graphのパス被覆を求め、被覆数を返す。

int num_covers(){

  int num=0;

  memset(till,-1,l*sizeof(int));

  memset(parent,-1,l*sizeof(int));

  for(int i=l-1;i>=0;i--){

    memset(visited,0,l*sizeof(bool));

    find(i,true);

  }

  for(int i=0;i<l;i++) if(parent[i]<0) num++;

  return num;

}

 

//プレゼント配送に必要なサンタの数を出力する関数

int santas(){

  int u,v,d,i;

  //入力読み込み

  memset(dist,-1,sizeof(dist));

  for(i=0;i<m;i++){

    scanf("%d%d%d",&u,&v,&d);

    dist[u][v] = d;

  }

  for(i=0;i<l;i++){

    scanf("%d%d",&(reqs[i].house),&(reqs[i].time));

  }

  compute_dist();//すべてのhouse間の最短距離を算出、distに記録

  sort(reqs,reqs+l,LessReq());

  compute_req_graph();//req_graphの構成

  int res = num_covers();

  return res;

}

 

//以下メイン関数

int main(){

  while(1){    

    scanf("%d%d%d",&n,&m,&l);

    if((n == 0) && (m == 0) && (l == 0)) break;    

    printf("%d\n",santas());

  }

  return 0;

}