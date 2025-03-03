#include"stdc++.h"

using namespace std;

long long n,ans=0,a[500010];

int main()

{

    scanf("%lld",&n);

    for(int i=1;i<=3*n;i++) scanf("%lld",&a[i]);

    sort(a+1,a+1+3*n);

    long long mid=n;

    for(int i=3*n-1;i>mid;i-=2)

        ans+=a[i];

    cout<<ans<<endl;

    return 0;

}