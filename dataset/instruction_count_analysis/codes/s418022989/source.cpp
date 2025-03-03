#include<stdio.h>



char g[2001][2001];

int n,m,maxc[2001][2001],maxr[2001][2001],lst=-1,res,max;



int main(){

	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++)scanf("%s",g[i]);

	for(int i=0;i<n;i++,lst=-1,res=0)for(int j=0;j<=m;j++)

		if(j==m||g[i][j]!='.'){

			for(int k=lst+1;k<j;k++)maxc[i][k]=res;

			res=0,lst=j;

		}

		else res++;

	lst=-1,res=0;

	for(int j=0;j<m;j++,lst=-1,res=0)for(int i=0;i<=n;i++)

		if(i==n||g[i][j]!='.'){

			for(int k=lst+1;k<i;k++)maxr[k][j]=res;

			res=0,lst=i;

		}

		else res++;

	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(maxc[i][j]+maxr[i][j]>max)max=maxc[i][j]+maxr[i][j];

	printf("%d\n",max-1);

	return 0;

}
