#include"stdc++.h"

#define LL long long

#define uLL unsigned long long



using namespace std;

const int N=3e5+10;

int rd()

{

    int x=0,w=1;char ch=0;

    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}

    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}

    return x*w;

}

int n,a[N],bt[N],b[N],c1[N],c2[N];

void add(int x,int y){while(x<=n) bt[x]+=y,x+=x&(-x);}

int gsm(int x){int an=0;while(x) an+=bt[x],x-=x&(-x);return an;}

void wa(){puts("No");exit(0);}

void ac(){puts("Yes");}



int main()

{

////

    n=rd();

    for(int i=1;i<=n;++i) a[i]=rd();

    for(int i=1;i<=n;++i)

	if((a[i]^i)&1) wa();

    for(int o=0;o<=1;++o)

    {

	memset(bt,0,sizeof(bt));

	for(int i=1+((o^1)&1);i<=n;i+=2)

	{

	    b[i]+=(bool)(gsm(n)-gsm(a[i]));

	    add(a[i],1);

	}

	memset(bt,0,sizeof(bt));

	for(int i=n-((o^n)&1);i>=1;i-=2)

	{

	    b[i]+=(bool)gsm(a[i]);

	    add(a[i],1);

	    if(b[i]==2) wa();

	}

    }

    for(int i=1;i<=n;i+=2)

	if(i<a[i]) ++c1[i],--c1[a[i]+1];

    for(int i=2;i<=n;i+=2)

	if(i<a[i]) ++c2[i],--c2[a[i]+1];

    for(int i=1;i<=n;++i)

    {

	c1[i]+=c1[i-1],c2[i]+=c2[i-1];

	if(c1[i]&&c2[i]) wa();

    }

    ac();

    return 0;

}
