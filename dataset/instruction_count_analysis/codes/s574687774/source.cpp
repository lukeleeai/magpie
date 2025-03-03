#include"stdc++.h"

using namespace std;

typedef long long ll;

ll minn=1e18+7;

const int maxn=1e5+7;

ll s[maxn];

int main(){

    ll n,a,b,i;

    ll sum=0;

    cin>>n>>a>>b;

    for(i=1;i<=n;i++){

        cin>>s[i];

    }

    for(i=2;i<=n;i++){

        sum+=min((s[i]-s[i-1])*a,b);

    }

    cout<<sum<<endl;

    return 0;

}
