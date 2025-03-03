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

int a[28],b[28];



int main()

{      

     ios::sync_with_stdio(false);

     cin.tie(NULL);

     cout.tie(NULL);

     

      ll n,cnt=0;

     

     cin>>n;

     string s;

     s=to_string(n);



     for(int i=0;i<s.size();i++)

       cnt+=(s[i]-'0');

     if(n%cnt)

      cout<<"No"<<endl;

     else

      cout<<"Yes"<<endl;





      return 0;

      

 }       
