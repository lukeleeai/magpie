#include<cstdio>

#include<algorithm>

using namespace std;

inline int read()

{

	int s=0;

    char c=getchar();

    while(c<'0' || c>'9')c=getchar();

    while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+c-48,c=getchar();

    return s;

}

int n,a[100005],ans;

int main()

{

	n=read();

	for(register int i=1;i<=n;i++)

		a[i]=read();

	sort(a+1,a+n+1);

	for(register int i=1;i<=n;i++)

	{

		int t=i;

		while(a[t+1]==a[i] && t+1<=n)  t++;

		int cnt=t-i+1;

		if(cnt>a[i])  ans+=cnt-a[i];

		if(cnt<a[i])  ans+=cnt;

		i=t;

	}

	printf("%d",ans);

	return 0;

}