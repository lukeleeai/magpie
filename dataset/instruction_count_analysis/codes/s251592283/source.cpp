#include<stdio.h>

#include<string.h>

#include<math.h>

#include<algorithm>

#include<algorithm>



using namespace std;



const int maxn = 1010;

const int inf = 0x3f3f3f3f;



int dis[maxn][maxn];

int n,m,L;



struct node

{

    int s,t;

    node(int _s ,int _t):s(_s),t(_t) {}

    node() {};

    bool operator <(const node& o)const

    {

        return t < o.t;

    }

} q[maxn];



int nn;

bool e[maxn][maxn];

void build()

{

    memset(e,0,sizeof(e));

    nn = L;

    for (int i=1; i<=nn; i++)

        for (int j=i+1; j<=nn; j++)

        {

            int d1 = q[j].t - q[i].t;

            int d2 = dis[q[j].s][q[i].s];

            if (d2 <= d1)

            {

                e[i][j] = 1;

                //printf("%d %d\n",i,j);

            }

        }

    for (int k=1;k<=nn;k++)

        for (int i=1;i<k;i++)

            for (int j=k+1;j<=nn;j++)

                e[i][j] = (e[i][j] | (e[i][k] & e[k][j]));

    return ;

}



int vis[maxn];

int cx[maxn];

int cy[maxn];

int find(int u)

{

    for (int v = u; v<=nn; v++)

    {

        if (e[u][v] && !vis[v])

        {

            vis[v] = 1;

            if (cy[v]==-1 || find(cy[v]))

            {

                cx[u] = v;

                cy[v] = u;

                return true;

            }

        }

    }

    return false;

}

int solve()

{

    memset(vis,0,sizeof(vis));

    memset(cx,-1,sizeof(cx));

    memset(cy,-1,sizeof(cy));

    int res = 0;

    for (int i=1; i<=nn; i++)

    {

        if (cx[i]==-1)

        {

            memset(vis,0,sizeof(vis));

            if (find(i))

                res++;

        }

    }

    return res;

}

int main()

{

    while (scanf("%d%d%d",&n,&m,&L)==3)

    {

        if (n==0 &&m==0 && L==0)

            break;

        memset(dis,inf,sizeof(dis));

        for (int i=1; i<=m; i++)

        {

            int u,v,d;

            scanf("%d%d%d",&u,&v,&d);

            u++;

            v++;

            if (d < dis[u][v])

            {

                dis[u][v] = d;

                dis[v][u] = d;

            }

        }



        for (int k=1; k<=n; k++)

            for (int i=1; i<=n; i++)

                for (int j=1; j<=n; j++)

                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);

        for (int i=1;i<=n;i++)

            dis[i][i] = 0;





        for (int i=1; i<=L; i++)

        {

            int s,t;

            scanf("%d%d",&s,&t);

            s++;

            q[i] = node(s,t);

        }

        sort(q+1,q+1+L);

        build();

        int res = solve();

        int ans = L - res;



        printf("%d\n",ans);



    }

    return 0;

}