#include<cstdio>

#include<cmath>

#include<algorithm>

#include<cstring>

#include<queue>

#include<iostream>

#include<map>

#define ll long long

#define rint register int

#define in inline

using namespace std;

int n,a[100010],b[100010],tot,cnt[100010],fa[100010],ans; 

map<int,int> f;//离散化 

in ll read()

{

    ll x=0,f=1; char ch=getchar();

    while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }

    while(ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }

    return x*f;

}

in int find(int x){ return x==fa[x]?x:fa[x]=find(fa[x]); }

in void merge(int x,int y)

{

    int fx=find(x),fy=find(y);

    if(fx!=fy) fa[fx]=fy;

}

int main()

{

    n=read();

    for(rint i=1;i<=n;i++) a[i]=read(),a[n+1]^=a[i];

    for(rint i=1;i<=n;i++) b[i]=read(),b[n+1]^=b[i];

    n++;

    for(rint i=1;i<=n;i++)

        if(a[i]!=b[i]||i==n) //n其实是n+1 需要特判 

        {

            if(!f[a[i]]) f[a[i]]=++tot;

            cnt[f[a[i]]]++;

        }

    for(rint i=1;i<=n;i++)

        if(a[i]!=b[i]||i==n) 

            cnt[f[b[i]]]--;

    for(rint i=0;i<=tot;i++) if(cnt[i]) { printf("-1"); return 0; }//从0开始枚举是为了避免b中出现a中没有的数

    for(rint i=1;i<=tot;i++) fa[i]=i;//并查集 

    for(rint i=1;i<=n;i++) a[i]=f[a[i]],b[i]=f[b[i]];

    for(rint i=1;i<=n;i++)

        if(a[i]!=b[i]) 

        {

            if(i<n) ans++;//最后一个点要单独处理 因为不需要连到b[n+1] 连一条边操作就多一次 

            merge(a[i],b[i]);

        }

    for(rint i=1;i<=tot;i++) if(find(i)==i) ans++;//有多少个环 就要在环之间连多少边-1

    if(ans) printf("%d",ans-1);

    return 0;

}