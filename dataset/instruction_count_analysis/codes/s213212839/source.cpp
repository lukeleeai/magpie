#include"stdc++.h"

typedef long long int ll;

using namespace std;

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    ll n,i;

    cin>>n;

    for(i=n;;i+=n){

        if(i%2==0){

            cout<<i<<endl;

            return 0;

        }

    }

}
