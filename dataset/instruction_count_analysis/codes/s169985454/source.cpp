#include"stdc++.h"

using namespace std;

using Int = long long;

const Int MAX = 30*30;

using BS = bitset<MAX*2>;

using mat = vector<BS>;



void gauss(mat &v){

  int n=v.size();

  for(Int i=0;i<n;i++){

    for(Int k=i;k<n;k++){

      if(v[k][i]){

	swap(v[i],v[k]);

	break;

      }

    }

    for(Int k=0;k<n;k++)

      if(i!=k&&v[k][i]) v[k]^=v[i];

  }

}



int mrank(mat v,int m){

  int n=v.size();

  int r=0,c=0;

  for(int i=0;i<n;i++){

    int s=-1;

    while(c<m){

      for(int j=i;j<n;j++){

	if(v[j][c]){

	  s=j;

	  break;

	}

      }

      if(~s) break;

      c++;

    }

    if(c>=m) break;

    

    swap(v[i],v[s]);

    for(int j=0;j<n;j++)

      if(i!=j&&v[j][c]) v[j]^=v[i];

    

    r++;c++;

  }

  return r;

}



mat mul(const mat &a,const mat &b){

  int n=a.size();

  vector<vector<int> > tmp(n,vector<int>(n,0));

  mat res(n,BS(0));

  for(int i=0;i<n;i++)

    for(int j=0;j<n;j++)

      for(int k=0;k<n;k++)

	tmp[i][j]+=(a[i][k]&b[k][j]);

  

  for(int i=0;i<n;i++)

    for(int j=0;j<n;j++)

      res[i][j]=tmp[i][j]&1;

  

  return res;

}



mat mat_pow(mat v,int k){

  int n=v.size();

  mat res(n,BS(0));

  for(int i=0;i<n;i++)

    res[i][i]=1;

  while(k){

    if(k&1) res=mul(res,v);

    v=mul(v,v);

    k>>=1;

  }

  return res;

}



signed main(){

  int m,n,d;

  while(cin>>m>>n>>d,m){

    vector<vector<int> > s(n,vector<int>(m));

    for(int i=0;i<n;i++)

      for(int j=0;j<m;j++)

	cin>>s[i][j];



    mat v(n*m,BS(0));

    auto idx=[&](int y,int x){return y*m+x;};

    auto in=[&](int y,int x){return 0<=y&&y<n&&0<=x&&x<m;};

    auto bfs=[&](int y,int x){

      int z=idx(y,x);

      v[z][z]=1;

      v[z][n*m]=s[y][x];

      

      vector<vector<int> > dp(n,vector<int>(m,-1));

      using P = pair<int, int>;

      queue<P> q;

      dp[y][x]=0;

      q.emplace(y,x);

      int dy[]={0,0,1,-1};

      int dx[]={1,-1,0,0};

      while(!q.empty()){

	tie(y,x)=q.front();q.pop();

	if(dp[y][x]==d) v[z][idx(y,x)]=1;

	for(int k=0;k<4;k++){

	  int ny=y+dy[k],nx=x+dx[k];

	  if(!in(ny,nx)||~dp[ny][nx]) continue;

	  dp[ny][nx]=dp[y][x]+1;

	  q.emplace(ny,nx);

	}

      }

    };

    

    for(int i=0;i<n;i++)

      for(int j=0;j<m;j++)

	bfs(i,j);

    

    int a=mrank(v,n*m);

    int b=mrank(v,n*m+1);

    cout<<(a==b)<<endl;

  }

  return 0;

}


