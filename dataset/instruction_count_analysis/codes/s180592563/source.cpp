#pragma GCC optimize("Ofast")

#pragma GCC optimize("inline")

#pragma comment(linker,"/STACK:1024000000,1024000000")

#undef __STRICT_ANSI__

#include <cstdio>

#include <cmath>

#include <cstdlib>

#include <string>

#include <cstring>

#include <cctype>

#include <sstream>

#include <cfloat>

#include <complex>

#include <climits>

#include <new>

#include <memory>

#include <cerrno>

#include <cassert>

#include <ctime>

#include <set>

#include <map>

#include <list>

#include <queue>

#include <deque>

#include <stack>

#include <vector>

#include <bitset>

#include <utility>

#include <iterator>

#include <iostream>

#include <fstream>

#include <iomanip>

#include <numeric>

#include <algorithm>

#include <functional>

#include <unordered_map>

#include <unordered_set>

#include <streambuf>

#include <cfenv>

#include <tuple>

#include <cstdint>

#include <random>

#include <regex>

#define lc c[0]

#define rc c[1]

#define fir first

#define sec second

#define lson x<<1

#define rson x<<1|1

#define PB push_back

#define PF push_front

#define MP make_pair

#define MT make_tuple

#define EB emplace_back

#define Lson l,m,lson

#define Rson m+1,r,rson

#define LB lower_bound

#define UB upper_bound

#define npos string::npos

#define FF fflush(stdout)

#define PQ priority_queue

#define rint register int

#define sqr(X) ((X)*(X))

#define cbr(X) ((X)*(X)*(X))

#define LBT(X) ((X)&(-(X)))

#define SZ(X) (int)(X).size()

#define ALL(X) (X).begin(),(X).end()

#define INS(X) inserter((X),(X).begin())

#define CPY(X,Y) memcpy((X),(Y),sizeof((Y)))

#define MEM(X,Y) memset((X),(Y),sizeof((X)))

#define POS(X,Y,Z) lower_bound((X),(Y),(Z))-(X)+1

#define SC(X) while(scanf("%s",(X)),!strlen((X)))

#define SU(X,Y,Z) sort((X),(Y)),(Z)=unique((X),(Y))-(X)

#define NUM(X,Y,L,R) UB((X),(Y),(R))-LB((X),(Y),(L))

#define INF 0x3f3f3f3f

#define NNF 0xc0c0c0c0

#define INF64 0x3f3f3f3f3f3f3f3f

#define NNF64 0xc0c0c0c0c0c0c0c0

#define ALP 0.75

#define P 131

using namespace std;

typedef long long LL;

typedef long double LD;

typedef unsigned int UI;

typedef unsigned long long ULL;

typedef pair<LL,LL> PLL;

typedef pair<int,LL> PIL;

typedef pair<LL,int> PLI;

typedef pair<int,int> PII;

typedef pair<char,int> PCI;

typedef pair<int,string> PIS;

typedef pair<string,int> PSI;

typedef pair<double,int> PDI;

typedef pair<double,double> PDD;

typedef pair<string,string> PSS;

typedef tuple<LL,LL,LL> PLLL;

typedef tuple<LL,LL,int> PLLI;

typedef tuple<int,LL,LL> PILL;

typedef tuple<LL,int,int> PLII;

typedef tuple<int,int,LL> PIIL;

typedef tuple<int,int,int> PIII;

typedef tuple<LL,LL,LL,LL> PLLLL;

typedef tuple<int,int,int,int> PIIII;

typedef tuple<double,double,int> PDDI;

typedef tuple<double,double,double> PDDD;

typedef tuple<double,double,double,int> PDDDI;

typedef set<LL> SL;

typedef set<int> SI;

typedef set<PII> SPII;

typedef set<PIL> SPIL;

typedef set<PLI> SPLI;

typedef set<PLL> SPLL;

typedef set<PIII> SPIII;

typedef set<PLLL> SPLLL;

typedef set<string> SS;

typedef queue<int> QI;

typedef queue<PII> QPII;

typedef queue<PIL> QPIL;

typedef queue<PLI> QPLI;

typedef queue<PLL> QPLL;

typedef deque<int> DI;

typedef deque<PII> DPII;

typedef deque<PIL> DPIL;

typedef deque<PLI> DPLI;

typedef deque<PLL> DPLL;

typedef complex<LL> CL;

typedef complex<int> CI;

typedef complex<double> CD;

typedef map<LL,LL> MLL;

typedef map<int,LL> MIL;

typedef map<LL,int> MLI;

typedef map<int,int> MII;

typedef map<PII,int> MPIII;

typedef map<PLL,int> MPLLI;

typedef map<int,double> MID;

typedef map<string,int> MSI;

typedef vector<LL> VL;

typedef vector<int> VI;

typedef vector<VI> VVI;

typedef vector<VL> VVL;

typedef vector<PII> VPII;

typedef vector<PIL> VPIL;

typedef vector<PLI> VPLI;

typedef vector<PLL> VPLL;

typedef vector<string> VS;

typedef vector<PIII> VPIII;

typedef vector<PIIL> VPIIL;

typedef vector<PILL> VPILL;

typedef vector<PLLL> VPLLL;

typedef vector<PLII> VPLII;

typedef vector<PLLI> VPLLI;

typedef vector<PIIII> VPIIII;

typedef vector<PLLLL> VPLLLL;

template<class T> inline T gcd(T x,T y) {return y?gcd(y,x%y):x;}

template<class T> inline T lcm(T x,T y) {return x/gcd(x,y)*y;}

template<class T> inline void adm(T &x,T y,T z) {x=x+y;if(x>=z)x=x-z;}

template<class T> inline void adj(T &x,T y) {if(x>=y||x<=-y)x=x%y;if(x<0)x=x+y;}

template<class T> inline T qpow(T x,LL y,T z) {for(;y;y>>=1,x=x*x)if(y&1)z=z*x;return z;}

template<class T> inline T mpow(LL w,T x,LL y,T z) {for(;y;y>>=1,x=x*x,x=x%w)if(y&1)z=z*x,z=z%w;return z;}

template<class T> inline T exgcd(T a,T b,T &x,T &y) {T t=a;b?(t=exgcd(b,a%b,y,x),y=y-(a/b)*x):(x=1,y=0);return t;}

const double EPS = 1e-10;

const LL MOD = 1000000007LL;

const int M = 5000005;

const int N = 3001;

int n,cur;

LL dp[2][N],ans;

char ch;



int main()

{

    scanf("%d\n",&n);

    dp[0][1]=1LL;

    for (rint i=2;i<=n;i++,cur^=1)

    {

        scanf("%c",&ch);

        MEM(dp[cur^1],0);

        if (ch=='<')

        {

            for (rint j=2;j<=i;j++) 

            {

                adm(dp[cur^1][j],dp[cur^1][j-1],MOD);

                adm(dp[cur^1][j],dp[cur][j-1],MOD);

            }

        }

        else 

        {

            for (rint j=i-1;j>=1;j--) 

            {

                adm(dp[cur^1][j],dp[cur^1][j+1],MOD);

                adm(dp[cur^1][j],dp[cur][j],MOD);

            }

        }

    }

    for (rint i=1;i<=n;i++) ans+=dp[cur][i];

    printf("%lld\n",ans%MOD);

    return 0;

}
















