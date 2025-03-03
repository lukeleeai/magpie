#include<cstdio>

int fa[100001],fl,fr,d[100001],n,m,l,r,d2;

bool j;

int gf(int x)

{

	int d1=fa[x];

	if(x==fa[x])return x;

	fa[x]=gf(fa[x]);

	d[x]+=d[d1];

	return fa[x];

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

	fa[i]=i;

	while(m)

	{

		scanf("%d%d%d",&l,&r,&d2);

		fl=gf(l);fr=gf(r);

		if(fl==fr&&d[r]-d[l]!=d2)

		{

			j=1;break;

		}

		else 

		{

			fa[fr]=fl;d[fr]=d2-d[r]+d[l];

		}

		m--;

	}

	if(j)printf("No");

	else printf("Yes");

}