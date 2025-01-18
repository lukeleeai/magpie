#include "stdc++.h"



using namespace std;



typedef long long ll;

const double eps=1e-6,pi=acos(-1);

const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;

int n,m,a[N],b[N],c[N];

int mem[N];



int solve(int i=0){

    if(i>=n) return 1e9;

    if(i==n-1) return 0;

    int &ret=mem[i];

    if(~ret) return ret;

    ret=1e9;

    for(int j=1;j<=m;++j)

        ret=min(ret,solve(i+j)+abs(a[i]-a[i+j]));

    return ret;

}



int main(){

    //freopen("myfile.txt","w",stdout);

    scanf("%d%d",&n,&m);

    for(int i=0;i<n;++i)

        scanf("%d",a+i);

    memset(mem,-1,sizeof mem);

    printf("%d",solve());

    return 0;

}
