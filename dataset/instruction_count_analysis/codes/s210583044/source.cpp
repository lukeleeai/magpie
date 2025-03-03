#include<cstdio>

#include<cstring>

#include<algorithm>

#include<queue>

#include<cmath>

#include<iostream>

using namespace std;

const int inf=0x3f3f3f3f;

const int maxn=1e5+10;



struct edge{

    int u,v,w;

    edge(int _u=0,int _v=0,int _w=0):u(_u),v(_v),w(_w){

    }

    bool operator<(const edge & a)const{

        return w<a.w;

    }

}es[2*maxn];



struct point{

    int x,y,id;

    point(int _x=0,int _y=0,int _id=0):x(_x),y(_y),id(_id){}

} ps[maxn];



int n,cnt,f[maxn];



bool cmpx(point a,point b){

    return a.x<b.x;

}



bool cmpy(point a,point b){

    return a.y<b.y;

}



int findf(int a){

    return ((f[a]==-1)?a:f[a]=findf(f[a]));

}



int kruskal(){

    int i,ans=0,cc=0;

    memset(f,0xff,sizeof(f));

    sort(es,es+cnt);

    for(i=0;i<cnt;i++){

        int u=es[i].u,v=es[i].v,w=es[i].w;

        int fu=findf(u),fv=findf(v);

        if(fu!=fv){

            ans+=w,++cc;

            f[fu]=fv;

        }

        if(cc==n-1)break;

    }

    if(cc<n-1)return -1;

    return ans;

}

int main(){

    int i,j,k,c,un,vn;

    scanf("%d",&n);

    for(i=1;i<=n;i++){

        scanf("%d%d",&ps[i].x,&ps[i].y);

        ps[i].id=i;

    }

    sort(ps+1,ps+n+1,cmpx);

    for(i=1;i<=n-1;i++){

        es[cnt++]=edge(ps[i].id,ps[i+1].id,(ps[i+1].x-ps[i].x));

    }

    sort(ps+1,ps+n+1,cmpy);

    for(i=1;i<=n-1;i++){

        es[cnt++]=edge(ps[i].id,ps[i+1].id,(ps[i+1].y-ps[i].y));

    }

    printf("%d\n",kruskal());

    return 0;

}
