#include<cstdio>

#include<cstring>

#include<algorithm>

template<class _Tp>_Tp max(_Tp a,_Tp b){if(a>b) return a;return b;}

template<class _Tp>_Tp min(_Tp a,_Tp b){if(a<b) return a;return b;}

template<class _Tp>void ckmax(_Tp &a,_Tp b){if(a<b) a=b;}

template<class _Tp>void ckmin(_Tp &a,_Tp b){if(a>b) a=b;}

template<class _Tp>void sswap(_Tp &a,_Tp &b){_Tp c=a;a=b;b=c;}

int read(){

	char ch=getchar();bool f=1;int x=0;

	while((ch<'0' || ch>'9') && ch!='-') ch=getchar();

	if(ch=='-') f=0,ch=getchar();

	while(ch>='0' && ch<='9'){x=x*10+(ch&15);ch=getchar();}

	return f?x:-x;

}

#define N 300010

class Point{

    public:int x,y;

    bool friend operator <(Point a,Point b){return a.x<b.x;}

}p[N];

class tree{

	public:int l,r,w,tag;

}t[N*4];

#define ls (x<<1)

#define rs ((x<<1)|1)

void pushu(int x){

    if(t[x].l==t[x].r)return;

    t[x].w=max(t[ls].w,t[rs].w);

}

void pushd(int x){

    int tag=t[x].tag;

    t[ls].tag+=tag;t[ls].w+=tag;

    t[rs].tag+=tag;t[rs].w+=tag;

    t[x].tag=0;

}

void build(int x,int l,int r){

    t[x].l=l;t[x].r=r;

	t[x].tag=0;t[x].w=0;

    if(l==r)return;

    int mid=(l+r)/2;

    build(ls,l,mid);

    build(rs,mid+1,r);

}

void update(int x,int l,int r,int val){

    if(l<=t[x].l&&t[x].r<=r){

        t[x].tag+=val;

        t[x].w+=val;

        return;

    }

    if(t[x].tag&&t[x].l!=t[x].r)pushd(x);

    if(l<=t[ls].r)update(ls,l,r,val);

    if(r>=t[rs].l)update(rs,l,r,val);

    pushu(x);

}

int stk[2][N],top0,top1,ans,w,h,n;

void solve(){

    build(1,1,n);

    std::sort(p+2,p+n+1);

    top0=top1=0;

    stk[0][0]=stk[1][0]=1;

    update(1,1,n,h*2);

    for(int i=2;i<=n;++i){

        update(1,1,i-1,(p[i].x-p[i-1].x)*2);

        ckmax(ans,t[1].w);

        if(p[i].y*2>=h){

            update(1,stk[0][top0],i-1,(p[i].y-h)*2);

            while(top0&&p[stk[0][top0]].y>=p[i].y){

                update(1,stk[0][top0-1],stk[0][top0]-1,(p[i].y-p[stk[0][top0]].y)*2);

                top0--;

            }++top0;

            stk[0][top0]=i;

        }else{

            update(1,stk[1][top1],i-1,-p[i].y*2);

            while(top1&&p[stk[1][top1]].y<=p[i].y){

                update(1,stk[1][top1-1],stk[1][top1]-1,(p[stk[1][top1]].y-p[i].y)*2);

                top1--;

            }++top1;

            stk[1][top1]=i;

        }

    }

}

int main(){

	w=read();h=read();n=read()+2;

    for(int i=2;i<n;++i)

    	p[i].x=read(),p[i].y=read();

    p[n].x=w;p[n].y=h;

    solve();

    sswap(w,h);

    for(int i=2;i<=n;++i)

        sswap(p[i].x,p[i].y);

    solve();

    printf("%d\n",ans);

}