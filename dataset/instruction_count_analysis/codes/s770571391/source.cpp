#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;

struct pp{

	int a,b;

}e[100010];

int cmp(const pp&a,const pp&b)

{

	if(a.a<b.a) return 1;

	return 0;

}

int main ()

{

	int n,m,i;

	scanf("%d%d",&n,&m);

	for(i=1;i<=n;++i) scanf("%d%d",&e[i].a,&e[i].b);

	sort(e+1,e+1+n,cmp);

	long long ans=0;

	for(i=1;i<=n;++i)

	{

		if(m>e[i].b)

		{

			m-=e[i].b;

			ans+=(long long)e[i].b*e[i].a; 

		}

		else

		{

			ans+=(long long)e[i].a*m;

			break;

		}

	} 

	printf("%lld",ans);

}