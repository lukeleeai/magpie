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



lli n;

vi gp[200002], ans(2e5+2);



void solve(){

    cin>>n; lli p;

    NA(i,2,n+1) cin>>p, gp[p].pb(i);

    NA(i,1,n+1) cout<<gp[i].size()<<'\n'; 

    return;

}    



int main(){

    fastIO;

    lli t = 1; 

    // cin>>t;

    NA(i,0,t) solve();

    return 0;

}
