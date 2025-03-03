/*why so serious?*/

#include"stdc++.h"

using namespace std;

#define   int      long long

#define   fast()   ios_base::sync_with_stdio(0);cin.tie(0)

#define   all(x)   x.begin(),x.end()

#define   pb       push_back

#define   F        first

#define   S        second



int32_t main()

{int n,q,i,l,r;

 string s;

 fast();

 cin>>n>>q>>s;



 vector<int>a(n+1);



 a[0]=a[1]=0;

 char prev=s[0];

 for(i=1;i<n;++i)

 {if(prev=='A' && s[i]=='C')

  a[i+1]=a[i]+1;

  else

  a[i+1]=a[i];

  prev=s[i];

 }



 //for(auto x:a)

 //cout<<x<<" ";

 //cout<<"\n";



 for(;q;--q)

 {cin>>l>>r;

  cout<<a[r]-a[l]<<"\n";

 }

 return 0;

}
