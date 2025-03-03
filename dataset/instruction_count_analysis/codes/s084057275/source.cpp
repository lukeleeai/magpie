#include"stdc++.h"

#define ll long long int

#define ff first

#define ss second

#define eps 1e-9



using namespace std;

vector< vector<pair<ll,ll> > > g;

vector< ll> col;

vector< bool > vis;



void bfs()

{

    vis[1]=1;

    col[1]=0;

    queue<ll>  q;

    q.push(1);



    while(!q.empty())

    {

        ll top = q.front();

        q.pop();



        for(int i=0;i<g[top].size();i++)

        {

            if(vis[g[top][i].ff]==0)

            {

                vis[g[top][i].ff] =1;



                if(g[top][i].ss %2 )

                {

                    col[ g[top][i].ff ] = 1 - col[top];



                }

                else

                {

                    col[ g[top][i].ff ] = col[top];

                }



                q.push(g[top][i].ff);

            }

        }



    }

}





int main()

{



    ll t,n,m,f,a,b,c,l,r,q,k,x,y,w,z,ans,mn,mx,sum=0;



    cin>>n;



    g.resize(n+1);

    col.resize(n+1);

    vis.resize(n+1);



    for(int i=0;i<n-1;i++)

    {

        cin>>x>>y>>w;



        g[x].push_back({y,w});

        g[y].push_back({x,w});

    }



    bfs();



    for(int i=1;i<=n;i++)

    {

        cout<<col[i]<<endl;

    }









}
