#include "stdc++.h"

using namespace std;

using ll = long long;

using pint = pair<int,int>;





const long long INFLL = 1LL << 60;

const int INFI = 1000000000;





int main() {

    int N,M; cin >> N >>M;

    vector<int> v(M);

    vector<int> p(M);

    for(int i=0;i<M;i++){

        int k; cin >> k;

        for(int j=0;j<k;j++) {

            int n; cin >> n; n--;

            v[i] = v[i]|(1<<n);

        }

    }

    for(int i=0;i<M;i++) cin >> p[i];



    ll ans=0;

    for(int bit=0; bit<(1<<N);bit++){

        bool good=true;

        for(int i=0;i<M;i++){

            int n = __builtin_popcount(bit&v[i]);

            if(n%2!=p[i]){good=false; break;}

        }

        if(good) ans++;

    }

    cout << ans << endl;

}


