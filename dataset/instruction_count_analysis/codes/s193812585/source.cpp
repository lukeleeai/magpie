#include "stdc++.h"

using namespace std;

int main()

{

    long long n;

    long long ans=0;

    cin>>n;

    if(n%2)

        cout<<0;

    else

    {



       for(long long i =1;i<=n;i*=5)

       {

           ans+=n/(i*10);

           //ans--;

           //cout<<

       }

       cout<<ans;

    }

//124999999999999995

//111111111111111111



}