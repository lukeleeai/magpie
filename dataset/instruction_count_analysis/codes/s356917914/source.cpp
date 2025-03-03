#include <iostream>

using namespace std;

int main() {

    long long N, K, i, t, a, b;

    long long arr[100001] = {0};

    cin >> N >> K;

    for(i = 0; i < N; i++) {

        cin >> a >> b;

        arr[a] += b;

    }

    for(i = 1, t = 0; i <= 100001; i++) {

        t += arr[i];

        if(t >= K) {cout << i; break;}

    }

}