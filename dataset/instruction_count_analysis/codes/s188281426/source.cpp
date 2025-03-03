#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

int sum[400005],lazy[400005],n,m;;

struct obj

{

    int l,r;

}p[300005];

bool cmp(obj x,obj y)

{

    return x.r-x.l<y.r-y.l;

}

void push_down(int k,int l,int r)

{

    if(l==r)

    {

        sum[k]+=lazy[k];

    }

    else

    {

        lazy[k<<1]+=lazy[k];

        lazy[k<<1|1]+=lazy[k];

        sum[k]+=lazy[k]*(r-l+1);

    }

    lazy[k]=0;

}

void change(int k,int l,int r,int x,int y,int w)

{

    if(l>=x&&r<=y)

    {

        lazy[k]+=w;

    }

    else

    {

        push_down(k,l,r);

        int mid=(l+r)>>1;

        if(y>=l&&x<=mid)

        {                 

            change(k<<1,l,mid,x,y,w);

        }             

        if(y>=mid+1&&x<=r)

        {                

            change(k<<1|1,mid+1,r,x,y,w);

    	}

    }

}

int query(int k,int l,int r,int x)

{

    push_down(k,l,r);

    if(l==r)

    {

        return sum[k];

    }

    int mid=(l+r)>>1;

    if(x<=mid)

    {

        return query(k<<1,l,mid,x);

    }

    return query(k<<1|1,mid+1,r,x);

}

int main()

{

    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)

    {

        scanf("%d%d",&p[i].l,&p[i].r);

    }

    int i=0;

    sort(p,p+n,cmp);

    for(int d=1;d<=m;d++)

    {

        while(i<n&&p[i].r-p[i].l<d)

        {

            change(1,1,m,p[i].l,p[i].r,1);

            i++;

        }

        int ans=n-i;

        for(int k=d;k<=m;k+=d)

        {

            ans+=query(1,1,m,k);

        }

        printf("%d\n",ans);

    }

    return 0;

}