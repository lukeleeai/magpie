#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

const double EPS=1e-8;

const double PI=acos(-1);

const int N=105;

int n;double x[N],y[N],z[N];

bool vis[N];

struct Node {

    double x,y;int id;

    Node(double x=0,double y=0,int id=0):x(x),y(y),id(id){}

    bool operator < (const Node &b) const {

        if(x!=b.x) return x<b.x;

        return y<b.y;

    }

    Node operator - (const Node &b) {

        return Node(x-b.x,y-b.y);

    }

    double det(const Node &b) {

        return x*b.y-y*b.x;

    }

    double dot(const Node &b) {

        return x*b.x+y*b.y;

    }

    double dis() {

        return sqrt(x*x+y*y);

    }

}point[N],ans[N];

int solve(int num) {

    std::sort(point,point+num);

    int k=0;

    for(int i=0;i<num;i++) {

        while(k>1&&(ans[k-1]-ans[k-2]).det(point[i]-ans[k-1])<EPS) k--;

        ans[k++]=point[i];

    }

    for(int i=num-2,t=k;~i;i--) {

        while(k>t&&(ans[k-1]-ans[k-2]).det(point[i]-ans[k-1])<EPS) k--;

        ans[k++]=point[i];

    }

    return k;

}

double res[N];

int main() {

    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%lf%lf",&point[i].x,&point[i].y),point[i].id=i;

    int num=solve(n)-1;

    for(int i=0;i<n;i++) res[i]=0;

    if(num==2) res[ans[0].id]=res[ans[1].id]=0.5;

    else {

        double tmp;

        tmp=(ans[0]-ans[num-1]).dot(ans[0]-ans[1]);

        tmp=acos(tmp/(ans[0]-ans[num-1]).dis()/(ans[0]-ans[1]).dis());

        res[ans[0].id]=(PI-tmp)/PI/2;

        tmp=(ans[num-1]-ans[0]).dot(ans[num-1]-ans[num-2]);

        tmp=acos(tmp/(ans[num-1]-ans[num-2]).dis()/(ans[num-1]-ans[0]).dis());

        res[ans[num-1].id]=(PI-tmp)/PI/2;

        for(int i=1;i<num-1;i++) {

            tmp=(ans[i]-ans[i-1]).dot(ans[i]-ans[i+1]);

            tmp=acos(tmp/(ans[i]-ans[i-1]).dis()/(ans[i]-ans[i+1]).dis());

            res[ans[i].id]=(PI-tmp)/PI/2;

        }

    }

    for(int i=0;i<n;i++) printf("%.12f\n",res[i]);

    return 0;

}
