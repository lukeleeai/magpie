#include"stdc++.h"

using namespace         std;

#define                 int long long

#define                 pb push_back

#define                 mp make_pair

#define st(arr,a)       memset(arr,a,sizeof arr)

#define                 nl cout<<endl

#define                 real signed

#define                 endl '\n'              

#define bitcount(x)     __builtin_popcountll(x)

const int MOD = 1000000007ll;

#define forn(i,a,b)     for(int i=a;i<=b;i++)

#define rfor(i,a,b)     for(int i=a;i>=b;i--)



int arr[100000+50000],n,k;



int dp[150000];



int ans(int ind)

{

    if(ind==n)return 0;

    if(ind>n)return MOD*MOD;



    if(dp[ind]>-1)return dp[ind];





//    dp[ind]=min(abs(arr[ind]-arr[ind+1])+ans(ind+1),abs(arr[ind]-arr[ind+2])+ans(ind+2));

  dp[ind]=MOD*MOD;



  forn(i,ind+1,ind+k)

        dp[ind]=min(dp[ind],abs(arr[ind]-arr[i])+ans(i));

    return dp[ind];

}



signed main() 

{

	ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cin>>n>>k;

    st(dp,-1);

    st(arr,MOD);

    forn(i,1,n)cin>>arr[i];



    cout<<ans(1);



    



     

     









     return 0;



}



//       g++ -g c2.cpp ; ./a.exe