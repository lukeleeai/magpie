#include<stdio.h>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<bitset>

#include<vector>

#include<math.h>

#define ls(x) (x<<1)

#define rs(x) ((x<<1)|1)

using namespace std;

int n,m;

struct nod

{

    int l,r,len;

    bool operator<(const nod &b)const

    {

        return len<b.len;

    }

}a[300005];

int lazy[1200005];

void pushdown(int now)

{

    lazy[ls(now)]+=lazy[now];

    lazy[rs(now)]+=lazy[now];

    lazy[now]=0;

}

void jia(int now,int l,int r,int st,int ed)

{

    if(l==r)

    {

        lazy[now]++;

        return;

    }

    if(st<=l&&ed>=r)

    {

        lazy[now]++;

        return;

    }

    if(lazy[now])pushdown(now);

    int mid=(l+r)>>1;

    if(st<=mid)jia(ls(now),l,mid,st,ed);

    if(ed>=mid+1)jia(rs(now),mid+1,r,st,ed);

}

int query(int now,int l,int r,int pos)

{

    if(l==r)return lazy[now];

    if(lazy[now])pushdown(now);

    int mid=(l+r)>>1;

    if(pos<=mid)return query(ls(now),l,mid,pos);

    else return query(rs(now),mid+1,r,pos);

}

int main()

{

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)

    {

        scanf("%d%d",&a[i].l,&a[i].r);

        a[i].len=a[i].r-a[i].l+1;

    }

    sort(a+1,a+1+n);

    int flag=1,ans;

    printf("%d\n",n);

    for(int i=2;i<=m;i++)

    {

        while(flag<=n&&a[flag].len<=i)

        {

            jia(1,1,m,a[flag].l,a[flag].r);

            //printf("%d %d\n",a[flag].l,a[flag].r);

            flag++;

        }

        ans=0;

        //printf("%d %d\n",i,query(1,1,m,9));

        for(int j=i;j<=m;j+=i)

        {

            ans+=query(1,1,m,j);

            //printf("%d ",ans);

        }

        printf("%d\n",ans+(n-flag+1));

    }

}