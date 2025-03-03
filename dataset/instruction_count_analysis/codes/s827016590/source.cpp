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

    int n=read(),m=read();

    printf("%lld\n",(n-1)*(m-1));

    return 0;

}