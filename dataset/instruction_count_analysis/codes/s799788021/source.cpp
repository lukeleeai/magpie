#include <iostream>

using namespace std;

int main()

{

    unsigned long long n, ans, k = 1;

    cin >> n;

    if(n & 1){

        cout << 0 << endl;

        return 0;

    }

    ans = n / 10;

    while ((k*=5) <= n) {

        ans += n / (k*10);

    }

    

    cout << ans << endl;

    return 0;

}