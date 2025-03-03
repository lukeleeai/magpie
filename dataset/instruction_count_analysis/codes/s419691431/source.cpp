#include "stdc++.h"

using namespace std;

const int N=65;

const double eps=1e-8;

int n,k;

double x[N],y[N],c[N],r[N];

double dis(pair<double,double> a,pair<double,double> b) {

    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));

}

vector<pair<double,double> > cal(double x1,double y1,double r1,double x2,double y2,double r2) {//两圆交点

    x1-=x2,y1-=y2;

    double S=x1*x1+y1*y1,a=(S+r2*r2-r1*r1)/2,D=S*r2*r2-a*a;

    if(S==0)return {};

    if(D<0) return {};

    double A1=a*x1,B1=y1*sqrt(D);

    double A2=a*y1,B2=x1*sqrt(D);

    return {{(A1+B1)/S+x2,(A2-B2)/S+y2},{(A1-B1)/S+x2,(A2+B2)/S+y2}};

}

bool check(double t) {

    for(int i=0;i<n;i++) r[i]=t/c[i];

    vector<pair<double,double> > vec;

    for(int i=0;i<n;i++) {

    	vec.push_back({x[i],y[i]});

        for(int j=i+1;j<n;j++) {

            auto v=cal(x[i],y[i],r[i],x[j],y[j],r[j]);

            for(auto it:v) vec.push_back(it);

        }

    }

    for(auto it:vec) {

        int cnt=0;

        for(int i=0;i<n;i++) {

            if(r[i]+eps>=dis(it,{x[i],y[i]})) cnt++;

        }

        if(cnt>=k) return true;

    }

    return false;

}

int main() {

    scanf("%d%d",&n,&k);

    for(int i=0;i<n;i++) {

        scanf("%lf%lf%lf",&x[i],&y[i],&c[i]);

    }

    double L=0,R=1000010;

    for(int i=0;i<100;i++) {

        double mid=(L+R)/2;

        if(check(mid)) R=mid;

        else L=mid;

    }

    printf("%.6lf\n",R);

    return 0;

}