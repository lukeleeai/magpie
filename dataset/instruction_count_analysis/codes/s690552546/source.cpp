#include"stdc++.h"

#define For(i,a,b) for(int i=(a);i<=(b);i++)

#define Rep(i,a,b) for(int i=(a);i>=(b);i--)

const int N=2e5+7; 

typedef long long LL;

using namespace std;

int n,m,ans;



template<typename T> void read(T &x) {

    T f=1; x=0; char ch=getchar();

    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();

    if(ch=='-') f=-1,ch=getchar();

    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0'; x*=f;

}



struct node {

    int l,r;

    friend bool operator <(const node&A,const node&B) {

        return A.r>B.r||(A.r==B.r&&A.l<B.l);

    }

}p[N];



#define lc x<<1

#define rc (x<<1|1)

#define mid ((l+r)>>1)

int sg[N<<2],lz[N<<2];

void build(int x,int l,int r) {

    if(l==r) { sg[x]=-l; return; }

    build(lc,l,mid); build(rc,mid+1,r);

    sg[x]=max(sg[lc],sg[rc]); 

}



void down(int x,int l_len,int r_len) {

    if(l_len) sg[lc]+=lz[x],lz[lc]+=lz[x];

    if(r_len) sg[rc]+=lz[x],lz[rc]+=lz[x];

    lz[x]=0;

}



int qry(int x,int l,int r,int ql,int qr) {

    if(ql>qr) return 0;

    if(l>=ql&&r<=qr) return sg[x];

    down(x,mid-l+1,r-mid);

    if(qr<=mid) return qry(lc,l,mid,ql,qr);

    if(ql>mid) return qry(rc,mid+1,r,ql,qr);

    return max(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr)); 

}



void update(int x,int l,int r,int ql,int qr,int v) {

    if(l>=ql&&r<=qr) {

        sg[x]+=v; lz[x]+=v; return;

    } 

    down(x,mid-l+1,r-mid);

    if(ql<=mid) update(lc,l,mid,ql,qr,v);

    if(qr>mid) update(rc,mid+1,r,ql,qr,v);

    sg[x]=max(sg[lc],sg[rc]); 

}



int main() {

    read(n); read(m); int pp=0;

    For(i,1,n) {

        read(p[i].l); read(p[i].r);

        if(p[i].l==0&&p[i].r>m) pp++,i--,n--;

    }

    sort(p+1,p+n+1);

    build(1,1,m+1); 

    For(i,1,n) {

        update(1,1,m+1,p[i].l+1,m+1,1);

        ans=max(ans,sg[1]+1-(m-p[i].r+1));

    }

    ans=max(n-m,ans)+pp;

    printf("%d\n",ans);

    return 0;

}