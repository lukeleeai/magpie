#include<algorithm>

#include<cstring>

#include<cstdio>

#define ll long long

#define fr(c,a,b) for(int c=a;c<=b;c++)

#define rf(c,a,b) for(int c=a;c>=b;c--)

const int Max=100010;

const int Min=-1;

using std::sort;

int max(int x,int y){return x>y?x:y;}

int min(int x,int y){return x<y?x:y;}

int abs(int x){return x>0?x:-x;}

inline int read()

{

	int x=0,f=1;

	char ch=getchar();

	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}

	return x*f;

}

inline void write(int x)

{

	if(x<0){putchar('-');x=-x;}

	if(x>9)write(x/10);

	putchar(x%10+'0');

}

int n=read(),t=read(),sum,ans,maxn1,maxn2;

int a[Max];

int main()

{

	fr(i,1,n)a[i]=read();

	rf(i,n,1)

	{

		maxn1=max(a[i],maxn1);

		sum=max(maxn1-a[i],sum);

	}

	rf(i,n,1)

	{

		maxn2=max(a[i],maxn2);

		if(maxn2-a[i]==sum)++ans;

	}

	write(ans);

	return 0;

}