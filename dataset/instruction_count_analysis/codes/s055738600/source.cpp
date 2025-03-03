#include<cstdio>

#include<algorithm>

using namespace std;

int N,ans=2e9,zj,w,e,W[300005],E[300005];

char S[300005];

int main()

{

	scanf("%d %s",&N,S);

	for(int i=0;i<N;i++)

	{

		if(S[i]=='W')

		w++;

		else

		e++;

		W[i+1]=w;

		E[i+1]=e;

	}

	for(int i=1;i<=N;i++)

	ans=min(W[i-1]+E[N]-E[i],ans);

	printf("%d",ans);

	return 0;

}