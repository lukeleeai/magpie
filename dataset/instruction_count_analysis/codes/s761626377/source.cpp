#include<cstdio>

#include<vector>

#include<algorithm>

using namespace std;



#define MAXN 100000

#define INF (1ll<<50)

int N,M;

struct Edge{

    int v,w;

    Edge(){}

    Edge(int a,int b){

        v=a,w=b;

    }

};

vector<Edge> G[MAXN+5];

long long Lim[2][MAXN+5];

//S1 < Lim[0][i]

//S1 > Lim[1][i]



void dfs(int u,int f,int Sign,long long Sum){

    for(int i=0;i<int(G[u].size());i++){

        int v=G[u][i].v,w=G[u][i].w;

        if(v!=f){

            int id=Sign==1?0:1;

            long long tmp=Sum+Sign*w;

            if(Lim[id][v]!=INF){

                if(Lim[id][v]!=tmp){

                    puts("0");

                    exit(0);

                }

                else

                    continue;

            }

            Lim[id][v]=tmp;

            dfs(v,u,-Sign,tmp);

        }

    }

}



int main(){

    scanf("%d%d",&N,&M);

    for(int i=1;i<=M;i++){

        int u,v,w;

        scanf("%d%d%d",&u,&v,&w);

        G[u].push_back(Edge(v,w));

        G[v].push_back(Edge(u,w));

    }

    fill(Lim[0]+1,Lim[0]+N+1,INF);

    fill(Lim[1]+1,Lim[1]+N+1,INF);

    dfs(1,-1,1,0ll);

    long long Left=0,Right=INF;

    for(int i=2;i<=N;i++){

        if(Lim[1][i]!=INF)

            Left=max(Left,Lim[1][i]);

        if(Lim[0][i]!=INF)

            Right=min(Right,Lim[0][i]);

    }

    long long Sure=-1,flag=INF;

    for(int i=2;i<=N;i++)

        if(Lim[0][i]!=INF&&Lim[1][i]!=INF){

            long long k=Lim[0][i]+Lim[1][i];

            if(k%2||k/2<0) flag=0;

            if(Sure==-1) Sure=k/2;

            else if(Sure!=k) flag=0;

        }

    if(Sure!=-1){

        if(Left<Sure&&Sure<Right) puts("1");

        else puts("0");

        return 0;

    }

    printf("%lld",min(flag,max(Right-Left-1,0ll)));

}
