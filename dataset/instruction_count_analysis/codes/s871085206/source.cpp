#include"stdc++.h"

#include <cstring>

using namespace std;

#define ll  long long

#define endl '\n'

const ll mod = 1000000007;

const double PI = 3.141592653589793238463;

using namespace std;

int main()

{

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll x;

    cin>>x;

    ll m=sqrtl(x);

    for (int i=m;i>0;i--){

        if (x%i==0){

            cout<<x/i+i-2<<endl;

            break;

        }

    }

    return 0;

}
