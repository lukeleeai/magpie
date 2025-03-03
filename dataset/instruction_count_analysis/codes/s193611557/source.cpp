// This file is a "Hello, world!" in C++ language by GCC for wandbox.

#include <iostream>

#include <cstdlib>

#include <algorithm>

using namespace std;

using ll = long long;





ll A[100010], B[100010], C[100010];

int main()

{

    int N; cin >> N;

    for(int i=0; i<N; ++i) cin >> A[i];

    for(int i=0; i<N; ++i) cin >> B[i];

    for(int i=0; i<N; ++i) cin >> C[i];

    

    sort(A, A+N);

    sort(B, B+N);

    sort(C, C+N);

    

    ll ans=0;

    for(int i=0; i<N; ++i){

        ll smaller = lower_bound(A, A+N, B[i])-A;

        ll bigger = (C+N) - upper_bound(C, C+N, B[i]);

        

        ans += smaller*bigger;

    }

    cout << ans << endl;

    return 0;

}