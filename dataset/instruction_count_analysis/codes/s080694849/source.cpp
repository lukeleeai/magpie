/*

ID:xmydada1

LANG:C++

TASK:

*/

#include"stdc++.h"

#define reg register



using namespace std;

const int N=2e5+7;

int m,n,ans=0,sum=0,p,q;

int a[N],b[N];

inline int read() {

reg int s = 0, t = 0; reg char ch = getchar();

while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();

while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();

return t ? -s : s;

}



inline void print(reg long long x) {

if(x < 0) putchar('-'), x = -x;

if(x > 9) print(x / 10);

putchar(x % 10 + 48);

}

int main()

{

//	freopen("triangle.in","r",stdin);

//	freopen("triangle.out","w",stdout);

	n=read();n=n*2-1;

	for(int i=1;i<=n;i++)a[i]=read();

	int l=0,r=1e9+7;

	while(l<=r)

	{

		int mid=l+r>>1;

		for(int i=1;i<=n;i++)

		{  

			if(a[i]>mid)b[i]=1;

			else b[i]=0;

		}

		b[n+1]=b[n];

		b[0]=b[1];

		p=0;

		for(int i=1;i<=n+1;i++)

		{

			if(b[i-1]!=b[i]){p++;}

			if(b[i-1]==b[i]&&p)

			{

				if(p%2==0)for(int j=i-p;j<=i-1;j++)b[j]=b[i];

				else 

				{

					q=p>>1;

					for(int j=i-p;j<=i-q-2;j++)b[j]=b[i-p-1];

					for(int j=i-q-1;j<=i-1;j++)b[j]=b[i];	

				}

				p=0;

			}

		}

		

		if(b[n/2+1]){l=mid+1;}

		else {r=mid-1;ans=mid;}

		memset(b,0,sizeof(b));

	}

	printf("%d",ans);



return 0;

}


