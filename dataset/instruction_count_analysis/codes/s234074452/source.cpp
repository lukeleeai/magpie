#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 1000010

char s[MAXN],t[MAXN];

int n,p[MAXN],l,ans,x[MAXN],y[MAXN],sl,sr,k;

int main()

{

	scanf("%d%s%s",&n,s+1,t+1);

	char ls=t[n];

	int np=n,flag=1;

	for(int i=1;i<=n;i++)

		if(s[i]!=t[i])

		{

			flag=0;

			break;

		}

	if(flag==1)

	{

		printf("0\n");

		return 0;

	}

	flag=1;

	for(int i=n-1;i>=0;i--)

		if(t[i]!=ls)

		{

			np=min(np,i+1);

			for(;np;np--)

				if(s[np]==ls)

				{

					p[i+1]=np;

					break;

				}

			if(np==0)

			{

				flag=0;

				break;

			}

			ls=t[i];

		}

	if(flag==0)

	{

		printf("-1\n");

		return 0;

	}

	ans=1;

	sl=0,sr=0;

	for(int i=1;i<=n;i++)

	{

		if(p[i]==0) continue;

		if(l>=p[i])

		{

			k++;

			ans=max(ans,y[sl]+k);

			x[sr]=i-k,y[sr++]=2-k;

			l++;

		}

		else if(l<p[i]&&p[i]<i)

		{

			if(ans==1)

			{

				ans=2,l=i;

				x[sr]=i-k,y[sr++]=2-k;

			}

			else if(ans==2)

			{

				sl=sr;

				x[sr]=i-k,y[sr++]=2-k;

				l=i;

			}

			else

			{

				l=p[i];

				k++;

				for(int j=sl;j<sr;j++)

					if(x[sl]+k-1<p[i]) sl++;

					else

					{

						ans=max(ans,y[j]+k);

						break;

					}

				x[sr]=i-k,y[sr++]=2-k;

			}

		}

		else if(l<p[i]&&p[i]==i)

		{

			k=0;

			sl=sr;

			l=i;

		}

	}

	printf("%d\n",ans);

}

/*

15

dqvfqxxbuizsxiw

ddqqvfqqxxxxbuu





*/