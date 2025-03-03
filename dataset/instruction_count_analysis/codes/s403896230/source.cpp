#include <algorithm>

#include <iostream>

#include <cstring>

#include <cstdlib>

#include <vector>

#include <queue>

#include <cstdio>

#include <cmath>

#include <string>

#include <stack>

#define PI acos(-1.0)

#define inf 0x3f3f3f3f

#define E exp(double(1))

#define maxn 51000

using namespace std;



struct Edge{

    int from,to,dis,next;

    int w;

} edge[maxn];



int b[maxn];

int head[maxn];

int vis[maxn];

int dis[maxn];

int tt[maxn];

int p[maxn];

int cnt;

int n;

int ll;

void add(int q,int h,int len,int w) {

    edge[cnt].from=q;

    edge[cnt].to=h;

    edge[cnt].dis=len;

    edge[cnt].w=w;

    edge[cnt].next=head[q];

    head[q]=cnt;

    cnt++;

}



vector<int>vct[maxn];



int Dijkstra(){

	int i,j,k,tmp,v;

	int flag;

	int yy;

	memset(dis,inf,sizeof(dis));

	memset(vis,0,sizeof(vis));

	memset(tt,0,sizeof(tt));

	memset(p,0,sizeof(p));

	dis[1]=0;

	vis[1]=1;

	int next;

	int s=1;

	yy=0;

	for(int i=0;i<maxn;i++) vct[i].clear();

	while(1){

		tmp=inf;

		next=-1;

		for(int i=head[s]; i!=-1; i=edge[i].next){

            v=edge[i].to;

            if(vis[v])continue;

            if(edge[i].dis+dis[s]<dis[v]){

                dis[v]=edge[i].dis+dis[s];

                tt[v]=edge[i].w;

                p[v]=1;

                vct[v].clear();

                vct[v].push_back(i);

            }else if(edge[i].dis+dis[s]==dis[v]){

                tt[v]=max(tt[v],edge[i].w);

                p[v]++;

                vct[v].push_back(i);

            }

		}

        for(int i=1;i<=n;i++){

            if(vis[i])continue;;

            if(dis[i]<tmp){

                tmp=dis[i];

                next=i;

            }

        }

		if(next==-1)break;



		for(i=0;i<vct[next].size();i++){

         //   printf("%d __>  %d\n",edge[vct[next][i]].from,edge[vct[next][i]].to);

            if(b[vct[next][i]])continue;

            ll+=edge[vct[next][i]].w;

            b[vct[next][i]]=1;

		}

		vis[next]=1;

		s=next;

		if(p[next]>=2){

            yy+=tt[next];

		}

	}

	return yy;

}







int main(){

    int m;

    int q,h,len,w,i,j;

    int ans;

    int ff;

    while(scanf("%d%d",&n,&m)!=EOF,n+m){

        ll=0;

        cnt=0;

        memset(b,0,sizeof(b));

        memset(head,-1,sizeof(head));

        for(i=0;i<m;i++){

            scanf("%d%d%d%d",&q,&h,&len,&w);

            add(q,h,len,w);

            add(h,q,len,w);

        }



        ff=Dijkstra();

     //   printf("%d\n",ll);

        printf("%d\n",ll-ff);

    }

    return 0;

}