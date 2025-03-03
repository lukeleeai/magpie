#include "stdc++.h"



using namespace std;



#ifdef ZERO_IQ

ios_base::sync_with_stdio ( false ), cin.tie ( 0 ), cout.tie ( 0 );

#endif



int main() {

    int n, m;

    cin >> n >> m;

    cout << 1LL * ((n - 1) + (m - 2)) / (m - 1) << endl;

    return 0;

}