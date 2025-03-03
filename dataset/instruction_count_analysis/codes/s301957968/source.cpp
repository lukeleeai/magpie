#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <iostream>

#include <algorithm>

#include <vector>

#include <set>

#include <map>

#define rep(i,l,r) for(int i=(l);i<=(r);++i)

#define per(i,r,l) for(int i=(r);i>=(l);--i)

#define fo(i,l,r,d) for(int i=(l);i<=(r);i+=(d))

using namespace std;

const int maxn=3e5+10;

int a[maxn],n;

int main(){

    scanf("%d",&n);

    rep(i,1,n){

        scanf("%d",&a[i]);

        if((i^a[i])&1) return puts("No"),0;

    }

    for(int i=1;i<=n;++i){

        if(a[i]==i) continue;

        int p;

        for(p=i;p<=n-2;p+=2)

            if(a[p+2]==p+2||a[p+1]!=p+1) break;

        int mx=0,mn=n+1;

        rep(j,i,p) mx=max(mx,a[j]),mn=min(mn,a[j]);

        if(mx!=p||mn!=i) return puts("No"),0;

        int f1=0,f2=0;

        fo(j,i,p,2)

            if(a[j]>f1) f1=a[j];

            else if(a[j]>f2) f2=a[j];

            else return puts("No"),0;

        i=p;

    }

    puts("Yes");

    return 0;

}

//DSYTXDY