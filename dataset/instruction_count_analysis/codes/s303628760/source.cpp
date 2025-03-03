#include "stdc++.h"

using namespace std;



int main() {

    int N, K;

    cin >> N >> K;

    vector<int> A(N);

    for(int i = 0; i < N; ++i) {

        cin >> A[i];

    }



    int g = 0;

    int ma = 0;

    for(int i = 0; i < N; ++i) {

        g = __gcd(g, A[i]);

        ma = max(ma, A[i]);

    }

    if(ma >= K && K % g == 0) {

        cout << "POSSIBLE" << endl;

    } else {

        cout << "IMPOSSIBLE" << endl;

    }

}
