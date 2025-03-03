#include "stdc++.h"



using namespace std;



#define MXN 100005



int a[MXN];



int main() { 

    int n, res = 0;

    while (cin >> n) {

        memset(a, 0, sizeof(a));

        for (int i = 1; i <= n; ++i) {

            cin >> a[i];

            res += abs(a[i]-a[i-1]);

        }

        res += abs(a[n]);

        for (int i = 1; i <= n; ++i) {

            cout << res-abs(a[i]-a[i-1])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1]) << "\n";

        }

    }



    return 0;

}
