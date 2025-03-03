#include<cstdio>

#include<cstring>

#include<algorithm>

#include<vector>

#include<queue>

#define INF 0x3fffffff

using namespace std;

  

int n,m;

int d[10005];

struct node

{

    int e,len,cost;

    //node(){}

    node(int a,int b,int c)

    {

        e=a,len=b,cost=c;

    }

    bool operator < (const node &a) const

    {

        return len>a.len;

    }

};

vector <node> E[10005];

priority_queue <pair<int,int> > q;

  

int main()

{

    //freopen("1.in","r",stdin);

    //freopen("1.out","w",stdout);

    while(~scanf("%d%d",&n,&m)&&n)

    {

        for(int i=1;i<=n;i++)

            d[i]=INF,E[i].clear();

        for(int i=1;i<=m;i++)

        {

            int s,e,cost,len;

            scanf("%d%d%d%d",&s,&e,&len,&cost);

            E[s].push_back(node(e,len,cost));

            E[e].push_back(node(s,len,cost));

        }

        q.push(make_pair(1,0));

        d[1]=0;

        while(!q.empty())

        {

            pair <int,int> t=q.top();

            q.pop();

            int v=t.first;

            //printf("*%d-%d\n",t.first,t.second);

            if(d[v]<t.second)

                continue;

            for(int i=0;i<E[v].size();i++)

            {

                node e=E[v][i];

                if(d[e.e]>d[v]+e.len)

                {

                    d[e.e]=d[v]+e.len;

                    q.push(make_pair(e.e,d[e.e]));

                }

            }

        }

        int ans=0;

        for(int i=2;i<=n;i++)

        {

            int mine=INF;

            for(int j=0;j<E[i].size();j++)

                if(E[i][j].len+d[E[i][j].e]==d[i]&&mine>E[i][j].cost)

                    mine=E[i][j].cost;

            if(mine!=INF)

            ans+=mine;

        }

        printf("%d\n",ans);

    }

} 