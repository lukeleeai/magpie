#include "stdc++.h"



using namespace std;



const int N = 3e5+5;



typedef long long ll;



char s[N];



int a[N];



int flag[N];



int main()



{



    int n;



    string s;



    cin>>n>>s;



    int l=0,r=0;



    for(int i=1;i<n;i++){



        if(s[i]=='W') r++;



    }



    int ans=n-r-1;



    for(int i=1;i<n;i++){



        if(s[i-1]=='E')  l++;



        if(s[i]=='W') r--;



        ans=min(ans,n-l-r-1);



    }



    cout<<ans<<endl;



}