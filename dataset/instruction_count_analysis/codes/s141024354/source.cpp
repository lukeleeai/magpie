#include <iostream>

#include <memory.h>

#include <deque>

#include <vector>

#include <stdio.h>

using namespace std;

const int MAXN = 10000;

const int INF = 100000000;

const int redirect = 0;

int N, M;

struct  Edge{

    int v, d, c;

};



int dist[MAXN], cost[MAXN];

bool inQueue[MAXN]; 

vector<Edge> g[MAXN];

deque<int> queue;





void addEdge(int u, int v, int d, int c){

    Edge e;

    e.v = v; e.d = d, e.c = c;

    g[u].push_back(e);

    e.v = u;

    g[v].push_back(e);

}



void spfa(int s){

    memset(inQueue, 0, sizeof(bool) * N);

    int i,j;

    for(i = 0; i < N; ++i)

    {

        dist[i] = INF;

        cost[i] = INF;

    }

    queue.push_back(s);

    dist[s] = 0;

    cost[s] = 0;

    inQueue[s] = true;

    while(!queue.empty()){

        int u = queue.front();

        queue.pop_front();

        //printf("Top: %d\n",u);

        for(i = 0; i < g[u].size(); ++i){

            Edge &e = g[u][i];

            if(dist[e.v] > dist[u] + e.d || dist[e.v] == dist[u] + e.d && cost[e.v] > e.c)

            {

                dist[e.v] = dist[u] + e.d;  //即使入&#38431;了，后&#32493;也能&#20248;化全局&#20540;

                cost[e.v] = e.c;

                if(!inQueue[e.v]) {    //&#36825;里&#26816;&#26597;避免重&#22797;入&#38431;

                    if(queue.empty() || dist[e.v] < dist[queue.front()]){

                        queue.push_front(e.v);

                    }else{

                        queue.push_back(e.v);

                    }

                    inQueue[e.v] = true;

                }

            }

            //printf("%d %d %d\n", e.v, dist[e.v], cost[e.v]);

        }

        inQueue[u] =  false;

    }

}



int main(){

    int i, j;

    int u, v, d, c;

    if(redirect)

        freopen("2249-input.txt", "r", stdin);



    while(1){

        scanf("%d%d", &N, &M);

        if(N==0 && M==0) 

            break;

        for(i = 0; i < N; ++i)

            g[i].clear();



        for(i = 0; i < M; ++i){

            scanf("%d%d%d%d", &u, &v, &d, &c);

            addEdge(--u, --v, d, c);

        }

        spfa(0);

        int res = 0; 

        for(i = 0; i < N; ++i){

            //printf("%d ", cost[i]);

            res += cost[i];

        }

        //printf("\n");

        printf("%d\n", res);

    }

    return 0;

}