#include "stdc++.h"

#define ull unsigned long long

#define ll long long

#define endl '\n'

#define pb push_back

#define mod 1000000007

#define mp make_pair

#define pi acos(-1)

#define line cout<<"----------------------------"<<endl

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

#define filein freopen("input.text","r",stdin)

#define fileout freopen("output.txt","w",stdout)

using namespace std;

const ll mx=200009;	

ll tree[mx*4]; 

ll lazy[mx*4]; 

vector<pair<ll,ll> >l[mx],r[mx]; 

void pushdown(ll node,ll b, ll e)

{

	if(lazy[node])

	{

		tree[node]+=lazy[node]; 

		if(b!=e)

		{

			lazy[node*2]+=lazy[node]; 

			lazy[node*2+1]+=lazy[node]; 

		}

		lazy[node]=0; 

	}

}

void update(ll node, ll b, ll e, ll i, ll j, ll val )

{

	pushdown(node,b,e);

	if(b>j or e<i) return ; 

	if(b>=i and e<=j)

	{

		lazy[node]+=val; 

		pushdown(node,b,e);

		return ;

	}

	ll mid=(b+e)>>1;

	update(node*2,b,mid,i,j,val);

	update(node*2+1,mid+1,e,i,j,val);

	tree[node]=max(tree[node*2],tree[node*2+1]);

}

ll query(ll node, ll b,ll e, ll i, ll j)

{

	pushdown(node,b,e);

	if(b>j or e<i) return LLONG_MIN; 

	if(b>=i and e<=j) return tree[node]; 

	ll mid=(b+e)>>1; 

	return max(query(node*2,b,mid,i,j),query(node*2+1,mid+1,e,i,j));

}

int main()

{

	ll n,m; 

	cin>>n>>m; 

	for(ll i=0;i<m;i++)

	{

		ll a,b,c; 

		cin>>a>>b>>c;

		l[a].pb(mp(a,c));

		r[b].pb(mp(a,c));

	}

	ll ans=0; 

	for(ll i=1;i<=n;i++)

	{

		for(auto x: l[i])

		{

			update(1,0,n,0,x.first-1,x.second);; 

		}

		ll curval=query(1,0,n,0,i-1);

		ans=max(ans,curval);

		update(1,0,n,i,i,curval);

		for(auto x: r[i])

		{

			update(1,0,n,0,x.first-1,-x.second);

		}

	}

	cout<<ans<<endl; 

}


