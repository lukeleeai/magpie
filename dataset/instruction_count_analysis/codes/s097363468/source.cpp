#include"stdc++.h"

using namespace std;

#define ll long long

ll n,k,a[100000];

ll f[100000],ans=1e18;

int main(){

    cin>>n>>k;

	memset(f,0x3f,sizeof(f));

    for(int i=0;i<n;i++){

		cin>>a[i];

	}

    for(int i=0;i<=n;i++){

        for(int j=0;j<n;j++)

            f[j]=min(f[j],a[(j-i+n)%n]);

        ll ret=0;

        for (int j=0;j<n;++j) ret+=f[j];

        ans=min(ans,ret+1ll*k*i);

    }

    cout<<ans<<endl;

    return 0;

}
