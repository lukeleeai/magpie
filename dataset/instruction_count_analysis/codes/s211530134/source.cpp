#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

#define N 505

int pos[N],id[N],ans[N*N];

bool cmp(int x,int y){return pos[x]<pos[y];}

int main()

{

	int n,i,j,k,x;

	scanf("%d",&n);

	for(i=1;i<=n;i++){

		scanf("%d",&pos[i]);

		id[i]=i;ans[pos[i]]=i;

	}

	sort(id+1,id+n+1,cmp);

	k=1;

	for(i=1;i<=n;i++){

		x=id[i];

		for(j=1;j<x;j++){

			while(ans[k])k++;

			if(k>pos[x]){printf("No\n");return 0;}

			ans[k]=x;

		}

	}

	for(i=1;i<=n;i++){

		x=id[i];

		for(j=x+1;j<=n;j++){

			while(ans[k])k++;

			if(k<pos[x]){printf("No\n");return 0;}

			ans[k]=x;

		}

	}

	printf("Yes\n%d",ans[1]);

	for(i=2;i<=n*n;i++)

		printf(" %d",ans[i]);

}