#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define pi 3.141592653589793116

#define mod 1e9+7

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;



long long int dp[100001][2][2];

int a[100001];

int n;

long long  go(int i,int curr,int pre1)

{

   if(i==n-1)

     {

         if(curr==1)

           return -a[i];

         else

            return a[i];

     }

    if(dp[i][curr][pre1]!=-1)

       return dp[i][curr][pre1]; 

   else

      {   long long ans=0;

          if(curr==1)

             ans=max({ans,-a[i]+go(i+1,0,curr),a[i]+go(i+1,1,curr)});

          else

             ans=max({ans,a[i]+go(i+1,0,curr),-a[i]+go(i+1,1,curr)});

          dp[i][curr][pre1]=ans;

          return ans;       

      }

}





int main() {

  off;

  int t;

  //cin>>t;

  t=1;

  while(t--){  

     cin>>n;

     for(int i=0;i<n;i++)

        cin>>a[i];

      memset(dp,-1,sizeof(dp));

    long long x=0;

    x=max(a[0]+go(1,0,0),-a[0]+go(1,1,1));

      cout<<x<<'\n';  

  }

    return 0;

}
