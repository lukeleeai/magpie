#include <iostream>

#include <utility>

#include <vector>

using ll=long long;

#define rep(i,a,b) for(ll i=a;i<ll(b);i++)

#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)

#define endl "\n"

#define ALL(x) x.begin(),x.end()

#define ALLR(x) x.rbegin(),x.rend()

using namespace std;



using P=pair<ll, ll>;

vector<P> prime_factorize(ll N) {

    vector<P> res;

    for (ll a = 2; a*a <= N; a++) {

        if (N % a != 0) continue;

        ll ex = 0; // 指数



        // 割れる限り割り続ける

        while (N % a == 0) {

            ex++;

            N /= a;

        }



        // その結果を push

        res.push_back(P(a, ex));

    }



    // 最後に残った数について

    if (N != 1) res.push_back(P(N, 1));

    return res;

}



const int MAX = 1e6;



ll N, ans;

vector<ll> pCount(MAX);

int main() {

	cin >> N;



	// 素因分解

	const auto &res = prime_factorize(N);

    rep(i, 0, res.size()) {

		int a = res[i].second;



		int b = 1;

		while(1){

			a -= b;

			if(a < 0) break;

			ans++;

			b++;

		}

    }

	cout << ans << endl;



    return 0;

}
