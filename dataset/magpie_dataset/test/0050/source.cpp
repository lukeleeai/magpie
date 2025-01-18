#include<cmath>

#include<queue>

#include<cstdio>

#include<vector>

#include<cstring>

#include<iostream>

#include<algorithm>

#define RG register

#define LL long long

#define fre(a) freopen(a".in","r",stdin);//freopen(a".out","w",stdout);

using namespace std;

const int MAXN=300000;

int n,m;

int X[MAXN],Y[MAXN],fa[MAXN];

double ans,ALL;

struct ed

{

   int from,to;

   double len;

}edge[MAXN];

bool comp(ed x,ed y){ return x.len>y.len; }

int find(int x)

{

   if(x!=fa[x])

      fa[x]=find(fa[x]);

   return fa[x];

}

void Union(int x,int y)

{

   x=find(x);

   y=find(y);

   fa[x]=y;

}

void work()

{

   int cnt=0;

   for(int i=1;i<=m;i++)

      {

	 int A=edge[i].from,B=edge[i].to;

	 if(find(A)!=find(B))

	    {

	       Union(A,B);

	       ans+=edge[i].len;

	       cnt++;

	    }

	 if(cnt>=n-1)break;

      }

}

int main()

{

   //fre("1");

   scanf("%d%d",&n,&m);

   for(int i=1;i<=n;i++)

      {

	 scanf("%d%d",&X[i],&Y[i]);

	 fa[i]=i;

      }

   for(int i=1,a,b;i<=m;i++)

      {

	 scanf("%d%d",&a,&b);

	 edge[i].from=a;

	 edge[i].to=b;

	 edge[i].len=sqrt((X[a]-X[b])*(X[a]-X[b])+(Y[a]-Y[b])*(Y[a]-Y[b]));

	 ALL+=edge[i].len;

      }

   sort(edge+1,edge+1+m,comp);

   work();

   ans=ALL-ans;

   printf("%.3lf\n",ans);

   return 0;

}