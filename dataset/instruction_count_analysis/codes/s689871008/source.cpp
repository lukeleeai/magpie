#include"stdc++.h"

using namespace std;

#define ll long long

#define pb push_back

#define pii pair<int,int>

map<pii,int>m;



vector<int>adjb[200005],adjr[200005];





#define MOD 1000000007

int main()

{





    ll n,m,i,ANS=0,ans=0,ans2=0;

    cin>>n>>m;

    ll ara[n],arb[m];

    for(i=0;i<n;i++) cin>>ara[i];

    for(i=0;i<m;i++) cin>>arb[i];

    ll mul=-n+1;

    for(i=0;i<n;i++) {

    ara[i]=(ara[i]*mul)%MOD;

    mul+=2;

    }



    mul=-m+1;

    for(i=0;i<m;i++) {

    arb[i]=(arb[i]*mul)%MOD;

    mul+=2;

    }

    for(i=0;i<n;i++) ans=(ans+ara[i])%MOD;

    for(i=0;i<m;i++) ANS=(ANS+(arb[i]*ans)%MOD)%MOD;

    cout<<ANS;











}