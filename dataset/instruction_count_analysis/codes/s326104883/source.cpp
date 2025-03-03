#include<cstring>

#include<cstdio>

#include<iostream>

using namespace std;

int vis[51][51];

int f[101][101];

int a[2555][3];

int ans;

int main(){

   int n,m;ans=0;

   scanf("%d%d",&n,&m);

   for(int i=1;i<=m;i++){

   	  scanf("%d%d",&a[i][1],&a[i][2]);

   }

   for(int i=1;i<=m;i++){

       memset(vis,0x3f3f3f3f,sizeof(vis));

   	   for(int j=1;j<=m;j++){

   	   	  if(j!=i)vis[a[j][1]][a[j][2]]=vis[a[j][2]][a[j][1]]=1;

	   }

	   for(int j=1;j<=n;j++)f[j][j]=0;

	   for(int k=1;k<=n;k++){

	   	  for(int j=1;j<=n;j++){

	   	  	 for(int l=1;l<=n;l++){

	   	  		vis[j][l]=vis[l][j]=min(vis[j][l],vis[j][k]+vis[k][l]);

			 }

		  }

	   }

	   for(int j=1;j<=n;j++){

	   	  for(int k=1;k<=n;k++){

	   	  	if(vis[j][k]==0x3f3f3f3f){

	   	  		ans++;goto haha;

			  }

			}

	   }

	   haha:;

   }

   cout<<ans;

}