#include"stdc++.h"

using namespace std;

#define ll long long

#define Mid ((l+r)/2)

#define rep(i,a,b) for(int i=(a);i<=(b);++i)

#define drep(i,a,b) for(int i=(a);i>=(b);--i)

#define file(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout);

const int maxn=2e5+5,mod=1e9+7,inf=0x3f3f3f3f;

int n,m,Q,K,T;

int read(){

    int x=0,f=1;char c=getchar();

    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}

    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}

    return x*f;

}int a[maxn],b[maxn];

struct node{int l,r,len;}stk[maxn];

int l=1,r,fb[maxn],fa[maxn];

signed main(){

    //file(a);

    n=read();

    rep(i,1,n)a[i]=read(),fa[a[i]]++;

    drep(i,n,1)b[i]=read(),fb[b[i]]++;

    rep(i,1,n)if(fa[a[i]]+fb[a[i]]>n)puts("No"),exit(0);

    rep(i,1,n){

        if(a[i]!=b[i])continue;

        int j=i;

        while(a[j+1]==b[j+1]&&j+1<=n)++j;

        stk[++r]=(node){i,j,j-i+1};i=j;

    }

    while(l<=r){

        int now=0;

        drep(i,n,1){

            if(b[i]!=a[stk[l].l+now]&&b[stk[l].l+now]!=a[i])swap(b[i],b[stk[l].l+now]),++now;

            if(now>=stk[l].len)break;

        }++l;

    }puts("Yes");

    rep(i,1,n)printf("%d ",b[i]);puts("");

    return 0;

    // rep(i,l,r)cout<<stk[i].l<<" "<<stk[i].r<<endl;

    while(l+1<=r){

        node u=stk[l],v=stk[l+1];++l,++l;

        rep(i,0,min(u.len,v.len)-1)swap(b[i+u.l],b[i+v.l]);

        if(u.l+v.len<=u.r)stk[++r]=(node){u.l+v.len,u.r};

        if(v.l+u.len<=v.r)stk[++r]=(node){v.l+u.len,v.r};

    }

    if(l>r){

        puts("Yes");

        rep(i,1,n)printf("%d ",b[i]);puts("");

    }

    else{

        // rep(i,1,n)printf("%d ",b[i]);puts("");

        // cout<<stk[l].l<<" "<<stk[l].r<<endl;

        int now=0;

        drep(i,n,1){

            if(b[i]!=a[stk[l].l]&&b[stk[l].l]!=a[i])swap(b[i],b[stk[l].l+now]),++now;

            if(now>=stk[l].len)break;

        }puts("Yes");

        rep(i,1,n)printf("%d ",b[i]);puts("");

    }





    return 0;

}
