#include<iostream>

#include<algorithm>

#include<cstring>

using namespace std;

const int N=4e5+10;

struct Ed{int fr,to,w;}E[N];

int f[N],n,Q,fa[N],cc;

long long Ans;

int cmp(const Ed&A,const Ed&B) {return A.w<B.w;}

int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}

void Work()

{

	for(int i=0;i<=n-2;i++)

		f[i+1]=min(f[i+1],f[i]+2);

	f[0]=min(f[0],f[n-1]+2);

}

int main()

{

	cin>>n>>Q;

	memset(f,63,sizeof(f));

	for(int i=1;i<=Q;i++)

	{

		int x,y,w;scanf("%d%d%d",&x,&y,&w);

		E[i]=(Ed){x,y,w};

		f[x]=min(f[x],w+1);

		f[y]=min(f[y],w+2);

	}

	cc=Q;Work();Work();

	for(int i=0;i<=n-2;i++)

		E[++cc]=(Ed){i,i+1,f[i]};

	E[++cc]=(Ed){n-1,0,f[n-1]};

	sort(E+1,E+cc+1,cmp);

	for(int i=1;i<=n;i++) fa[i]=i;

	for(int i=1;i<=cc;i++)

	{

		int fx=find(E[i].fr),fy=find(E[i].to);

		if(fx!=fy) Ans+=E[i].w,fa[fx]=fy;

	}

	cout<<Ans<<endl;

}
