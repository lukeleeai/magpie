#include<iostream>

#include<cstdio>

#include<algorithm>

#include<vector>

#include<queue>

#define F first

#define S second

#define pb push_back

#define rep(i,n) for(int i=0;i<n;i++)

#define all(n) n.begin(),n.end()

using namespace std;

bool used[3010][3010];

static const short dy[] = {0,1,0,-1};

static const short dx[] = {1,0,-1,0};

int h,w;

typedef pair<int,int> P;

 

int main(){

  int n;

  while(true){

    cin >> w >> h;

    if(w+h == 0)break;

    cin >> n;

    int x1[n],x2[n],y1[n],y2[n];

    vector<int> x,y;

    for(int i=0;i<n;i++){

      cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

      x.pb(x1[i]);y.pb(y1[i]);x.pb(x2[i]);y.pb(y2[i]);

    }

    x.pb(0); x.pb(w); y.pb(0); y.pb(h);

     

    sort(all(x)); sort(all(y));

    x.erase(unique(all(x)),x.end()); y.erase(unique(all(y)),y.end());

    

    int limx = x.size(),limy = y.size();

    rep(i,3010)rep(j,3010)used[i][j] = false;

    

    rep(i,n){

      x1[i] = find(all(x),x1[i])-x.begin();

      //cout << "x1[i] = " << x1[i];

      y1[i] = find(all(y),y1[i])-y.begin();

      //cout << ", y1[i] = " << y1[i];

      x2[i] = find(all(x),x2[i])-x.begin();

      //cout << ", x2[i] = " << x2[i];

      y2[i] = find(all(y),y2[i])-y.begin();

      //cout << ", y2[i] = " << y2[i] << endl;

    

    

    }

    int cnt = 0;

    rep(i,limy)rep(j,limx)used[i][j] = i==limy-1||j==limx-1;

    queue<P> que;



    rep(i,n)for(int k=x1[i];k<x2[i];k++){

    for(int j=y1[i];j<y2[i];j++)used[j][k] = true;

      }

     

    rep(i,limy){

      rep(j,limx){

    if(!used[i][j]){

      que.push(P(j,i));

      cnt++;

      used[i][j] = true;

      while(!que.empty()){

        P p = que.front(); que.pop();

        rep(k,4){

          int nx = p.F+dx[k],ny = p.S+dy[k];

          if(0<=nx && nx <limx-1 && 0<= ny && ny <limy-1 && !used[ny][nx]){

        used[ny][nx] = true;

        que.push(P(nx,ny));

          }

        }

 

      }

    }

      }

    }

   

 

 

    cout << cnt << endl;

 

 

 

 

 

  }

  return 0;

}