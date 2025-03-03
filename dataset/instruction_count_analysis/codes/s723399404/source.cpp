//----------------------Shanu Garg here---------------------

//-------------Search on youtube : Shanu Garg---------------

//-Studying at National Institute of Technology Delhi(NITD)-

//---------------------From Delhi, India--------------------



#include"stdc++.h"

#include<algorithm>

using namespace std;



#define f(i,n) for(auto i=0;i<n;i++)

#define fr(i,n) for(auto i=n-1;i>=0;i--)

#define fs(i,a,b,c) for(auto i=a;i!=b;i+=c)

#define fl(i,x) for(auto i : x)

#define memset(a,first,last,val) fs(i,first,last,1) a[i]=val

#define nl cout<<"\n";

#define chk(x) cout<<#x<<x<<" ", nl

#define ll long long int

#define ull unsigned long long int

#define vi vector<int>

#define vvi vector<vi>

#define pr pair<ll, ll>

#define vii vector<pair<int, int>>

#define vll vector<pr>

#define vl vector<ll>

#define m(a,b) map<a, b>

#define mid(a,b) ((a+b)/2)

#define pb push_back

const int INF = 0x3f3f3f3f, mod = 1e9 + 7;



class triplet{

    public:

    ll f, s, t;};



vl in(ll n){vl v;ll x;

    f(i,n)

    cin>>x, v.pb(x);

    return v;}



vll in_pr(ll n){

    vll ar;

    ll x,y;

    f(i,n)

    {cin>>x>>y;

    ar[i]={x,y};

    }return ar;

}

void out(vl v, char ch='\0'){

    fl(i,v)

    cout<<i<<ch;

}



void solve(){

    ll A, P;

    cin>>A>>P;

    A*=3;

    A+=P;

    cout<<A/2;nl

}



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    solve();

   return 0;

}




