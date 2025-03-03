#include"stdc++.h"

using namespace std;

#define maxn (int)1e5+1000

typedef long long ll;



int main()

{

    ll n,k;

    cin >> n >> k;

    if(n > k)

        n %= k;

    ll minn = n;

    int t = 100000;

    while(t--)

    {

        n = abs(n - k);

        minn = min(minn,n);

    }

    cout << minn << endl;

}
