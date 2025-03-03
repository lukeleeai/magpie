#include"stdc++.h"

using namespace std;



#define f(i,n) for(auto i=0;i<n;i++)

#define fr(i,n) for(auto i=n-1;i>=0;i--)

#define fs(i,a,b,c) for(auto i=a;i!=b;i+=c)

#define fl(i,x) for(auto i : x)

#define nl cout<<"\n";

#define ll long long int

#define vl vector<ll>

#define mid(a,b) ((a+b)/2)

#define pb push_back



class triplet{ll f, s, t;};



vl in(ll n){vl v;ll x;

    f(i,n)

    cin>>x, v.pb(x);

    return v;}

void out(vl v){fl(i,v)cout<<i;}

void out(vl v, char ch){

    fl(i,v)

    cout<<i<<ch;}



ll attack(ll ar[10000][10000], ll i, ll j, ll k){

    return ((i+2 < k) && (j+1 < k)) + ((i+2 < k) && (j-1 >= 0)) + ((i-2 >= 0) && (j+1 < k)) + ((i-2 >= 0) && (j-1 >= 0));

}



void solve(){

    char ch;

    cin>>ch;

    cout<<(char)(ch+1);

}

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    solve();

   return 0;

}