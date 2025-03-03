#include <cstdio>

#include <iostream>

using namespace std;

int n, k;



int main() {

    ios::sync_with_stdio(false);

    

    cin >> n >> k;

    int ans = k;

    

    for (int i = 1; i <=n-1; i++)

        ans *= (k-1);

    

    cout << ans << endl;

    return 0;

}