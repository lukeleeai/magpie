/*|In The Name of Allah|*/

/* Dear GCC compiler:

*

* If my code doesn't compile, this doesn't mean it's wrong.

* It just mean that you don't understand what I want.

* Here's my safety pig, I hope my code compile and get accepted.

* _._ _..._ .-',     _.._(`))

*'-. `     '  /-._.-'    ',/

*   )         \            '.

*  / _    _    |             \

* |  a    a    /              |

* \   .-.                     ;

*  '-('' ).-'       ,'       ;

*     '-;           |      .'

*        \           \    /

*        | 7  .__  _.-\   \

*        | |  |  ``/  /`  /

*       /,_|  |   /,_/   /

*          /,_/      '`-'

*/

#include "stdc++.h"

using namespace std;

long long power(long long x, long long y){

if (y == 0)

	return 1;

long long ret = power(x , y >> 1) %1000000007 ;

if (y % 2 == 0)

	return (ret * ret) % 1000000007;

else

	return (x * (ret * ret % 1000000007)) % 1000000007;

}



pair<int, int> norm(pair<int, int> p)

{

	if(p.first < 0)

	{

		p.first *= -1;

		p.second *= -1;

	}

	else if (p.first == 0 && p.second < 0)

	{

		p.second *= -1;

	}

	int d = __gcd(abs(p.first), abs(p.second));

	p.first /= d;

	p.second /= d;

	return p;

}



/*

	void dikstra(){

	for (int i=1;i<=n;i++)dst[i]=oo;

	clr(vis,0);

	clr(parent,-1);

	dst[1]=0;

	parent[1]=-1;

	s.insert( mp(0,1 ) );

	while(!s.empty()){



		pair<ll,ll> x=*s.begin();

		s.erase(s.begin());

		ll u=x.sc;

		ll d=x.fr;

		if (vis[u])continue;

		vis[u]=1;

		for (int i=0;i<v[u].size();i++){

			ll to=v[u][i].fr;

			ll cost=v[u][i].sc;

			if (vis[to]||d+cost>=dst[to])continue;

			dst[to]=d+cost;

			parent[to]=u;

			s.insert(mp(d+cost,to));

		}

	}









	vi v;

if (dst[n]==oo)return cout<< -1,0;



int nn=n;

	while(parent[nn]!=-1){

		v.push_back(nn);

		nn=parent[nn];

	}

		reverse(all(v));



	}





int parent[N], sz[N];

int n, m, components;



void init(){

  iota(parent, parent+n, 0);

  fill(sz, sz+n, 1);

  components = n;

}



int find(int u){

  if(parent[u] == u)  return u;

  return parent[u] = find(parent[u]);

}



void join(int u, int v){

  u = find(u), v = find(v);

  if(u == v)  return;

  if(sz[u] < sz[v]) swap(u, v);

  parent[v] = u;

  sz[u] += sz[v];

  --components;

}



*/

const double Eps =(1e-7);

int dcmp(double x,double y){ return fabs(x-y)<=Eps? 0: x<y ?-1:1; }

typedef long long ll;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<string> vs;

typedef vector<pair<int,int> > vii;

typedef map<int, int> mii;

typedef map<string, int> msi;

typedef pair<int, int> pii;

#define mii map <int, int>

#define mll map <ll, ll>

#define pii pair <int, int>

#define pll pair <ll, ll>

#define vi vector <int>

#define vd vector <double>

#define vll vector <ll>

#define sll set <ll>

#define spii set <pii>

#define vpii vector <pair <int,int> >

#define vpll vector <pair <long long,long long> >

#define vvi vector <vector <int> >

#define vvpii vector <vector <pii > >

#define sfi1(v) scanf("%d",&v)

#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)

#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)

#define sfll1(v) scanf("%I64d",&v);

#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)

#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)

#define min3(a,b,c)     min(a,min(b,c))

#define max3(a,b,c)     max(a,max(b,c))

#define min4(a,b,c,d)   min(a,min(b,min(c,d)))

#define max4(a,b,c,d)   max(a,max(b,max(c,d)))

#define el	'\n'

#define lp(i,n) for(int i = 0;i < int(n);i++)

#define lp1(i,n) for(int i = 1;i <= int(n);i++)

#define rlp(i, n) for (int i = (n) - 1; i >= 0; i--)

#define rng(i,a,b) for(int i = int(a);i <= int(b);i++)

#define mp(x,y)  	make_pair((x),(y))

#define pb(x)    	push_back((x))

#define all(v)  	((v).begin()),((v).end())

#define sz(x)  		((int) (x).size())

#define bits(a) 	__builtin_popcountll(a)

#define fr first

#define sc second

#define pii pair<int, int>

#define sortva(v) sort(all(v))

#define sortvd(v) sort(v.rbegin(),v.rend())

#define sortaa(a,n) sort(a,a+n)

#define sortad(a,n) sort(a,a+n),reverse(a,a+n)

#define SS stringstream

#define ll long long

#define clr(x, y) memset(x, y, sizeof(x))

#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)

#define read freopen("input.in", "rt", stdin);

#define write freopen("output.in", "wt", stdout);

#define fastIO cout << fixed << setprecision(0), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);



int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int kx[] = { 2, 2, 1, -1, -2, -2, 1, -1 };

int ky[] = { 1, -1, 2, 2, 1, -1, -2, -2 };

ll gcd(ll a, ll b){if (a == 0)return b;return gcd(b % a, a);}







int const N = 5e5+9, mod = 1e9+7 , oo = 1e9+7;



//------------------------------------------------------------------------------------





int pref[N];

int arr[N];

int n;

int main()

{

	cin>>n;

	lp1(i,n)cin>>arr[i];

	lp1(i,n)pref[i]=pref[i-1]+arr[i];



	int sum=oo;

	for (int i=1;i<=n;i++){

		sum=min(sum,abs(pref[i]-(pref[n]-pref[i])));

	}



	cout<<sum;











/*

*/

return 0;

}
