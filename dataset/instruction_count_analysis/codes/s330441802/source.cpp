#include       <set>

#include       <map>

#include     <queue>

#include     <cmath>

#include    <cstdio>

#include    <cctype>

#include    <vector>

#include   <cstring>

#include <algorithm>

using namespace std;



typedef long long ll;

const ll mod = 1e9+7;

const double eps = 1e-7;

const int maxn = 1e5+5;



ll fast_pow(ll a,ll b,ll mod){

    ll ans = 1;

    while(b){

        if(b&1)

            ans = ans*a%mod;

        a = a*a%mod;

        b>>=1;

    }

    return ans;

}

int a[127];

int c[127];

int main(){

    int n;

    char str[55];

    scanf("%d",&n);

    memset(c,0x3f,sizeof(c));

    for(int i=0;i<n;i++){

        scanf("%s",str);

        memset(a,0,sizeof(a));

        for(int j=0;str[j];j++)

            a[str[j]]++;

        for(int j='a';j<='z';j++)

            c[j] = min(c[j],a[j]);

    }

    for(int j='a';j<='z';j++)

        while(c[j])putchar(j),c[j]--;

}



/*



1592794101

989097785





232162543



*/
