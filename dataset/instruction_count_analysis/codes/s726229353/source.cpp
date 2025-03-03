#include<iostream>

#include<cstdio>

#include<algorithm>

#include <cstring>

using namespace std;

int main()

{

    int t=1,i=0,n,q,a[100005],N[100005]= {0},maxl=0,d;

    long long k;

    cin>>n>>k>>q;

    for(i=1; i<=q; i++)

    {

        cin>>a[i];

        N[a[i]]++;

    }

    for(i=1; i<=n; i++)

        if(N[i]>N[maxl])

            maxl=i;

    for(i=1; i<=q; i++)

        if(a[i]!=maxl)

            --k;

    for(i=1; i<=n; i++)

        if(N[i]+k-N[maxl]<=0)

            cout<<"No\n";

        else

            cout<<"Yes\n";

    return 0;

}


