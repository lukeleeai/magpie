#include<cstdio>

#include<cstring>

#include<algorithm>

#define maxn 500005

using namespace std;

int n,x[maxn],sum;

char s[maxn];

int main()

{

	scanf("%s",s+1);

	n=strlen(s+1);

	reverse(s+1,s+n+1);

	for(int i=1;i<=n;i++) x[i]=(s[i]-'0')*9;

	for(int i=1;i<=n;i++) x[i+1]+=x[i]/10,x[i]%=10;

	if(x[n+1]) n++;

	for(int i=1;i<=n;i++) sum+=x[i];

	for(int k=1;k<=n*2;k++)

	{

		int v=9,j=1;

		while(v)

		{

			sum-=x[j],x[j]+=v;

			v=x[j]/10,x[j]%=10;

			sum+=x[j];

			if(j>n) n++;

			j++;

		}

		if(sum<=9*k) { printf("%d\n",k); return 0; }

	}

}