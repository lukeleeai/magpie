#include<cstdio>

#include<cstring>

#include<algorithm>

#include<queue>

#include<vector>

using namespace std;

int n,m,i,j,d[10005],ans;

struct edge{

    int v,d,c;

    edge(int vv,int dd,int cc){

        v=vv,d=dd,c=cc;

    }

};

struct de{

    int u,d;

    de(int uu,int dd){

        u=uu,d=dd;

    }

	bool operator<(const de &a)const

	{

		return d < a.d;

	}

};



priority_queue<de> q;

vector <edge> e[20005];

int main()

{

    //freopen("1.in","r",stdin);

    //freopen("1.out","w",stdout);

    int u,v,d1,c;

    while(~scanf("%d %d",&n,&m)&&n)

    {

        ans=0;

       /* ;

        if(n==0||m==0)

            return 0;*/

        while(!q.empty())

            q.pop();

        for(i=1;i<=n;i++)

        {

            e[i].clear();

            d[i]=2147483647;

        }

        for(i=1;i<=m;i++)

        {

            scanf("%d %d %d %d",&u,&v,&d1,&c);

            e[u].push_back(edge(v,d1,c));

            e[v].push_back(edge(u,d1,c));

        }

        d[1]=0;

        q.push(de(1,0));

        while(!q.empty())

        {

            de k=q.top();

            q.pop();

            if(d[k.u]<k.d)continue;

            for(i=0;i<int(e[k.u].size());i++)

            {

                if(d[e[k.u][i].v]>=e[k.u][i].d+d[k.u])

                {

                    d[e[k.u][i].v]=e[k.u][i].d+d[k.u];

                    q.push(de(e[k.u][i].v,d[e[k.u][i].v]));

                }

            }

        }

        ans=0;

        int mi=2147483647;

        for(i=2;i<=n;i++)

        {

            for(j=0;j<int(e[i].size());j++)

            {

                if(d[e[i][j].v]+e[i][j].d==d[i]&&mi>e[i][j].c)

                    mi=e[i][j].c;

            }

            if(mi!=2147483647)

            ans=ans+mi;

            mi=2147483647;

        }

        printf("%d\n",ans);

    }

}