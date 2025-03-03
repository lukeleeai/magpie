

#include"stdc++.h"

#define lli long long int

#define MOD 1000000007

#define KING 1000000002

#define queen 1000002

#define fi first

#define se second

#define se second

#define lsb(i) (i & -i)

#define nl cout<<'\n'

#define TEST cout<<"TEST",nl

#define all(a) a.begin(), a.end()

#define pr pair<lli,lli>

#define pb push_back

#define eb emplace_back

#define mp make_pair

#define vi vector<lli>

#define vpi vector<pr> 

#define P pair<lli,pr>

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)

#define NA(i,s,n) for(lli i=s;i<n;i++)

using namespace std;



lli power(lli x,lli y,lli p) { 

	lli res = 1;	 

	x = x % p; 

	while (y > 0) 

	{ 

		if (y & 1) 

			res = (res*x) % p; 

		y = y>>1; 

		x = (x*x) % p; 

	} 

	return res; 

} 



lli n,a,b,c;



void solve(){

    lli n, p; cin>>n;

	vi a(n+1, 0);

	NA(i,2,n+1){

		cin>>p;

		++a[p];

	}

	NA(i,1,n+1) cout<<a[i]<<'\n';

    return;

}



int main(){

    fastIO;

    lli t = 1; 

    // cin>>t;

    NA(i,0,t) solve();

    return 0;

}
