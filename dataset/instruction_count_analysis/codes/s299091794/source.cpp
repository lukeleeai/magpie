#include<iostream>

#include<iomanip>

#include<cmath>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<algorithm>

#include<set>

#include<map>

#include<queue>

#include<stack>

#include<vector>

#include<cctype>

#define szxb 200010

using namespace std;

int n;

long long a[szxb];

int main()

{

	memset(a,0,sizeof(a));

	scanf("%d",&n);

	int t;

	long long total=0;

	for(register int i=1;i<=n;i++)

	{

		scanf("%d",&t);

		total+=t,a[i]=(a[i-1]+t);

	}

	long long minn=1e17;

	for(register int i=2;i<=n;i++)

	{

		minn=(min(minn,abs(total-(a[i-1]*2))));

	}

	printf("%lld",minn);

	putchar(10);

	return 0;

}