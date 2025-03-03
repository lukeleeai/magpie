#include <cstdio>

int n,ans;

char ch1,ch2;

int main()

{

	scanf("%d",&n);

	ch1=getchar();

	ch1=getchar();

	ans=1;

	for(int i=1;i<n;i++)

	{

	    ch2=getchar();

	    if(ch2!=ch1) ans++;

	    ch1=ch2;

	}

	printf("%d",ans);

}