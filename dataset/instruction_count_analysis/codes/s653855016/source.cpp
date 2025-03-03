#include<complex>

#include<cstdio>

using namespace std;

const int N=1e6+7;

int n,minn=0x3f3f3f3f,maxn;

int a[N];

int qread()

{

	int x=0;

	char ch=getchar();

	while(ch<'0' || ch>'9')ch=getchar();

	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}

	return x;

}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

	{

		a[i]=qread();

		maxn=max(maxn,a[i]);

		minn=min(minn,a[i]);

	}

	if(maxn-minn>=2){puts("No");return 0;;}

	if(maxn==minn)

	{

		if(minn==n-1)puts("Yes");

		else if(2*minn<=n)puts("Yes");

		else puts("No");

		return 0;

	}

	int cnt=0;

	for(int i=1;i<=n;i++)

		cnt+=a[i]==minn;

	if(minn<cnt)puts("No");

	else if(n-cnt<2*(maxn-cnt))puts("No");

	else puts("Yes");

	return 0;

}