#include<set>

#include<cstdio>

#include<queue>

#include<cmath>

#include<cstring>

#include<iostream>

#include<algorithm>

using namespace std;

long long read(){

	long long f=1,x=0;

	char c=getchar();

	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}

	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}

	return f*x;

}

#define MAXN 100000

struct node{

	int x,y;

	bool color;//0 White 1 Black

}wish[MAXN+5];

int fit[MAXN+5],unfit[MAXN+5];

int main(){

	char c;

	int n=read(),k=read(),tmp,ans=0;

	for(int i=1;i<=n;i++)

	{

		wish[i].x=read()%(2*k),wish[i].y=read()%(2*k),c=getchar();

		if(c=='W')

			wish[i].color=1;

		else

			wish[i].color=0;

	}

	for(int x=0;x<=k;x++)

	{

		tmp=0;

		memset(fit,0,sizeof fit);

		memset(unfit,0,sizeof unfit);

		for(int i=1;i<=n;i++)

		{

			int p=(x<=wish[i].x&&wish[i].x<x+k),

				q=(0<=wish[i].y&&wish[i].y<k);

			if((p^q)==wish[i].color)

			{

				tmp++;

				fit[wish[i].y]++;

			}

			else

				unfit[wish[i].y]++;

		}

		for(int i=0;i<=k;i++)

		{

			if(tmp>ans) ans=tmp;

			if(n-tmp>ans) ans=n-tmp;

			if(i!=k)

				tmp=tmp-fit[i]+unfit[i]-fit[i+k]+unfit[i+k];		

		}

	}

	printf("%d\n",ans);

	return 0;

}
