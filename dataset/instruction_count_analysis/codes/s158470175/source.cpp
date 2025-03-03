#include<cstdio>

#include<cctype>

#include<cstring>

#include<algorithm>

#define LL long long

#define OP "then"

const int MAXN(1e5+5);

inline int read()

{

	int x(0);

	int flag(1);

	char ch(getchar()); 

	while(!isdigit(ch))

	{

		if(ch=='-')

		{

			flag=-1;

		}

		ch=getchar();

	}

	while(isdigit(ch))

	{

		x=(x<<1)+(x<<3)+(ch^48);

		ch=getchar();

	}

	return flag*x;

}

int fx[MAXN];

int fy[MAXN];

LL wx[MAXN];

LL wy[MAXN];

int findx(int x)

{

	if(fx[x]==x) 

	{

		return x;

	}

	int y=findx(fx[x]); 

	wx[x]+=wx[fx[x]];

	return fx[x]=y;

}

int findy(int x)

{

	if(fy[x]==x)

	{

		return x;

	}

	int y(findy(fy[x]));

	wy[x]+=wy[fy[x]];

	return fy[x]=y;

}

bool unionnx(int x,int y,LL val1,LL val2)

{

	int a(findx(x));

	int b(findx(y));

	if(a==b)

	{

		return wx[x]-wx[y]==val2-val1;//1 x  2 y

	}

	fx[a]=b; 

	wx[a]=val2-val1+wx[y]-wx[x];

	return 1;

}

bool unionny(int x,int y,LL val1,LL val2)

{

	int a(findy(x));

	int b(findy(y));

	if(a==b)

	{

		return wy[x]-wy[y]==val2-val1;//1 x  2 y

	}

	fy[a]=b; 

	wy[a]=val2-val1+wy[y]-wy[x];

	return 1;

}

class Node

{

	public:

		int x;

		int y;

		LL val;

}node[MAXN];

bool cmpx(const Node &a,const Node &b )

{

	return a.x<b.x;

}

bool cmpy(const Node &a,const Node &b)

{

	return a.y<b.y;

}

LL h1[MAXN];

LL h2[MAXN];

int main()

{

	//std::freopen(OP".in","r",stdin);

	//std::freopen(OP".out","w",stdout);

	std::memset(h1,63,sizeof h1); 

	std::memset(h2,63,sizeof h2);

	std::memset(wx,0,sizeof wx);

	std::memset(wy,0,sizeof wy);

	int r(read()),c(read()),n(read());

	for(int i=1;i<=r;i++)

	{

		fx[i]=i;

	}

	for(int i=1;i<=c;i++)

	{

		fy[i]=i;

	}

	bool flag=1;

	for(int i=1;i<=n;i++)

	{

		int x(read()),y(read()),val(1ll*read());

		node[i]=(Node){x,y,val};

		if(val<0)

		{

			flag=0;

		}

	}

	if(!flag)

	{

		std::printf("No\n");

		return 0;

	}

	std::sort(node+1,node+1+n,cmpx);

	for(int i=1;i<n;i++)

	{

		if(node[i].x==node[i+1].x)

		{

			flag&=unionny(node[i].y,node[i+1].y,node[i].val,node[i+1].val);

		}

	}

	std::sort(node+1,node+1+n,cmpy);

	for(int i=1;i<n;i++)

	{

		if(node[i].y==node[i+1].y)

		{

			flag&=unionnx(node[i].x,node[i+1].x,node[i].val,node[i+1].val);

		}

	}

    for(int i=1;i<=n;i++)

    {

       	int x=findx(node[i].x);

       	h1[x]=std::min(1ll*h1[x],node[i].val+wx[node[i].x]);

    }

    for(int i=1;i<=r;i++)

    {

       	int x=findx(i);

       	h2[x]=std::min(1ll*h2[x],-wx[i]);

    }

    for(int i=1;i<=r;i++)

    {

        if(fx[i]==i&&h1[i]+h2[i]<0)

		{

        	flag=0;

        }    		

    }

	(!flag)?std::printf("No\n"):std::printf("Yes\n");

	return 0;

}

/*

6

2 2

3

1 1 0

1 2 10

2 1 20

2 3

5

1 1 0

1 2 10

1 3 20

2 1 30

2 3 40

2 2

3

1 1 20

1 2 10

2 1 0

3 3

4

1 1 0

1 3 10

3 1 10

3 3 20

2 2

4

1 1 0

1 2 10

2 1 30

2 2 20

1 1 

1

1 1 -1

*/