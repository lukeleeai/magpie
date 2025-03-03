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

       ll n,m,k,c,i,j,ii,jj,ans=0;

       cin>>n>>m>>k;

       char a[n][m];

       for(i=0;i<n;i++)

        for(j=0;j<m;j++)

         cin>>a[i][j];

       for(i=0;i<(1<<n);i++)

       {

           for(j=0;j<(1<<m);j++)

           {

               c=0;

               for(ii=0;ii<n;ii++)

               {

                   for(jj=0;jj<m;jj++)

                   {

                       if(i>>ii&1&&j>>jj&1&&a[ii][jj]=='#')

                        c++;

                   }

               }

               ans+=(c==k);

           }

       }  

       cout<<ans;          

   }

}
