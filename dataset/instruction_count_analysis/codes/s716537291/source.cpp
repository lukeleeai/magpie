#include<cstdio>

#include<algorithm>

#include<cmath>

#define ll long long

#define N 100005

#define inf 0x3fffffff

#define rep(i, l, r) for(int i=l; i<=r; ++i)

using namespace std;

int n, k;

char s[N];

int main(){

    scanf("%d%d%s", &n, &k, s);

    int tmp=0;

    rep(i, 0, n-1){

        if(!i || s[i]!=s[i-1]) ++tmp;

    }

    tmp=max(1, tmp-2*k);

    printf("%d", n-tmp);

    return 0;

}