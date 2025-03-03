#include<stdio.h>

const int maxn=1e5+7;

int pre[maxn];

bool you[maxn];

int Find(int x)

{

    if(pre[x] == x) return x;

    else return pre[x] = Find(pre[x]);

}

void join(int x,int y)

{

    int fx=Find(x);

    int fy=Find(y);

    if(fx!=fy)pre[fx]=fy;

}

int main()

{

    int n,m,sum=0,jian=0;

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)pre[i]=i;

    for(int i=1;i<=m;i++)

    {

        int a,b,c;

        scanf("%d%d%d",&a,&b,&c);

        if(a==b&&you[a]==false)

		{

			jian++;

			you[a]=true;

		}

        join(a,b);

    }

    for(int i=1;i<=n;i++)if(pre[i]==i)sum++;

    printf("%d\n",sum-jian);

    printf("\n");

}