#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;



const int MAXN=1e5+5;



int n,m;

bool vis[MAXN];

int head[MAXN],ecnt;

struct edge{

    int v,nxt;

}E[MAXN*2];

int deq[MAXN*2],l,r;



void addedge(int u,int v){

    E[++ecnt]=(edge){v,head[u]};

    head[u]=ecnt;

}



int check(int u){

    for(int i=head[u];i;i=E[i].nxt){

        int v=E[i].v;

        if(!vis[v]) return v;

    }

    return -1;

}



int main(){



    scanf("%d%d",&n,&m);

    l=n,r=n+1;

    for(int i=1;i<=m;i++){

        int u,v;

        scanf("%d%d",&u,&v);

        addedge(u,v);

        addedge(v,u);

        if(i==1){

            deq[l]=u;

            deq[r]=v;

            vis[u]=vis[v]=1;

        }

    }

    while(1){

        int u=check(deq[l]);

        if(u==-1) break;

        else deq[--l]=u,vis[u]=1;

    }

    while(1){

        int u=check(deq[r]);

        if(u==-1) break;

        else deq[++r]=u,vis[u]=1;

    }

    printf("%d\n",r-l+1);

    for(int i=l;i<=r;i++)

        printf("%d ",deq[i]);





    fclose(stdin);

    fclose(stdout);

}
