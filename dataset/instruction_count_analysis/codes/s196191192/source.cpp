#include "stdc++.h"

using namespace std;



struct node

{

    int x,y;

} red[105],blue[105];



const int MAXN = 1005;

const int MAXM = 100000;

const int INF = 0x3f3f3f3f;

int N;

struct Edge

{

    int to,next,cap,flow,cost,from;

} edge[MAXM];

int head[MAXN],tol;

int pre[MAXN],dis[MAXN];

bool vis[MAXN];



void addedge(int u,int v,int cap,int cost)

{

    edge[tol].from=u;

    edge[tol].to = v;

    edge[tol].cap=cap;

    edge[tol].cost = cost;

    edge[tol].flow = 0;

    edge[tol].next = head[u];

    head[u] = tol++;

    edge[tol].from=v;

    edge[tol].to = u;

    edge[tol].cap = 0;

    edge[tol].cost = -cost;

    edge[tol].flow = 0;

    edge[tol].next = head[v];

    head[v] = tol++;

}

bool spfa(int s,int t)

{

    queue<int>q;

    for(int i = 0; i <= N; i++)

    {

        dis[i] = INF;

        vis[i] = false;

        pre[i] = -1;

    }

    dis[s] = 0;

    vis[s] = true;

    q.push(s);

    while(!q.empty())

    {

        int u = q.front();

        q.pop();

        vis[u] = false;

        for(int i = head[u]; i != -1; i = edge[i].next)

        {

            int v = edge[i].to;

            //printf("i=%d\n",i);

            //printf("dis[v]=%d dis[u]=%d edge[i].cost=%d cap=%d flow=%d\n",dis[v],dis[u],edge[i].cost,edge[i].cap,edge[i].flow);

            if(edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost )

            {

                dis[v] = dis[u] + edge[i].cost;

                pre[v] = i;

                if(!vis[v])

                {

                    vis[v] = true;

                    q.push(v);

                }

            }

        }

    }

    if(pre[t] == -1)

        return false;

    else

        return true;

}

//返回的是最大流，cost 存的是最小费用

int minCostMaxflow(int s,int t,int &cost)

{

    int flow = 0;

    cost = 0;

    while(spfa(s,t))

    {

        int Min = INF;

        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])

        {

            if(Min > edge[i].cap - edge[i].flow)

                Min = edge[i].cap - edge[i].flow;

        }



        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])

        {

            edge[i].flow += Min;

            edge[i^1].flow -= Min;

            cost += edge[i].cost * Min;

        }

        flow += Min;

    }

    return flow;

}



int main()

{

    int S,T;

    cin>>N;

    S=0,T=2*N+1;

    memset(head,-1,sizeof(head));

    for(int i=1; i<=N; i++)

    {

        cin>>red[i].x>>red[i].y;

        addedge(i+N,T,1,0);

    }

    for(int i=1; i<=N; i++)

    {

        cin>>blue[i].x>>blue[i].y;

        addedge(S,i,1,0);

    }

    for(int i=1;i<=N;i++)

    {

        for(int j=1;j<=N;j++)

        {

            if(blue[i].x>red[j].x&&blue[i].y>red[j].y)

                addedge(i,j+N,1,0);

        }

    }

    N=2*N+1;

    int co;

    cout<<minCostMaxflow(S,T,co);

    return 0;

}
