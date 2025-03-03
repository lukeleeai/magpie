#pragma GCC optimize("O3")

#include "stdc++.h"

using namespace std;

typedef  long long ll;

typedef  vector<int> vi;

typedef  pair<int,int> pii;

typedef  pair<int,string> pis;

double pi=3.1415926535898;

#define speed      ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

#define lop(i,n)   for(int i=0;i<int(n);i++)

#define rep(i,a,b) for(int i=a;i<=int(b);++i)

#define rng(i,a,b) for(int i=a;i>=int(b);i--)

#define ms(x,a)    memset(x,a,sizeof(x))

#define all(x)     (x).begin(),(x).end()

#define sz(x)      int(x.size())

#define pb         push_back

#define r0         return 0;

#define CC         continue;

#define bb(x)      cerr<< x <<endl;

#define F          first

#define S          second       //  __builtin_popcount;

//freopen("output.txt","w",stdout),freopen("input.txt","r",stdin);

const ll M  = 1e9+7 ;

const int N = 300100;

const int inf = INT_MAX;

const double eps = 1e-7;

//////////////////////    Hi    ^_^  hack me if you can :P



int a[100];

int n, p;

int s;

ll mem[100][5005];

ll dp ( int i, int s)

{

    if ( i == n) return s%2 == p;

    ll &r = mem[i][s];

    if (r!=-1)

    {

        return r;

    }

    return r = dp(i+1,s+a[i])+dp(i+1,s);

}

int main()

{

    speed;

    cin >> n >> p;

    lop(i,n) cin >> a[i];

    ms(mem,-1);

    cout << dp(0,0);



    return 0;

}
