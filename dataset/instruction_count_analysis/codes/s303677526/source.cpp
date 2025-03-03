#include<stdio.h>

#include<map>

using namespace std;

typedef long long ll;

map<ll,int>p;

map<ll,int>::iterator it;

int fa[100010],siz[100010],a[100010],b[100010],h[100010],nex[200010],to[200010],M,n;

void add(int a,int b){

    M++;

    to[M]=b;

    nex[M]=h[a];

    h[a]=M;

}

ll wd[100010],d[100010];

void dfs(int x,int dis){

    siz[x]=1;

    d[1]+=dis;

    for(int i=h[x];i;i=nex[i]){

        if(to[i]!=fa[x]){

            fa[to[i]]=x;

            dfs(to[i],dis+1);

            siz[x]+=siz[to[i]];

        }

    }

}

void dfs(int x){

    for(int i=h[x];i;i=nex[i]){

        if(to[i]!=fa[x]){

            d[to[i]]=d[x]+n-siz[to[i]]*2;

            dfs(to[i]);

        }

    }

}

int get(int x){return fa[x]==x?x:(fa[x]=get(fa[x]));}

int main(){

    int i;

    scanf("%d",&n);

    for(i=1;i<=n;i++){

        scanf("%lld",wd+i);

        p[wd[i]]=i;

    }

    for(i=1;i<=n;i++){

        fa[i]=i;

        siz[i]=1;

    }

    it=p.end();

    for(it--;it!=p.begin();it--){

        if(n-siz[it->second]*2==0||!p.count(it->first-(n-siz[it->second]*2))){

            puts("-1");

            return 0;

        }

        M++;

        a[M]=it->second;

        b[M]=p[it->first-(n-siz[it->second]*2)];

        siz[fa[a[M]]=get(b[M])]+=siz[a[M]];

    }

    M=0;

    for(i=1;i<n;i++){

        add(a[i],b[i]);

        add(b[i],a[i]);

    }

    fa[1]=0;

    dfs(1,0);

    dfs(1);

    for(i=1;i<=n;i++){

        if(wd[i]!=d[i]){

            puts("-1");

            return 0;

        }

    }

    for(i=1;i<n;i++)printf("%d %d\n",a[i],b[i]);

}