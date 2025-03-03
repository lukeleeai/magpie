#include<iostream>

#include <algorithm>

#include <cmath>

#include <iterator>

#include <cstring>

#include <cstdio>

#include <iomanip>

#include <sstream>

#include <map>

#include <unordered_map>

#include <vector> 

#include <bitset>

#include <cctype>

#include <set>

#include <stack>

#include <queue>

#include <fstream>

#include <numeric>

 

using namespace std;

 

typedef long long ll;

typedef unsigned long long ull;

//typedef int_128 lll;

typedef double db;

typedef pair<int, int> pii;

typedef pair<int, string> pis;

typedef pair<ll,ll> pll;

typedef vector<int>::iterator iit;

typedef vector<long long>::iterator llit;

typedef vector<double>::iterator dbit;

template <typename T> inline T abs(T x) { return x > 0 ? x : -x; }

template <typename T> inline T sqr(T x) { return x * x; }

template <typename T> inline T max(T a, T b, T c) { return max(max(a, b), c); }

template <typename T> inline T min(T a, T b, T c) { return min(min(a, b), c); }

template <typename T> inline bool toMax(T& a, T b) { return a < b ? a = b, 1 : 0; }

template <typename T> inline bool toMin(T& a, T b) { return a > b ? a = b, 1 : 0; }

template <typename T> inline T gcd(T a, T b) { if (b == 0)return a; return gcd(b, a % b); }

template <typename T, typename T1> inline T qpower(T x, T p, T1 mod) { T re = 1; x %= mod; while (p) { if (p & 1)re = (re * x) % mod; x = (x * x) % mod; p >>= 1; }return re; }

template <typename T1, typename T2> inline T1 power(T1 x, T2 p) { return x < 0 && p < 1 && -1 < p ? p != 0 ? -pow(-x, p) : 1 : pow(x, p); }

inline bool mr(ll x, ll b) { ll k = x - 1; while (k) { ll cur = qpower(b, k, x); if (cur != 1 && cur != x - 1)return false; if ((k & 1) == 1 || cur == x - 1)return true; k >>= 1; }return true; }

inline bool isprime(ll x) { if (x == 46856248255981ll || x < 2)return false; if (x == 2 || x == 3 || x == 7 || x == 61 || x == 24251)return true; return mr(x, 2) && mr(x, 61); }

template<typename T>inline void read(T &res){char c;res=0;bool f=0;while((c=getchar())<48)if(c=='-')f=1;do res=(res<<1)+(res<<3)+(c^48);while((c=getchar())>47);if(f)res=-res;}

//template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10^48);}

template <typename T> inline string itos(T x) { stringstream ss; string str; ss << x; ss >> str; return str; }

//inline int stoi(string str) { stringstream ss; int x; ss << str; ss >> x; return x; }    C++11自带

const double PI = acos(-1);

const double e = 2.718281828459;

const ll MOD = 1000000007;

const int MAXN = 200005;

const int MAX = 0x3f3f3f3f;

const int INF = 0x80000000;

#define fr first

#define sc second

#define pp make_pair

#define REP(i,a,b) for(register int i=a;i<=b;i++)

#define RP(i,a,b) for(register int i=a;i<b;i++)

#define DRP(i,a,b) for(register int i=a;i>=b;i--)

#define mst(X,Y) memset(X,Y,sizeof(X)) 

#define setp(X) cout.setf(ios_base::fixed,ios_base::floatfield);cout.precision((X)) 

#define debug(X) cerr<<"\tDEBUG: "<<#X<<" = "<<(X)<<endl

//#define writln(X) write(X);putchar('\n')

//#define writsp(X) write(X);putchar(' ') 

#define readf() fstream cin;cin.open("C:\\Users\\86159\\Desktop\\input.txt")

#define writef() fstream cout;cout.open("C:\\Users\\86159\\Desktop\\output.txt")

#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

 

map<int,int> mp;

int a[MAXN];

int main()

{

	int n;

	read(n);

	for (int i=1;i<=n;i++)

	{

		read(a[i]);

		mp[a[i]+i]++;

	}

	ll cnt=0;

	for (int j=1;j<=n;j++)

		if (mp[j-a[j]])

			cnt+=mp[j-a[j]];

	cout<<cnt<<endl;

}

 

 

 

// 