#include<iostream>

#include<algorithm>

using namespace std;

int a[3];

int main()

{

    cin>>a[0]>>a[1]>>a[2];

    sort(a,a+3);

    int ans=2*a[2]-a[1]-a[0];

    if (ans%2)

        ans+=3;

    ans/=2;

    cout<<ans<<endl;

    return 0;

}
