#include <stdio.h>

#include <string.h>

#include <algorithm>

#include <cmath>

typedef long long ll;

using namespace std;

#define rep(i,st,ed) for (int i=st;i<=ed;++i)



const int INF=0x3f3f3f3f;

const int N=2000005;



int a[N];



int read() {

    int x=0,v=1; char ch=getchar();

    for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):v,ch=getchar());

    for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());

    return x*v;

}



bool check(int l,int r) {

    int mx = 0, mn = INF;

    for (int i = l; i <= r; i++) {

        mx = max(mx, a[i]);

        mn = min(mn, a[i]);

    }

    if (mn < l || mx > r) return true;

    int r1 = 0, r2 = 0;

    for(int i=l;i<=r;i++){

        if(a[i] != i){

            if(a[i]<i){//那么他是从小的换过来的

                if(r1<a[i]) r1=a[i];

                else return true;

            }else{//那么他是从大的换过来的

                if(r2<a[i]) r2=a[i];

                else return true;

            }

        }

    }

    return false;

}



int main(void) {

    int n=read(),x;

    for(int i=1;i<=n;i++) a[i]=read();

    for(int i=1;i<=n;i++){

        if(a[i] != i){

            for(x=i;a[x+1]==x+1&&a[x+2]!=x+2;) x+= 2;

            x=min(x,n);// 得到交换的段，也就是这个是分段的，有些段是跨不过去的

            if(check(i, x)) return puts("No"), 0;

            i=x;

        }

    }

    return puts("Yes"),0;

}
