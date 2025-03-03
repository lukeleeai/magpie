#include"stdc++.h"



using namespace std;

 

typedef long long ll;

#define For(i,x,y) for(int i=x; i<y; ++i)

#define mem(x,y) memset(x,y,sizeof(x))

#define ALL(a) a.begin(),a.end()

#define PII pair<int,int>

#define INF 0x3f3f3f3f

#define DOF 0x7f7f7f7f

#define se second

#define fi first

#define endl '\n'

 

template <typename T>

inline void read(T &r){

    static char c; r=0; int f=1;

    for(c=getchar(); c<'0'||c>'9'; c=getchar()) if(c=='-')f=-1;

    for(; c>='0'&&c<='9'; r=(r<<1)+(r<<3)+(c^48),c=getchar());

    r*=f;

} // -_-



const int N = 2e5 + 105;

ll a[N], pre[N], k;

int main(){

    int n; scanf("%d", &n);

    scanf("%lld", &k);

    pre[0] = 0;

    for(int i = 1; i <= n; ++i){

        scanf("%lld", &a[i]);

        pre[i] = pre[i - 1] + a[i];

    }

    map<ll, int>ma;

    ll ans = 0;

    for(int i = 0; i <= n; ++i){

        if(i >= k){

            ma[(pre[i - k] - (i - k))%k] --;

        }

        if(ma[(pre[i] - i)%k]){

            ans += ma[(pre[i] - i)%k];

        }

        ma[(pre[i] - i)%k] ++;

    }

    cout<<ans<<endl;

    // system("pause");

    return 0;

}