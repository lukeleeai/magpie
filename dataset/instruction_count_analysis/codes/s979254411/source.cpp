#include<cstdio>

#include<cstring>

#include<algorithm>

int Min(int a,int b){return a<b?a:b;}

int Max(int a,int b){return a>b?a:b;}

inline int read()

{

	int x=0,f=1;char c=getchar();

	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}

	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}

	return x*f;

}

int n,v[100005],num[100005],ans,m1,m2,M1,M2,b1,b2,B1,B2;

int main()

{

	n=read();

	for(int i=1;i<=n;i++) v[i]=read();

	for(int i=1;i<=n;i+=2) num[v[i]]++;

	for(int i=1;i<=100000;i++)

	{

		if(num[i]>=m2)

		{

			if(num[i]>=m1)

			{

				m2=m1;b2=b1;

				m1=num[i];b1=i;

			}

			else{m2=num[i];b2=i;}

		}

	}

//	printf("%d\n",m);

	memset(num,0,sizeof num);

	for(int i=2;i<=n;i+=2) num[v[i]]++;

	for(int i=1;i<=100000;i++)

	{

		if(num[i]>=M2)

		{

			if(num[i]>=M1)

			{

				M2=M1;B2=B1;

				M1=num[i];B1=i;

			}

			else{M2=num[i];B2=i;}

		}

	}

	//printf("%d %d %d %d\n",m1,m2,M1,M2);

	if(b1!=B1) printf("%d",n-M1-m1);

	else

	{

		if(M2>0&&m2>0) return 0*printf("%d",n-Max(m1+M2,m2+M1));

		if(M2>0) return 0*printf("%d",n-m1-M2);

		if(m2>0) return 0*printf("%d",n-m2-M1);

		printf("%d",n>>1);

	}

}
