#include <iostream>

#include <sstream>

#include <vector>

#include <cmath>

#include <cstdio>

#include <queue>

#include <set>

#include <map>

#include <cstdlib>

#include <cstring>

#include <algorithm>

#define maxn 100005

using namespace std;

typedef long long ff;

int fo[2*maxn+5];

long long kx[2*maxn+5],ty[2*maxn+5];



int fin(int x)

{

       if(fo[x]==x)

       return x;

       else

       return fo[x]=fin(fo[x]);



}

int main()

{

    int n;

    scanf("%d",&n);

    for(int i=1;i<2*maxn;i++)

    {fo[i]=i;

    ty[i]=0;

    kx[i]=0;

    }

    long long ans=0;

    int x,y;

    for(int i=0;i<n;i++)

    {

       scanf("%d %d",&x,&y);

       fo[fin(x)]=fin(y+maxn);

     //  printf("%d\n",fo[fin(x)]);

      // fo[find(y+maxn)]=y;

    }

     for(int i=1;i<maxn;i++)

     kx[fin(i)]++;

     for(int i=maxn;i<maxn*2;i++)

     ty[fin(i)]++;



     for(int i=1;i<=2*maxn;i++)

     {

     ans+=kx[i]*ty[i];

    // if(kx[i]*ty[i]!=0)

     //printf("%d %d\n",i,kx[i]*ty[i]);

     }

     printf("%lld",ans-n);



}
