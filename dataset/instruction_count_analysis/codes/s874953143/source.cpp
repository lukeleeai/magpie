#include<cstdio>

#define N 100005

#define P pair<int,int>

#define int long long

inline int read(){

    int x=0;char ch=getchar();

    for(;ch<48||ch>57;ch=getchar());

    for(;ch>47&&ch<58;ch=getchar())

    x=(x<<1)+(x<<3)+(ch^48);return x;

}

using namespace std;

signed main()

{

    int n=read();

    if(n>=195)puts("5");else

    if(n>=189)puts("4");else

    if(n>=165)puts("3");else

    if(n>=135)puts("2");else

    if(n>=105)puts("1");else

    puts("0");

    return 0;

}