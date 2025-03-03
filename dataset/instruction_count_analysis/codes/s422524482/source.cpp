#include"stdc++.h"

using namespace std;

int n,m,cnt,ans,HASH[200001],tr[200001];

struct point{int x,y;}a[200001];

struct seg{int k,x,y,r;}s[2000001];

inline bool cmp3(seg a,seg b){

    if(a.y==b.y)return a.k>b.k;

    return a.y<b.y;

}

int find(int x)

{

    int l=0,r=m+1;

    while(l+1<r)

    {

        int mid=(l+r)>>1;

        if(HASH[mid]>=x)r=mid;

        else l=mid;

    }

    return r;

}

void insert(int k,int l,int r,int t)//0横线,1竖线

{

    if(!k){s[++cnt].x=find(l);s[cnt].r=find(r);s[cnt].y=t;s[cnt].k=0;}

    else{

        s[++cnt].x=find(t);s[cnt].y=l;s[cnt].k=1;

        s[++cnt].x=find(t);s[cnt].y=r;s[cnt].k=-1;

    }

}

void update(int x,int y)

{

    while(x<2e5)

    {

        tr[x]+=y;

        x+=x&(-x);

    }

}

int ask(int x)

{

    int s=0;

    while(x){

        s+=tr[x];

        x-=x&(-x);

    }

    return s;

}

int main()

{

    scanf("%d",&n);

    for(int i=1;i<=2*n;i++){

        scanf("%d%d",&a[i].x,&a[i].y);

        HASH[i]=a[i].x;

    }

    sort(HASH+1,HASH+2*n+1);

    m=unique(HASH+1,HASH+2*n+1)-(HASH+1);

    for(int i=1;i<2*n;i+=2){

        if(a[i].x==a[i+1].x){

            if(a[i].y>a[i+1].y)swap(a[i],a[i+1]);

            insert(1,a[i].y,a[i+1].y,a[i].x);

        }else{

            if(a[i].x>a[i+1].x)swap(a[i],a[i+1]);

            insert(0,a[i].x,a[i+1].x,a[i].y);

        }

    }

    sort(s+1,s+cnt+1,cmp3);

    for(int i=1;i<=cnt;i++){

//        if(!s[i].k)cout<<s[i].x<<" "<<s[i].r<<endl;

//        else cout<<s[i].x<<" "<<s[i].y<<" "<<s[i].k<<endl;

        if(!s[i].k)ans+=ask(s[i].r)-ask(s[i].x-1);

        else update(s[i].x,s[i].k);

    }

    printf("%d\n",ans);

    return 0;

}


