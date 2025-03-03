#include"stdc++.h"

using namespace std;

#define int long long



signed main()

{

    int a[200002], res=0;

    int n;

    cin>>n;

    for (int i=1; i<=n; i++) {cin>>a[i];}

    sort(a+1,a+n+1);

    for (int i=1; i<n; i++)

    {

        if (a[i]==a[i+1]) {cout<<"NO"; return 0;}

    }

    cout<<"YES";

}
