#include <cstdio>

#include <iostream>

#include <cstring>

#include <algorithm> 

#include <vector>

#include <map>

#define N 100010

using namespace std;

vector<int>Q[N];

map<int,int>d;

bool vis[N];

int n,a[N],b[N],x[N],y[N],cnt,ans;

void dfs(int x){

    vis[x]=1;

    for (int i=0;i<Q[x].size();i++) if (!vis[Q[x][i]]) dfs(Q[x][i]);

}

int main(){

    scanf("%d",&n);



    for(int i=1;i<=n;i++){

        scanf("%d",&a[i]),a[n+1]^=a[i];

        if(!d[a[i]]) d[a[i]]=++cnt;

    }



    if(!d[a[n+1]]) d[a[n+1]]=++cnt;



    for(int i=1;i<=n;i++){

        scanf("%d",&b[i]),b[n+1]^=b[i];

        if(!d[b[i]]) d[b[i]]=++cnt;

    }



    if(!d[b[n+1]]) d[b[n+1]]=++cnt;



    memcpy(x,a,sizeof x),memcpy(y,b,sizeof y);



    sort(x+1,x+n+2),sort(y+1,y+n+2);



    for(int i=1;i<=n;i++) if(x[i]!=y[i]) {printf("-1");return 0;}



    for(int i=1;i<=n+1;i++) a[i]=d[a[i]],b[i]=d[b[i]];



    for(int i=1;i<=n;i++) if(a[i]!=b[i]) ans++,Q[a[i]].push_back(b[i]);



    if(a[n+1]!=b[n+1]) Q[a[n+1]].push_back(b[n+1]);



    for(int i=1;i<cnt;i++) if(Q[i].size()&&!vis[i]) dfs(i),ans++;



    if(!vis[cnt]) ans++;



    printf("%d",ans-1);



	return 0;

}
