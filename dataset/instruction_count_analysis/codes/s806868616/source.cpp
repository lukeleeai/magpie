#include"stdc++.h"

#define F(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

typedef long long ll;

const int N=305;

ll nw[N][N],a[N][N],fa[N],rnk[N];

int n;

ll sum;

struct Edge {

	int u,v,w;

};

vector <Edge> E;

bool cmp(Edge a,Edge b) {

	return a.w<b.w;

}

int find(int x) {

	if(x==fa[x]) return x;

	else return fa[x]=find(fa[x]);

}

int uni(int a,int b) {

	int f_a=find(a),f_b=find(b);

	if(f_a==f_b) return 0;

	if(rnk[f_a]<=rnk[f_b]) {

		fa[f_a]=f_b;

		if(rnk[f_a]==rnk[f_b])

			rnk[f_b]++;

	}

	else fa[f_b]=f_a;

}

int main() {

//	freopen("1.in","r",stdin);

	memset(nw,127/2,sizeof(nw));

	cin>>n;

	F(i,0,n) nw[i][i]=0,fa[i]=i;

	F(i,1,n) F(j,1,n) cin>>a[i][j];

	F(i,1,n) F(j,1,n) {

		if(a[i][j]!=a[j][i]) {cout<<-1;return 0;}

		if(i==j&&a[i][j]) {cout<<-1;return 0;}

	}

	F(i,1,n) F(j,i+1,n) E.push_back((Edge) {i,j,a[i][j]});

	sort(E.begin(),E.end(),cmp);

	int lim=E.size(),t=-1;

	F(i,1,n*(n-1)/2) {

		if(++t>=lim) break;

		int u=E[t].u,v=E[t].v,w=E[t].w;

		if(nw[u][v]<=w) continue;

		sum+=w;

		nw[u][v]=nw[v][u]=w;

		F(i,1,n) F(j,1,n) nw[i][j]=min(nw[i][j],min(nw[i][u]+w+nw[v][j],nw[i][v]+w+nw[u][j]));

		int pd=0;

		F(i,1,n) F(j,1,n) if(nw[i][j]!=a[i][j]) pd=1;

//		F(i,1,n){ F(j,1,n) printf("%lld ",nw[i][j]);cout<<"\n";}

//		cout<<endl;

		if(pd==1) continue;

		else break;

		if(t+1==lim) {cout<<"-1";return 0;}

		break;

//		else nw[E[t].u][E[t].v]=nw[E[t].v][E[t].u]=E[t].w,sum+=E[t].w;

	}

//	F(k,1,n) 

//		F(i,1,n)

//			F(j,1,n)

//				nw[i][j]=min(nw[i][j],nw[i][k]+nw[k][j]);

//	F(i,1,n) F(j,1,n) if(nw[i][j]!=a[i][j]) {cout<<-1;return 0;}

	int pd=0;

		F(i,1,n) F(j,1,n) if(nw[i][j]!=a[i][j]) pd=1;

	if(pd==1) cout<<-1;

	else cout<<sum;

	return 0;

}