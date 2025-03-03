#include <iostream>

#include <stdio.h>

#include <math.h>

#include <string.h>

#include <time.h>

#include <stdlib.h>

#include <string>

#include <bitset>

#include <vector>

#include <set>

#include <map>

#include <queue>

#include <algorithm>

#include <sstream>

#include <stack>

#include <iomanip>

using namespace std;

#define pb push_back

#define mp make_pair

typedef pair<int,int> pii;

typedef long long ll;

typedef double ld;

typedef vector<int> vi;

#define fi first

#define se second

#define fe first

#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}

#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}

#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}

#define es(x,e) (int e=fst[x];e;e=nxt[e])

#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])

#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}

#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}

#define SZ 3123456

int n,m,t,x[SZ];

char ch,B[1<<20],*S=B,*T=B;

#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<20,stdin),S==T)?0:*S++)

#define isd(c) (c>='0'&&c<='9')

int aa,bb;int F(){

	int x; scanf("%d",&x); return x;

    while(ch=getc(),!isd(ch)&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);

    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;

}

#define gi F()

#define BUFSIZE 5000000

namespace fob {char b[BUFSIZE]={},*f=b,*g=b+BUFSIZE-2;}

#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)

#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)

struct foce {~foce() {pob; fflush(stdout);}} _foce;

namespace ib {char b[100];}

inline void pll(ll x)

{

    if(x==0) {pc(48); return;}

    //if(x<0) {pc('-'); x=-x;} //如果有负数就加上 

    char *s=ib::b;

    while(x) *(++s)=x%10, x/=10;

    while(s!=ib::b) pc((*(s--))+48);

}

ll qf[SZ],f[SZ];

int main()

{

	n=gi,m=gi,t=gi;

	for(int i=1;i<=n;i++) x[i]=gi;

	int p=0; f[0]=0; qf[0]=-2LL*x[1];

	for(int i=1;i<=n;i++)

	{

		while(t<=2*(x[i]-x[p+1])&&p<i) ++p;

		ll c=1e18;

		if(p<i)

			c=min(c,f[p]+max(t,2*(x[i]-x[p+1])));

		if(p) c=min(c,qf[p-1]+2*x[i]);

		f[i]=c;

		qf[i]=min(qf[i-1],f[i]-2LL*x[i+1]);

	}

	printf("%lld\n",f[n]+m);

}
