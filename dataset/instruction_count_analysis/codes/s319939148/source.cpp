#include<cmath>

#include<cstdio>

#include<algorithm>

using namespace std;

struct node{

	int ne,tow;

};

node pth[200000+10];

int mp[100000+10],szp;

int vis[100000+10];

int n;

int deg[100000+10];

int root=-1;

int son[100000+10];

int bro[100000+10];

int dp[100000+10];

int left[100000+10];

void addpath(int i,int j){

	++szp;

	pth[szp].ne=mp[i];

	pth[szp].tow=j;

	mp[i]=szp;

	deg[i]++;

}



void dfs1(int i,int j){

	if (vis[i]!=0) return;

	vis[i]=j;

	int po=mp[i];

	while (po!=-1){

		if (vis[pth[po].tow]==0){

			bro[pth[po].tow]=son[i];

			son[i]=pth[po].tow;

		}

		dfs1(pth[po].tow,j+1);

		po=pth[po].ne;

	}	

}

void dfs2(int i){

	int j=son[i];

	if (j==-1){

		left[i]=1;

		dp[i]=1;

		return;

	}

	while (j!=-1){

		dfs2(j);

		left[i]+=left[j];

		dp[i]+=dp[j];

		j=bro[j];

	}

	j=son[i];

	if (j!=-1&&bro[j]!=-1)

	while (j!=-1){

		if (dp[j]==1&&left[j]==1){

			dp[i]--;

			return;

		}

		j=bro[j];

	}



}





int main(){

	scanf("%d",&n);

	for (int f1=0;f1<n;f1++){

		mp[f1]=-1;

		vis[f1]=0;

	}

	

	for (int f1=1;f1<n;f1++){

		int i,j;

		scanf("%d%d",&i,&j);

		addpath(i,j);

		addpath(j,i);

		if (deg[i]>2)root=i;

		if (deg[j]>2)root=j;

	}

	if (root==-1){

		printf("1\n");

		return 0;

	}

	for (int f1=0;f1<n;f1++){

		son[f1]=-1;

		bro[f1]=-1;

		left[f1]=0;

		dp[f1]=0;

	}

	dfs1(root,1);

	dfs2(root);

	printf("%d\n",dp[root]);

	//for (int f1=0;f1<n;f1++)printf("%d ",dp[f1]);

}
