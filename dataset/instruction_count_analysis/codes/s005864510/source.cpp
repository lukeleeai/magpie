#include"stdc++.h"

#define ull unsigned long long

#define ll long long

#define pb push_back

#define endl '\n'

#define line cout<<"----------------------"<<endl

#define mp make_pair

#define mod 1000000007

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

#define filein freopen("input.txt","r",stdin)

#define fileout freopen("output.txt","w",stdout)

using namespace std;

const ll  mx=200009;

vector<ll > v[mx];

ll  sub[mx];

pair<ll ,ll > call(ll  s, ll  par)

{

    ll  white=1,black=1;

    for(auto x: v[s])

    {

        if(x==par) continue;

        pair<ll ,ll > temp=call(x,s);

        white=white*(temp.first+temp.second);

        white%=mod;

        black=black*temp.first;

        black%=mod;

    }

    return {white,black};

}

int  main()

{



    ll  n;

    cin>>n;

    for(ll  i=0;i<n-1;i++)

    {

        ll  a,b;

        cin>>a>>b;

        v[a].pb(b);

        v[b].pb(a);

    }

    pair<ll ,ll > ans=call(1,-1);

    cout<<(ans.first+ans.second)%mod<<endl;

}
