#include<cstdio>

#include<algorithm>

using namespace std;



char s1[200001],s2[200001];

int main(){

	int n,m,k;

	int x,y;

	scanf("%d%d%d",&n,&m,&k);

	scanf("%d%d%s%s",&x,&y,s1+1,s2+1);

	int l1=1,r1=n,l2=1,r2=m;

	for(int i=k;i;i--){

		if(s2[i]=='U')r1=min(n,r1+1);

		if(s2[i]=='D')l1=max(1,l1-1);

		if(s2[i]=='L')r2=min(m,r2+1);

		if(s2[i]=='R')l2=max(1,l2-1);

		if(s1[i]=='U')l1++;

		if(s1[i]=='D')r1--;

		if(s1[i]=='L')l2++;

		if(s1[i]=='R')r2--;

		//printf("%d %d %d %d\n",l1,r1,l2,r2);

		if(l1>r1||l2>r2){

			printf("NO\n");

			return 0;

		}

	}

	if(x>=l1&&x<=r1&&y>=l2&&y<=r2)

		printf("YES\n");

	else printf("NO\n");

}