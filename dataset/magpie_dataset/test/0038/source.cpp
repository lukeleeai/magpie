#include"stdc++.h"

using namespace std;

#define ll long long int

#define soja(i,a,n) for(ll i=a;i<=n;i++)

#define ulta(i,n,a) for(ll i=n;i>=a;i--)

int main()

{

    ll n,m,k,sum=0,t;

   cin>>n;

   map<ll,ll> ma;

   soja(i,0,n-1)

   {

       cin>>k;

       if(ma[k]==INT_MAX)

        ma[k]=1;

       else

        ma[k]++;

        sum+=k;

   }

   cin>>t;

   soja(i,0,t-1)

   {

       cin>>n>>m;

       sum-=ma[n]*n;

       sum+=ma[n]*m;

       if(ma[m]==INT_MAX)

        ma[m]=ma[n];

       else

       ma[m]+=ma[n];

       ma[n]=0;

      // cout<<ma[m]<<" "<<ma[n]<<endl;

       cout<<sum<<endl;

   }



return 0;

}