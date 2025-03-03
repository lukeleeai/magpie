#include"stdc++.h"

using namespace std;

#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define  ll  long long

#define  pi  pair<int,int>

#define  pb  push_back

#define  F   first

#define  S   second

const int N=2e5+2;

int main()

{

    ft

    ll t,i,j,n,m,s=0;

    cin>>n;

    for(i=0; i<n; i++)

    {

        cin>>m;

        s+=(m-1);

    }

    cout<<s<<"\n";

    return 0;

}


