#include <cstdio>

//#include <iostream>

//#include <algorithm>

//#include <cstring>

//#include <queue> //priority_queue 优先队列

#include <map>

#include <set> //multiset  set<int,greater<int>>大到小

//#include <vector>// ::iterator it;

//#include <stack>

//#include <cmath> // auto &Name : STLName  Name.

//#include <utility>

//#include <sstream>

//#include <string>

#define mod 1000000007

#define mod9 998244353

typedef unsigned long long ull;

typedef long long ll;

typedef double db;

typedef long double ld;

const db eps=1e-10;

const int INF = 0x3f3f3f3f;

const ll inf=0x3f3f3f3f3f3f3f3f;

const int N=1e6+5;

using namespace std;





ll t,n,m,k,cnt=0;

ll a[65]={0};

ll sum=0;

ll ksm(ll a,ll b){

    ll c=mod;

    ll ans=1;

    a=a%c;

    while(b>0){

        if(b%2) ans=(ans*a)%c;

        b=b/2;

        a=(a*a)%c;

    }

    return ans;

}

int main(){

    scanf("%lld",&n);

    k=n;

    while(n--){

        scanf("%lld",&m);

        for(ll i=0;m;i++){

            ll x=m%2;

            m/=2;

            if(x) a[i]++;

        }

    }

    for(ll i=0;i<65;i++){

        sum=(sum+((a[i]*(k-a[i]))%mod)*ksm(2,i))%mod;

    }

    printf("%lld\n",sum);

    return 0;

}