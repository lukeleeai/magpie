#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

#define MOD 1000000007

#define PI 3.141592653589793



int main(){

    int d, n;

    cin >> d >> n;

    int ans;

    if(d == 0)

        if(n != 100)

            ans = n;

        else

            ans = 101;

    else if(d == 1)

        if(n != 100)

            ans = n * 100;

        else

            ans = 10100;

    else

        if(n != 100)

            ans = n * 10000;

        else

            ans = 1010000;

    cout << ans << endl;

}
