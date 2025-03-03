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

#define LCM(a,b) ((a*b)/__gcd(x,y))

const int INF = 0x3f3f3f3f, mod = 1e9 + 7;



class triplet{

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

    }

    return ar;

}

void out(vl v, char ch='\0'){

    fl(i,v)

    cout<<i<<ch;

}



void solve(){

    ll N;

    cin>>N;

    bool flag=false;

    for(int i=1;i<10;i++)

    if(N%i == 0)

    if(N/i < 10  &&  N/i > 0)

    flag=true;



    flag ? cout<<"Yes" : cout<<"No";

}



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    solve();

   return 0;

}