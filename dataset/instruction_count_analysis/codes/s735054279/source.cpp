#include<iostream>

#include<algorithm>

#define ll long long

using namespace std;

int a[200005],b[200005];

int main()

{

    int n;

    cin>>n;

    for(int i=0;i<n;i++)

        cin>>a[i];

    ll ans=0;

    for(int i=0;i<n;i++)

    {

        if(i+a[i]<=n)

            b[a[i]+i]++;

        if(i-a[i]>=0)

            ans+=b[i-a[i]];

    }

    cout<<ans<<endl;

    return 0;

}
