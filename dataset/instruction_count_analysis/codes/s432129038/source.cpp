#include"stdc++.h"

using namespace std;

int main(){

    int ans=1,n,k;

    cin>>n>>k;

    for (int i=1;i<=n;i++)

    	ans+=min(ans,k);

    cout<<ans<<endl;

    return 0;

}