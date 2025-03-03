#include "stdc++.h"

#define inf 0x3f3f3f3f

int h,w,i,j,k,l,x,t,kk,cnt,ans,a[15][1005],s[15][1005],q[15];

bool f;

inline void read(int &x)

{

	short negative=1;

    x=0;

    char c=getchar();

    while(c<'0' || c>'9')

    {

    	if(c=='-')

			negative=-1;

		c=getchar();

	}

    while(c>='0' && c<='9')

        x=(x<<3)+(x<<1)+(c^48),c=getchar();

    x*=negative;

}

inline void print(int x)

{

    if (x<0)

        putchar('-'),x=-x;

    if (x>9)

        print(x/10);

    putchar(x%10+'0');

}

signed main(void)

{

	read(h),read(w),read(kk);

	for (i=1;i<=h;i++)

		for (j=1;j<=w;j++)

		{

			char c=getchar();

			while (c!='1' && c!='0')

				c=getchar();

			a[i][j]=c-48;

		}

	for (i=1;i<=h;i++)

		for (j=1;j<=w;j++)

			s[i][j]=s[i][j-1]+a[i][j];

	ans=inf;

	for (i=0;i<1<<(h-1);i++)

	{

		l=t=0;

		for (j=1;j<=w;j++)

		{

			f=false;

			cnt=1,x=i;

			memset(q,0,sizeof(q));

			for (k=1;k<=h;k++)

			{

				q[cnt]+=s[k][j]-s[k][l];

				if (x%2 && k!=h)

					cnt++;

				x/=2;

			}

			for (k=1;k<=cnt;k++)

				if (q[k]>kk)

				{

					if (l==j-1)

						f=true;

					l=j-1;

					j-=1;

					t++;

					break;

				}

			if (f)

				break;

		}

		if (!f)

			ans=std::min(ans,cnt-1+t);

	}

	print(ans);

	return 0;

} 