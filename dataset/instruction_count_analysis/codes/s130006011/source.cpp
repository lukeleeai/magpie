#include<cstring>

#include<cmath>

#include<cstdio>

#include<algorithm>

using namespace std;

int a[100010],n;

inline int read(void)

{

	int x=0,f=1;

     char ch=getchar();

     while(ch>'9'||ch<'0'){

       if(ch=='-') f=-1;

       ch=getchar(); }

     while(ch>='0'&&ch<='9'){

       x=x*10+ch-'0';

       ch=getchar();}

     return x*f;

}

int gcd(int a,int b)

{

     return (b==0)?a:gcd(b,a%b);

}

bool pd()

{

	 long long sum=0;

	 int ex=0,tot=0;

	 for(int i=1;i<=n;++i)

	 {

			sum+=a[i]-1;

			if(a[i]&1) tot++;

			if(a[i]==1) ex=1;

	 }

	 if(ex) return sum%2;

	 if((n-tot)%2) return 1;

	 if(tot==1)

	 {

			int g=0;

			for(int i=1;i<=n;++i) if(a[i]&1) a[i]--;

			for(int i=1;i<=n;++i) g=gcd(g,a[i]);

			for(int i=1;i<=n;++i) a[i]/=g;

			return pd()^1;

	 }

	 return 0;

}

int main()

{

	n=read();

	for(int i=1;i<=n;++i) a[i]=read();

	if(pd()) puts("First");

 	else puts("Second");

	return 0;

}