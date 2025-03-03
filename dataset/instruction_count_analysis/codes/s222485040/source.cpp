#include"stdc++.h"

using namespace std;



typedef long long lint;

#define fint register int

#define flint register lint



inline int ty()

{

	register int a=0,b=1,c=getchar();

	while(!isdigit(c))b^=c=='-',c=getchar();

	while(isdigit(c))a=a*10+c-48,c=getchar();

	return b?a:-a;

}



const int _ = 200007 , _e = 999999;



struct edges

{

	int a,b,v;

	edges(int _a=0,int _b=0,int _v=0)

	{

		a=_a,b=_b,v=_v;

	}

	inline friend int operator < (edges a,edges b)

	{

		return a.v<b.v;

	}

}e[_e];

int ecnt=0;

inline void adde(int a,int b,int c)

{

	e[++ecnt]=edges(a,b,c);

}



int bfa[_];

inline int findbfa(int x)

{

	return bfa[x]==x?x:bfa[x]=findbfa(bfa[x]);

}

inline void link(int a,int b)

{

	a=findbfa(a),b=findbfa(b);

	if(a==b)return;

	bfa[a]=b;

}



int n,qq;



lint kuro()

{

	sort(e+1,e+ecnt+1);

	for(fint i=0;i<n;i++)bfa[i]=i;

	flint ans=0;

	for(fint i=1;i<=ecnt;i++)

	{

		fint a=e[i].a,b=e[i].b,c=e[i].v;

		if(findbfa(a)==findbfa(b))continue;

		link(a,b),ans+=c;

	}

	return ans;

}



int midis[_];



int main()

{

	memset(midis,63,sizeof(midis));

	

	n=ty(),qq=ty();

	for(fint i=1;i<=qq;i++)

	{

		fint a=ty(),b=ty(),c=ty();

		midis[(a+1)%n]=min(midis[(a+1)%n],c+1);

		midis[(b+1)%n]=min(midis[(b+1)%n],c+2);

		e[++ecnt]=edges(a,b,c);

	}



	for(fint i=0;i<n+n+n;i++)

	{

		fint a=i%n;

		midis[a]=min(midis[a],midis[(a-1+n)%n]+2);

	}



	for(fint i=0;i<n;i++)e[++ecnt]=edges((i-1+n)%n,i,midis[i]);



	printf("%lld\n",kuro());



	return 0;

}
