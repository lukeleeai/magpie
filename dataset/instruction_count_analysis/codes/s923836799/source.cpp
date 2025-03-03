#include"stdc++.h"

using namespace std;

typedef long long ll;

const ll inf = 1e9;

#define sz              300005

#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



int par[sz];

bool vis[sz];

vector < int > V[sz];



void bfs(int src){



    memset(vis,0,sizeof(vis));

    memset(par,0,sizeof(par));

    queue< int > q;

    q.push(1);

    vis[1]=0;



    while(!q.empty()){

        int u=q.front();

        q.pop();



        for(int i=0; i<V[u].size(); i++){

            int v=V[u][i];

            if(vis[v]==0){

                par[v]=u;

                vis[v]=1;

                q.push(v);

            }

        }

    }

}



int main(){

    Fast;

    int a,b,c, i,j, n,m,t, cs=1;



    cin>>n>>m;

    for(i=0; i<m; i++){

        cin>>a>>b;

        V[a].push_back(b);

        V[b].push_back(a);

    }

    bfs(1);



    bool flag=true;

    vector < int > pp;

    for(i=2; i<=n; i++){

        if(par[i]==0){

            flag=false;break;

        }

        pp.push_back(par[i]);

    }

    if(!flag){

        cout<<"No"<<endl;

    }

    else{

        cout<<"Yes"<<endl;

        for(i=0; i<n-1; i++){

            cout<<pp[i]<<endl;

        }

    }





    return 0;

}


