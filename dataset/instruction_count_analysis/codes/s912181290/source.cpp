#include "stdc++.h"

//#pragma GCC optimize("Ofast")



#define fi first

#define se second



const int N = 100100;



using namespace std;



struct edge{

    int a,b,c,flow;

};

const int MAXN = 200200;

const int inf_int = 1e9;

struct Flow{

    vector<int> g[MAXN];

    vector<edge> e;

    inline int add_edge(int a,int b,int c){

        edge e1 = {a,b,c,0};

        edge e2 = {b,a,0,0};

        int id = e.size();

        g[a].push_back(id);

        e.push_back(e1);

        g[b].push_back(id+1);

        e.push_back(e2);

        return id;

    }



    int s,t,n;

    int ptr[MAXN],dis[MAXN],q[MAXN];

    void init(int S,int T,int N){

        s = S;

        t = T;

        n = N;

    }





    bool bfs(){

        fill(dis,dis+n,inf_int);

        dis[s] = 0;

        int qh = 0,qt = 1;

        q[0] = s;

        while(qh<qt){

            int v = q[qh++];

            for(int id:g[v]){

                edge &r = e[id];

                int to = r.b;

                if(r.c > r.flow && dis[to]>dis[v]+1){

                    dis[to] = dis[v]+1;

                    q[qt++] = to;

                }

            }

        }

        return dis[t]!=inf_int;

    }







    int dfs(int v,int flow){

        if(v==t)

            return flow;

        for(;ptr[v]<g[v].size();++ptr[v]){

            int id = g[v][ptr[v]];

            edge &r = e[id];

            if(r.c > r.flow && dis[r.b]==dis[v]+1){

                int pushed = dfs(r.b, min(flow, r.c - r.flow));

                if(pushed){

                    e[id].flow+=pushed;

                    e[id^1].flow-=pushed;

                    return pushed;

                }

            }

        }

        return 0;

    }



    void delete_all(){

        e.clear();

        for(int i = 0;i<n;++i){

            g[i].clear();

        }

    }



    void clear(){

        int m = e.size();

        for(int i = 0;i<m;++i){

            e[i].flow=0;

        }

    }





    int flow(){

        int res = 0;

        while(bfs()){

            fill(ptr,ptr+n,0);

            while(int pushed = dfs(s,inf_int)){

                res+=pushed;

            }

        }

        return res;

    }



} flow;



int n;

int p[N];

int q[N];

int A[N];

int B[N];



int main()

{

        //freopen("input.txt", "r", stdin);

        //freopen("output.txt", "w", stdout);



        ios_base::sync_with_stdio(0);



        cin >> n;

        for(int i = 0; i < n; i++){

                cin >> p[i];

        }

        for(int i = 0; i < n; i++){

                cin >> q[i];

        }

        int G = 0;

        for(int i = 0; i < n; i++){

                if(A[i] == 0){

                        G += 1;

                        A[i] = G;

                        int j = p[i];

                        while(j != i){

                                A[j] = G;

                                j = p[j];

                        }

                }

                if(B[i] == 0){

                        G += 1;

                        B[i] = G;

                        int j = q[i];

                        while(j != i){

                                B[j] = G;

                                j = q[j];

                        }

                }

        }

        G += 1;

        flow.init(0, G, G + 1);



        int res = n;

        for(int i = 0; i < n; i++){

                if(p[i] == i && q[i] == i){

                        res -= 1;

                } else if(p[i] == i){

                        flow.add_edge(B[i], G, 1);

                } else if(q[i] == i){

                        flow.add_edge(0, A[i], 1);

                } else{

                        flow.add_edge(B[i], A[i], 1);

                        if(p[i] == q[i]){

                                flow.add_edge(A[i], B[i], 1);

                        }

                }

        }

        res -= flow.flow();



        cout << res << '\n';

}
