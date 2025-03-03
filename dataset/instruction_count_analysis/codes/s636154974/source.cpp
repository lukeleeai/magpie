#include "stdc++.h"

using namespace std;

#define fio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

#define ll long long

#define dd double

#define pb push_back

#define ff first

#define ss second

#define Mp make_pair

const ll Mod=1000000007;

const ll INF=999999999999999999;

const ll NN=(ll)(1e6+5);

int mod(string s,int a) 

{ 

    int ans=0; 

    for (int i=0;i<s.length();i++) 

         ans=(ans*10+(int)s[i]-'0')%a; 

    return ans; 

}

ll min(ll x,ll y){if(x<y) return x;return y;}

ll max(ll x,ll y){if(x>y) return x;return y;}

ll power(ll x,unsigned ll y) 

{ 

    if (y==0) 

        return 1; 

    else if (y%2==0) 

        return power(x,y/2)*power(x,y/2); 

    else

        return x*power(x,y/2)*power(x,y/2); 

}

ll hcf(ll a,ll b) 

{ 

    if(b==0) 

        return a; 

    return hcf(b,a%b);  

}

char a[6][6];

ll n,m,k;

ll f(bitset <6> bs1,bitset <6> bs2)

{

    map <ll,ll> r,c;

    ll i,j,ans=0;

    for(i=0;i<6;i++)

     if(bs1[i])

      r[i]++;

    for(i=0;i<6;i++)

     if(bs2[i])

      c[i]++;

    for(i=0;i<n;i++)

    {

        if(r[i])

         continue;

        for(j=0;j<m;j++)

        {

            if(c[j])

             continue;

            if(a[i][j]=='#')

             ans++; 

        } 

    }    

    return ans;

}

int main()

{

   fio;

   /*#ifndef ONLINE_JUDGE 

    	freopen("input.txt", "r", stdin); 

    	freopen("output.txt", "w", stdout); 

    	freopen("error.txt", "w", stderr); 

   #endif*/

   ll TT=1;

   //cin>>TT;

   while(TT--)

   {

       ll i,j,ans=0;

       cin>>n>>m>>k;

       for(i=0;i<n;i++)

        for(j=0;j<m;j++)

         cin>>a[i][j];

       for(i=0;i<pow(2,n);i++)

       {

           bitset <6> bs1(i);

           for(j=0;j<pow(2,m);j++)

           {

               bitset <6> bs2(j);

               ans+=(f(bs1,bs2)==k);

           }

       }  

       cout<<ans;          

   }

}