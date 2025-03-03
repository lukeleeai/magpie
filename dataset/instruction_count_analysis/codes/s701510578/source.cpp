#include <iostream>

#include <vector>

#include <cstdlib>

long long INF = 1e18;

using namespace std;

int main(){

    int N, K;

    cin >> N >> K;

    vector<long long> a(N);

    for(int i = 0; i < N; i++) cin >> a[i];

    long long ans = INF;

    for(int i = 0; i < N; i++){

        if(i + K - 1 >= N) break;

        if(a[i] < 0 && a[i + K - 1] > 0) ans = min(ans, abs(a[i]) + abs(a[i + K - 1]) + min(abs(a[i]), abs(a[i + K - 1])));

        else ans = min(ans, max(abs(a[i]), abs(a[i + K - 1])));

    }

    cout << ans << endl;

}