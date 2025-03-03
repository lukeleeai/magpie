#include <iostream>

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <algorithm>

#include <vector>

#include <map>



using namespace std;



#define N 207



 vector<int> vx,vy;

 map<int,int> hx,hy;

 int dx[4]={0,0,1,-1};

 int dy[4]={1,-1,0,0};

 int vis[N][N];

 int l[55],r[55],t[55],b[55];

 

bool OK(int nx,int ny)

{

  if(nx >= 0 && nx <= 201 && ny >= 0 && ny <= 201 && !vis[nx][ny])

    return 1;

  return 0;

}



void dfs(int x,int y)

{

  vis[x][y] = 1;

  for(int k=0;k<4;k++)

  {

    int nx = x + dx[k];

    int ny = y + dy[k];

    if(OK(nx,ny))

      dfs(nx,ny);

  }

}

 int main(){

 	int n,i,j;

 	while(scanf("%d",&n)!=EOF&&n){

 		vx.clear();

 		vy.clear();

 		hx.clear();

 		hy.clear();

 		for(int i=0;i<n;i++){

 			scanf("%d%d%d%d",&l[i],&t[i],&r[i],&b[i]);

 			vx.push_back(l[i]);

 			vx.push_back(r[i]);

 			vy.push_back(t[i]);

 			vy.push_back(b[i]);

 		}

 		sort(vx.begin(),vx.end());

 		vx.erase(unique(vx.begin(),vx.end()),vx.end());

 		sort(vy.begin(),vy.end());

 		vy.erase(unique(vy.begin(),vy.end()),vy.end());

 		for(int i=0;i<vx.size();i++)

 		   hx[vx[i]]=2*i+1;

 		for(int i=0;i<vy.size();i++)

 		   hy[vy[i]]=2*i+1;

 		for(int i=0;i<n;i++){

 			l[i]=hx[l[i]];

 			t[i]=hy[t[i]];

 			r[i]=hx[r[i]];

 			b[i]=hy[b[i]];

 		}

 		memset(vis,0,sizeof(vis));

 		for(int i=0;i<n;i++){

 			for(int j=b[i];j<=t[i];j++){

 				vis[j][l[i]]=1;

 				vis[j][r[i]]=1;

 			}

 			for(int j=l[i];j<=r[i];j++){

 				vis[t[i]][j]=1;

 				vis[b[i]][j]=1;

 			}

 		}

 		int cnt=0;

 		for(int i=0;i<=201;i++){

 			for(int j=0;j<=201;j++){

 				if(!vis[i][j]){

 					cnt++; dfs(i,j);

 					

 				}

 			}

 		}

 		printf("%d\n",cnt);

 	}

 	return 0;

 }