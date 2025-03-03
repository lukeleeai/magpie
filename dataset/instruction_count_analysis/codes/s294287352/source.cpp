#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <cmath>

#include <queue>

#include <stack>

#include <map>

#include <set>

#include <vector>

#include <iomanip>

#define ALL(x) (x).begin(), (x).end()

#define rt return

#define dll(x) scanf("%I64d",&x)

#define xll(x) printf("%I64d\n",x)

#define sz(a) int(a.size())

#define all(a) a.begin(), a.end()

#define rep(i,x,n) for(int i=x;i<n;i++)

#define repd(i,x,n) for(int i=x;i<=n;i++)

#define pii pair<int,int>

#define pll pair<long long ,long long>

#define gbtb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

#define MS0(X) memset((X), 0, sizeof((X)))

#define MSC0(X) memset((X), '\0', sizeof((X)))

#define pb push_back

#define mp make_pair

#define fi first

#define se second

#define eps 1e-6

#define gg(x) getInt(&x)

#define db(x) cout<<"== [ "<<x<<" ] =="<<endl;

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}

inline void getInt(int* p);

const int maxn=1000010;

// const int inf=0x3f3f3f3f;

/*** TEMPLATE CODE * * STARTS HERE ***/

int n;

char op[maxn];

int a[maxn];

ll dp[maxn/10][4];

const ll inf=(ll)(1e18);



int main()

{

    //freopen("D:\\common_text\\code_stream\\in.txt","r",stdin);

    //freopen("D:\\common_text\\code_stream\\out.txt","w",stdout);

    gbtb;

    cin>>n;

    cin>>a[1];

    repd(i,2,n)

    {

        cin>>op[i]>>a[i];

    }

    dp[1][0]=a[1];

    dp[1][1]=dp[1][2]=-inf;

    repd(i,2,n)

    {

        if(op[i]=='+')

        {

            dp[i][0]=max(dp[i-1][0],dp[i-1][1])+a[i];

            dp[i][1]=dp[i-1][1]-a[i];

            dp[i][2]=dp[i-1][2]+a[i];

        }else

        {

            dp[i][0]=-inf;

            dp[i][1]=max(dp[i-1][0],dp[i-1][1])-a[i];

            dp[i][2]=max(dp[i-1][2],dp[i-1][1])+a[i];

        }

    }

    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;

    

    

    return 0;

}



inline void getInt(int* p) {

    char ch;

    do {

        ch = getchar();

    } while (ch == ' ' || ch == '\n');

    if (ch == '-') {

        *p = -(getchar() - '0');

        while ((ch = getchar()) >= '0' && ch <= '9') {

            *p = *p * 10 - ch + '0';

        }

    }

    else {

        *p = ch - '0';

        while ((ch = getchar()) >= '0' && ch <= '9') {

            *p = *p * 10 + ch - '0';

        }

    }

}


