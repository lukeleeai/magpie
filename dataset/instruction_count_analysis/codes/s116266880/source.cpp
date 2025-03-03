#include<cstdio>

#include<cstdlib>

#include<cstring>

#define LL long long

#define Maxn 1010



int a[Maxn],op[Maxn];

LL s1=0,s2=0;



int main()

{

	int n,st,ed=0;

	scanf("%d",&n);

	for(int i=1;i<=n;i++) scanf("%d",&a[i]);

	for(int i=1;i<=n;i+=2) if(a[i]>0) s1+=a[i];

	for(int i=2;i<=n;i+=2) if(a[i]>0) s2+=a[i];

	if(s1==0&&s2==0)

	{

		int mx=a[1],id=1;

		for(int i=1;i<=n;i++) if(a[i]>mx)

			mx=a[i],id=i;

		printf("%d\n",mx);

		printf("%d\n",n-1);

		for(int i=n;i>id;i--) printf("%d\n",i);

		for(int i=id-1;i>=1;i--) printf("1\n");

	}

	else{

		if(s1>=s2)

		{

			printf("%lld\n",s1);

			st=1;

		}

		else

		{

			printf("%lld\n",s2);

			st=2;

		}

		op[0]=0;

		for(int i=st;i<=n;i+=2) if(a[i]>0) ed=i;

		for(int i=ed;i>=1;i-=2) if(a[i]>0) st=i;

		for(int i=n;i>ed;i--) op[++op[0]]=i;

		for(int i=ed-2;i>=st;i-=2)

		{

			if(a[i]>0) op[++op[0]]=i+1;

			else op[++op[0]]=i;

		}

		for(int i=st-1;i>=1;i--) op[++op[0]]=1;

		printf("%d\n",op[0]);

		for(int i=1;i<=op[0];i++) printf("%d\n",op[i]);

	}

	return 0;

}
