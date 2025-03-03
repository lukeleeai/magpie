#include <iostream>

using namespace std;

typedef long long ll;

int main()

{

    ll n,m;

    cin>>n>>m;

    if(abs(n-m)>1)

    {

        cout<<0<<endl;

        return 0;

    }

    if(n==m)

    {

    ll brojac=1;

    for(ll i=1;i<=n;i++)

    {

        brojac*=i;

        brojac%=1000000007;

    }

    for(ll i=1;i<=n;i++)

    {

        brojac*=i;

        brojac%=1000000007;

    }

    brojac*=2;

    brojac%=1000000007;

    cout<<brojac<<endl;

    }

    else

    {

        ll brojac=1;

        if(n<m)

            swap(n,m);

        for(ll i=1;i<=n;i++)

    {

        brojac*=i;

        brojac%=1000000007;

    }

    for(ll i=1;i<=m;i++)

    {

        brojac*=i;

        brojac%=1000000007;

    }

    cout<<brojac<<endl;

    }

    return 0;

}