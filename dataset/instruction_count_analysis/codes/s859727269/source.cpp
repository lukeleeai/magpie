#include<cstdio>

#include<cstring>

#include<algorithm>

#include<iostream>

#include<string>

#include<vector>

#include<stack>

#include<bitset>

#include<cstdlib>

#include<cmath>

#include<set>

#include<list>

#include<deque>

#include<map>

#include<queue>

#define rep(i,n) for(int i=0;i<n;i++)

#define rep1(i,n) for(int i=1;i<=n;i++)

#define fr(i,x,n) for(int i=x;i<=n;i++)

#define rf(i,n,x) for(int i=n;i>=x;i--)

#define mst(x,i) memset(x,i,sizeof(x))

#define IOS ios::sync_with_stdio(false),cin.tie(0)

#define PB push_back

#define X first

#define Y second

using namespace std;

typedef long long LL;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int,int> pii;

typedef pair<LL,LL> pll;

const int maxn=1E5+5;

const int maxm=1E5+5;

const int inf=0x3f3f3f3f;

const LL INF=0x3f3f3f3f3f3f3f3f;

const LL mod=1E9+7;

const double eps=1E-6;

const double PI=acos(-1.0);

template<class T>

bool scan(T &ret){

    char c;int sgn;

    if(c=getchar(),c==EOF) return 0;

    while(c!='-'&&(c<'0'||c>'9')) c=getchar();

    sgn=(c=='-')?-1:1;

    ret=(c=='-')?0:(c-'0');

    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');

    ret*=sgn;

    return 1;

}

template<class T>

T gcd(T a,T b){

    return b==0?a:gcd(b,a%b);

}

template<class T>

T qpow(T a,T b,T mod){

    T ret=1;

    a%=mod;

    while(b){

        if(b&1) ret=(a*ret)%mod;

        a=(a*a)%mod;

        b>>=1;

    }

    return ret%mod;

}

int a[maxn];

void solve(){

    int n;cin>>n;

    rep1(i,n) cin>>a[i];

    int mark=-1,cur=0,mx=0;

    rf(i,n,1){

        if(mark==-1) mark=a[i];

        else{

            if(a[i]>=mark) mark=a[i],cur++;

            else mark=a[i],cur=0;

            mx=max(mx,cur);

        }

    }

    cout<<mx<<endl;

}

int main(){

#ifdef LOCAL

    freopen("in.txt","r",stdin);

    //freopen("out.txt","w",stdout);

#endif

    IOS;

    int T=1;

    //cin>>T;

    while(T--){

        solve();

    }

    return 0;

}
