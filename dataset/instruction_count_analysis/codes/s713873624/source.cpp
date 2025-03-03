#include"stdc++.h"

using namespace std;

typedef long long int ll;

const ll MAXN=4e5+51;

struct Edge{

	ll from,to,dist;

	inline bool operator <(const Edge &rhs)const

	{

		return this->dist<rhs.dist;

	}

};

Edge ed[MAXN];

ll nc,cnt,x,y,z,tot;

ll dist[MAXN],boss[MAXN];

inline ll read()

{

    register ll num=0,neg=1;

    register char ch=getchar();

    while(!isdigit(ch)&&ch!='-')

    {

        ch=getchar();

    }

    if(ch=='-')

    {

        neg=-1;

        ch=getchar();

    }

    while(isdigit(ch))

    {

        num=(num<<3)+(num<<1)+(ch-'0');

        ch=getchar();

    }

    return num*neg;

} 

inline void setup(ll cnt)

{

	for(register int i=0;i<cnt;i++)

	{

		boss[i]=i;

	}

}

inline void update()

{

	for(register int i=0;i<nc;i++)

	{

		dist[i]=min(dist[i],dist[(i+nc-1)%nc]+2);

	}

}

inline ll findb(ll node)

{

	if(node==boss[node])

	{

		return node;

	}

	boss[node]=findb(boss[node]);

	return boss[node];

}

inline void Union(ll x,ll y)

{

	ll bx=findb(x),by=findb(y);

	if(bx!=by)

	{

		boss[by]=bx;

	}

}

inline ll Kruskal()

{

	ll res=0,k=0;

	sort(ed,ed+tot),setup(nc);

	for(register int i=0;k<nc-1;i++)

	{

		if(findb(ed[i].from)!=findb(ed[i].to))

		{

			Union(ed[i].from,ed[i].to),res+=ed[i].dist,k++;

		}

	}

	return res;

}

int main()

{

	nc=read(),cnt=read(),memset(dist,0x3f,sizeof(dist));

	for(register int i=0;i<cnt;i++)

	{

		x=read(),y=read(),z=read();

		ed[tot++]=(Edge){x,y,z};

		dist[x]=min(dist[x],z+1),dist[y]=min(dist[y],z+2);

	}

	update(),update();

	for(register int i=0;i<=nc;i++)

	{

		ed[tot++]=(Edge){i,(i+1)%nc,dist[i]};

	}

	printf("%lld",Kruskal());

}