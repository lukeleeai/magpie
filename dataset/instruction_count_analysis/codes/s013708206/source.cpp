#include"stdc++.h"

using namespace std;

int n,a[101101],ans;

int main()

{

    ios::sync_with_stdio(false);

    cin>>n;

    for(int i=1;i<=n;i++)

	{

        cin>>a[i];

    }

    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++)

	{

        if(a[i]==a[i-1])ans++;

    }

    if(ans&1)ans++;

    cout<<n-ans<<"\n";

    exit(0);

}