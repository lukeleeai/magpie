#include<cstdio>

#include<algorithm>

using namespace std;

#define ll long long

const int maxn=1e5+5;

const ll INF=0x3f3f3f3f3f3f3f3f;

int a[maxn];

struct node

{

    int l,r;

    ll diff,lz;

}tree[4*maxn];

void build(int l,int r,int cur)

{

    tree[cur].l=l;

    tree[cur].r=r;

    if(l==r)

        return;

    int mid=(l+r)>>1;

    build(l,mid,cur<<1);

    build(mid+1,r,cur<<1|1);

    return;

}

void push_up(int cur)

{

    tree[cur].diff=tree[cur<<1].diff+tree[cur<<1|1].diff;

    return;

}

void push_down(int cur)

{

    if(tree[cur].lz!=0)

    {

        tree[cur<<1].diff+=(tree[cur<<1].r-tree[cur<<1].l+1)*tree[cur].lz;

        tree[cur<<1].lz+=tree[cur].lz;

        tree[cur<<1|1].diff+=(tree[cur<<1|1].r-tree[cur<<1|1].l+1)*tree[cur].lz;

        tree[cur<<1|1].lz+=tree[cur].lz;

        tree[cur].lz=0;

    }

    return;

}

void add(int l,int r,ll val,int cur)

{

    if(l>r) return;

    if(tree[cur].l>=l&&tree[cur].r<=r)

    {

        tree[cur].diff+=(tree[cur].r-tree[cur].l+1)*val;

        tree[cur].lz+=val;

        return;

    }

    if(tree[cur].l>r||tree[cur].r<l)

        return;

    push_down(cur);

    add(l,r,val,cur<<1);

    add(l,r,val,cur<<1|1);

    push_up(cur);

    return;

}

ll diff0[maxn];

void together(int cur)

{

    if(tree[cur].l==tree[cur].r)

    {

        diff0[tree[cur].l]=tree[cur].diff;

        return;

    }

    push_down(cur);

    together(cur<<1);

    together(cur<<1|1);

    push_up(cur);

    return;

}

ll minn[maxn];

int main()

{

    int n,m;

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)

        scanf("%d",&a[i]);

    build(0,m-1,1);

    ll base=0;

    for(int i=1;i<n;i++)

    {

        if(a[i]<a[i+1])

        {

            base+=(ll)(a[i+1]-a[i]);

            add(a[i]+1,a[i+1]-1,-1,1);

            add(a[i+1],a[i+1],a[i+1]-a[i]-1,1);

        }

        else

        {

            base+=(ll)(m-a[i]+a[i+1]);

            add(0,0,-(m-a[i]),1);

            add(1,a[i+1]-1,-1,1);

            add(a[i+1],a[i+1],m-a[i]+a[i+1]-1,1);

            add(a[i]+1,m-1,-1,1);

        }

    }

    together(1);

    minn[0]=base;

    for(int i=1;i<=m;i++)

        minn[i]=minn[i-1]+diff0[i-1];

    ll ans=INF;

    for(int i=1;i<=m;i++)

        ans=min(ans,minn[i]);

    printf("%lld\n",ans);

    return 0;

}

/*

 4 6

 1 5 1 4

 8 9 7 5 6 9

 

 9 9 8 7 6 5 4 3 2

 */
