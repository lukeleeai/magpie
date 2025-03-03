#include"stdc++.h"

#define pb       push_back

#define mp       make_pair

#define mod      1000000007

#define first    ff

#define second   ss

#define pi       acos(-1.0)

#define test     int t;cin>>t;while(t--)

typedef long long ll;

using namespace std;

vector<int>node[10001];

ll bigmod(ll a,ll b)

{

    ll  res=1;

    a=a%mod;

    if(a==0)

        return 0;

    while(b>0)

    {



           if(b%2)

            res=(res*a)%mod;

            b=b>>1;

            a=(a*a)%mod;

    }

    return res;

}

int main()

{      





     ios::sync_with_stdio(false);

     cin.tie(NULL);

     cout.tie(NULL);

     

     int n;

     cin>>n;



     ll ans=(bigmod(10,n)-(2*bigmod(9,n))%mod+bigmod(8,n))%mod;

     if(ans<0)

        cout<<ans+mod<<endl;

     else

     cout<<ans<<endl;



      return 0;

    

 }   