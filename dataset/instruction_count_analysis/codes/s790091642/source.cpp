#include"stdc++.h"

#define int long long

using namespace std;

inline int read(){

    int sum=0;

    char c=getchar();

    while(!isdigit(c)) c=getchar();

    while(isdigit(c)){

        sum=sum*10+(c^48);

        c=getchar();

    }

    return sum;

}

int const maxn=200005;

int const maxm=400005;

int n,q,cnt,ans,H[maxn],f[maxn],father[maxn];

struct Edge{

    int from,to,length;

}E[maxm];

inline void add(int a,int b,int c){

    E[++cnt]=(Edge){a,b,c};

    H[a]=cnt;

}

int find(int x){

    if(father[x]!=x) father[x]=find(father[x]);

    return father[x];

}

inline bool cmp(Edge x,Edge y){

    return x.length<y.length;

}

inline void kruskal(){

    sort(E+1,E+cnt+1,cmp);

    for(int i=1;i<=n;i++)

      father[i]=i;

    for(int i=1;i<=cnt;i++){

        int r1=find(E[i].from),r2=find(E[i].to);

        if(r1!=r2) father[r1]=r2,ans+=E[i].length;

    }

}

signed main(){

    n=read(),q=read();

    for(int i=1;i<=n;i++)

      f[i]=1e16;

    for(int i=1;i<=q;i++){

        int x=read()+1,y=read()+1,z=read();

        add(x,y,z);

        f[x]=min(f[x],z+1),f[y]=min(f[y],z+2);

    }

    //这个做法要记住的，它很巧妙地通过了断环为链，并且扫两遍，求出了环的前缀

    for(int i=1;i<=2*n-1;i++){

        int pre=(i%n==1)?n:((i-1)%n);

        f[(i-1)%n+1]=min(f[(i-1)%n+1],f[pre]+2);

    }

    for(int i=1;i<=n;i++)

      add(i,i%n+1,f[i]);

    kruskal();

    printf("%lld\n",ans);

    return 0;

}