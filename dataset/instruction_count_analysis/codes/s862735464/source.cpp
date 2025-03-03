#include"stdc++.h"

using namespace std;

#define maxn 100010

#define inf 0x3f3f3f3f

int v[maxn];

int pre[maxn];

vector<int> g[maxn];

int ty[maxn];

bool used[maxn];

int a,b;

void dfs(int u){

    a++;b+=ty[u];

    used[u]=true;

    for(int i=0;i<g[u].size();i++){

        int to=g[u][i];

        if(used[to]) continue;

        dfs(to);

    }

}

int main(){

    int n,T;

    scanf("%d%d",&n,&T);

    scanf("%d",&v[0]);

    int minx=v[0],dis=0,pos=0;

    for(int i=1;i<n;i++){

        scanf("%d",&v[i]);

        if(v[i]<=minx){

            pre[i]=i;

            minx=v[i];

            pos=i;

        }

        else{

            pre[i]=pos;

            dis=max(dis,v[i]-v[pos]);

        }

    }

    memset(used,1,sizeof(used));

    for(int i=1;i<n;i++){

        if(v[i]-v[pre[i]]==dis){

            g[pre[i]].push_back(i);

            g[i].push_back(pre[i]);

            used[i]=used[pre[i]]=false;

            ty[pre[i]]=1;

        }

    }

    int res=0;

    for(int i=0;i<n;i++){

        if(!used[i]){

            a=b=0;

            dfs(i);

            res+=min(b,a-b);

        }

    }

    printf("%d\n",res);

    return 0;

}
