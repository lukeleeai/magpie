#include <iostream>

#include <vector>

#include <algorithm>

#include <map>



using namespace std;



typedef long long ll;

typedef pair<ll, ll> P;

    

vector<int> L(100001);



int main() {



    int N , X;

    cin >> N >> X;

    for (int i = 0; i < N; i ++) {

        cin >> L[i];

    }

    for (int i = 1; i < N; i++) {

        L[i] += L[i-1];

    }

    

    int ans = 1;



    for (int i = 0; i < N; i++) {

        if (L[i] <= X) ans++;

    }

    cout << ans << '\n';

}
