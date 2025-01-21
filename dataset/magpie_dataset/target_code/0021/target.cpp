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

const ll  mx=300009;

ll  ara[mx];

ll  cost[mx];

int main()

{

    ll n,k;

    cin>>n>>k;

    for(ll  i=1;i<=n;i++) cin>>ara[i];

    cost[1]=0;

    cost[2]=abs(ara[2]-ara[1]);

    for(ll  i=3;i<=n;i++)

    {

        cost[i]=LLONG_MAX;

        for(ll  j=1;j<=min(i-1,k);j++)

        {

            cost[i]=min(cost[i],cost[i-j]+abs(ara[i]-ara[i-j]));

        }

    }

    cout<<cost[n]<<endl;





}
