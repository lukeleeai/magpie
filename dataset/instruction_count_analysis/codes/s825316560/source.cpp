#pragma GCC optimize("Ofast",3,"inline")

#include"stdc++.h"

using namespace std;

#define fir first

#define sec second

#define m_p make_pair

#define y1 ygftgfgcdtfgxffgx

#define y2 yfdsesgvtyghftfvv

#define x1 xvyr6cf6fgcfgf676

#define x2 xcr6rfc5r66y6r6fr

#define up_bound upper_bound

#define low_bound lower_bound

#define next_per next_permutation

#define pb push_back

#define i_to_s to_string

typedef priority_queue<int> p_queue;

typedef priority_queue<int, vector<int>, greater<int> > min_p_queue;

typedef long long ll;

typedef long double ld;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;

int mon[20]={31,28,31,30,31,30,31,31,30,31,30,31};

ll gcd(ll x,ll y){return ((y==0)?x:gcd(y,x%y));}

const int N = 4e5 +11;

int n,m,cnt,d,b[N],ans[N];;

struct uzi{int s,t,x,i;}p[N];

struct faker{int x,i; bool operator <(const faker & t)const{return x<t.x;} }a[N];

int cmp(uzi a,uzi b){return a.x<b.x;}

map<int,int>pos;

bool operator < ( pair<int,int>A,pair<int,int>B ){return A.fir<B.fir;}

int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(0);

//	freopen(".in","r",stdin);

//	freopen(".out","w",stdout);

	cin>>n>>m;

	memset(ans,-1,sizeof ans);

	for(int i=1;i<=n;i++){

		cin>>p[i].s>>p[i].t>>p[i].x;

		p[i].s-=p[i].x;p[i].t-=p[i].x;p[i].i=i;

		p[i].s=max(p[i].s,0);

		p[i].t=max(p[i].t,0);

	}

	sort(p+1,p+1+n,cmp);

	for(int i=1;i<=m;i++)cin>>a[i].x,a[i].i=i,pos[a[i].x]=i;

	set<int>s;

	for(int i=1;i<=m;i++)s.insert(a[i].x);

	for(int i=1;i<=n;i++){

		auto l=s.lower_bound(p[i].s);

		auto k=s.lower_bound(p[i].t);

		vector<int>q;

		for(auto j=l;j!=k;j++){

			ans[pos[*j]]=p[i].x;

			q.pb(*j);

		}

		for(auto j:q)s.erase(j);

	}

	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';

	return 0;

}