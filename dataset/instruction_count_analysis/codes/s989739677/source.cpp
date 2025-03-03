#include<cstdio>

#include<cmath>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

#define clr(a,b) memset(a,b,sizeof(a))

#define pb(a)    push_back(a)

#define il       inline

#define reg      register

typedef long long ll;

typedef double db;

const int maxn=10000;

const int minn=200000+5;

struct Point

{

    db x,y;

    Point(){}

    Point(db x,db y):x(x),y(y){}

};

struct Seg

{

    Point a,b;

    int c;

    Seg(Point a,Point b,int c):a(a),b(b),c(c){}

    friend bool operator<(Seg p,Seg q){

        if(p.a.y!=q.a.y) return p.a.y<q.a.y;

    	return p.c!=q.c?p.c<q.c:p.a.x<q.a.x;

    }

};

db  x[minn<<2];

int q,lenx,ans,tree[minn<<2];

vector<Seg> ve;

void init()

{

    clr(tree,0);

    ve.clear();

    lenx=0;

    ans=0;

    return ;

}

void  pushpu(int k,int c)

{

    while(k)

    {

        tree[k]+=c;

        k>>=1;

    }

}

void update(int l,int r,int nu,int c,int k)

{

    if(nu==l&&r==nu)

    {

        pushpu(k,c);

        return ;

    }

    int mind=(l+r)/2;

    if(nu<=mind){update(l,mind,nu,c,k<<1);}

    if(nu>mind) {update(mind+1,r,nu,c,k<<1|1);}

    return ;

}

void query(int l,int r,int L,int R,int k)

{

    if(L<=l&&r<=R)

    {

        ans+=tree[k];

        return ;

    }

    int mind=(l+r)/2;

    if(L<=mind){query(l,mind,L,R,k<<1);}

    if(R>mind) {query(mind+1,r,L,R,k<<1|1);}

    return ;

}

int slove()

{

    sort(ve.begin(),ve.end());

    sort(x,x+lenx);

    int res=0;

    for(reg int i=0;i<ve.size();i++)

    {

        if(ve[i].a.x==ve[i].b.x){

            int nu=lower_bound(x,x+lenx,ve[i].a.x)-x+1;

            int c=ve[i].c>2?-1:ve[i].c;

            update(1,lenx,nu,c,1);

        }

        else

        {

            ans=0;

            int l=lower_bound(x,x+lenx,ve[i].a.x)-x+1;

            int r=lower_bound(x,x+lenx,ve[i].b.x)-x+1;

            query(1,lenx,l,r,1);

            res+=ans;

        }

    }

return res;

}

int main()

{

//    freopen("data.txt","r",stdin);

    init();

    scanf("%d",&q);

    Point a,b;

    while(q--)

    {

        scanf("%lf%lf",&a.x,&a.y);

        scanf("%lf%lf",&b.x,&b.y);

        if(a.x>b.x||a.y>b.y){swap(a,b);}

        if(a.x!=b.x)

        {

            x[lenx++]=a.x;x[lenx++]=b.x;

            ve.pb(Seg(a,b,2));

        }

        else

        {

            x[lenx++]=a.x;

            ve.pb(Seg(a,a,1));

            ve.pb(Seg(b,b,3));

        }

    }

    printf("%d\n",slove());

    return 0;

}


