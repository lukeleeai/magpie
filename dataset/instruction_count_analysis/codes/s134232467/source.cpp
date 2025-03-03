#include"stdc++.h"

using namespace std;

#define ll long long

vector<ll>vi;

vector<ll> :: iterator vt;

ll arr[200009];

int main()

{

    ll n,t,x,y,z,j,i,k,m,flag =0,maxi=LONG_LONG_MIN ,mini=LONG_LONG_MAX,sum=0,c=0;

    map<string,ll>mp;

    map<string,ll> :: iterator mt;

    string s, ss;

    cin>>n;

    for(i = 0 ;i<n ;i++)

    {

        cin>>s;

        mp[s]++;

    }

    cin>>m;

    for(i  = 0;i<m ;i++)

    {

        cin>>s;

        mp[s]--;

    }

    for(mt = mp.begin() ;mt!= mp.end() ;mt++)

    {

        maxi = max(mt->second,maxi);

    }

    if(maxi<0)

        maxi = 0;

    cout<<maxi<<endl;

}
