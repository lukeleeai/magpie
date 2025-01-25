#include"stdc++.h"

using namespace std;

const int INF=1001001001;

const int MAX_V=1000;

const int S=MAX_V-2,T=MAX_V-1;

struct edge{

    int to,cap,cost,rev;

    edge(int to,int cap,int cost,int rev)

        :to(to),cap(cap),cost(cost),rev(rev){}

};

vector<edge>G[MAX_V];

int dist[MAX_V];

int prevv[MAX_V],preve[MAX_V];



void add_edge(int from,int to,int cap,int cost){

    G[from].push_back(edge(to,cap,cost,G[to].size()));

    G[to].push_back(edge(from,0,-cost,G[from].size()-1));

}



int min_cost_flow(int s,int t,int f){

    int res=0;

    while(f>0){

        fill_n(dist,MAX_V,INF);

        dist[s]=0;

        bool update=true;

        while(update){

            update=false;

            for(int v=0;v<MAX_V;v++){

                if(dist[v]==INF)continue;

                for(int i=0;i<G[v].size();i++){

                    edge &e=G[v][i];

                    if(e.cap>0&&dist[e.to]>dist[v]+e.cost){

                        dist[e.to]=dist[v]+e.cost;

                        prevv[e.to]=v;

                        preve[e.to]=i;

                        update=true;

                    }

                }

            }

        }



        if(dist[t]==INF)return -1;



        int d=f;

        for(int v=t;v!=s;v=prevv[v]){

            edge &e=G[prevv[v]][preve[v]];

            d=min(d,e.cap);

        }



        f-=d;

        res+=dist[t]*d;

        for(int v=t;v!=s;v=prevv[v]){

            edge &e=G[prevv[v]][preve[v]];

            e.cap-=d;

            G[v][e.rev].cap+=d;

        }

    }

    return res;

}



int D,K,L;

int M,N,P;

int c[8][8],r[200],t[200];



int cost[1<<16];

int dp[9][1<<16];



void DPing(){

    fill_n(*dp,9*(1<<16),INF);

    dp[0][0]=0;

    for(int i=0;i<D;i++){

        for(int j=0;j<L;j++){

            for(int k=0;k<(1<<(2*K));k++){

                for(int l=0;l<K;l++){

                    if((k>>(2*l)&3)>=2)continue;

                    dp[j+1][k+(1<<(2*l))]=min(dp[j+1][k+(1<<(2*l))],dp[j][k]+c[i][l]);

                }

            }

        }

        for(int j=0;j<(1<<(2*K));j++){

            for(int k=1;k<=L;k++){

                dp[0][j]=min(dp[0][j],dp[k][j]);

                dp[k][j]=INF;

            }

        }

    }



    for(int i=0;i<(1<<(2*K));i++){

        cost[i]=dp[0][i];

    }

}



bool in(int a,int b){

    for(int i=0;i<K;i++){

        int va=a>>(i*2)&3;

        int vb=b>>(i*2)&3;

        if(va>vb)return false;

    }

    return true;

}



void solve(){

    DPing();

    fill_n(G,MAX_V,vector<edge>());



    for(int i=0;i<M;i++)add_edge(S,i,1,0);

    for(int i=0;i<P;i++)add_edge(M+i,T,1,0);

    for(int i=0;i<M;i++){

        if(cost[r[i]]!=INF)add_edge(i,T,1,cost[r[i]]);

        for(int j=0;j<P;j++){

            if(in(t[j],r[i])&&cost[r[i]-t[j]]!=INF){

                add_edge(i,M+j,1,cost[r[i]-t[j]]);

            }

        }

    }



    cout<<min_cost_flow(S,T,N)<<endl;





}



int get(){

    int ret=0;

    for(int i=0;i<K;i++){

        int v;cin>>v;

        ret+=v<<(i*2);

    }

    return ret;

}



int main(){

    while(cin>>D>>K>>L,D||K||L){

        for(int i=0;i<D;i++)for(int j=0;j<K;j++)cin>>c[i][j];

        cin>>M>>N>>P;

        for(int i=0;i<M;i++)r[i]=get();

        for(int i=0;i<P;i++)t[i]=get();

        solve();

    }





    return 0;

}