#include "stdc++.h"

using namespace std;

int main(){



    int n,k; cin >> n >> k;

    n -= 1;

    unsigned long long ans = k;

    while(n--){



        ans *= k-1;



    }

    cout << ans;



}