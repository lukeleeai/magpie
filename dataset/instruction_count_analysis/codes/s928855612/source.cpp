#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define pi 3.141592653589793116

#define mod 1e9+7

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int main() {

  off;

  int t;

  //cin>>t;

  t=1;

  while(t--){  

    int n;

    cin>>n;

    int a[n],c=0,min1=INT_MAX;

    for(int i=0;i<n;i++)

        {

            cin>>a[i];

            if(a[i]<0)

              ++c;

          min1=min(min1,abs(a[i]));

        }

    long long sum=0;

    for(int i=0;i<n;i++)

       sum+=abs(a[i]);

     if(c%2==0)

       {

          cout<<sum<<'\n';

       }

     else

       {

          cout<<sum-2*min1<<'\n';

       }    



  }

    return 0;

}