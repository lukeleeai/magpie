#include"stdc++.h"

using namespace std;

long long mod=1e9+7;

long long no[180],ans[180];

map<long long,long long> mp;

long long f(long long k)

{

    if (mp[k]) return mp[k];

    for(int i=1;i<=177;i++)

        if (k==no[i]) return mp[k]=ans[i];

    if (k%2==0) return mp[k]=(2*f(k/2-1)+f(k/2))%mod;

    return mp[k]=(f(k/2-1)+2*f(k/2))%mod;

}

int main()

{

     long long n;

     cin>>n;

     no[1]=0;no[2]=1;no[3]=2;

     ans[1]=1;ans[2]=2;ans[3]=4;

     for(int i=2;i<=59;i++)

     {

          no[3*i-2]=(1ll<<i)-2;

          no[3*i-1]=no[3*i-2]+1;

          no[3*i]=no[3*i-1]+1;

          ans[3*i-2]=(2*ans[3*i-5]+ans[3*i-4])%mod;

          ans[3*i-1]=(ans[3*i-5]+2*ans[3*i-4])%mod;

          ans[3*i]=(ans[3*i-1]+i+1)%mod;

     }

     cout<<f(n)<<endl;

     return 0;

}