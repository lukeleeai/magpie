#include"stdc++.h"

#define ll long long

using namespace std;

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);



    ll n,k;

    cin>>n>>k;



    n=n%k;

    while(abs(n-k) < n)

    {

        n=abs(n-k);

    }

    cout<<n<<"\n";

return 0;

}
