#include "stdc++.h"

#define rep(i, n) for (int i = 0; i < (n); ++i)

#define sz(x) int(x.size())

using namespace std;

typedef long long ll;

typedef pair<int, int> P;



const ll INF = 1LL << 60;



ll N;

vector<P> red;

vector<P> blue;



int main() {

    cin >> N;

    red.resize(N);

    blue.resize(N);



    rep(i, N) {

        ll a, b;

        cin >> a >> b;

        red[i] = P(a, b);

    }

    rep(i, N) {

        ll c, d;

        cin >> c >> d;

        blue[i] = P(c, d);

    }

    sort(red.begin(), red.end());

    sort(blue.begin(), blue.end());



    // blue -> red

    ll cnt = 0;

    rep(i, N) {

        ll red_y = -1;

        ll red_idx = -1;



        rep(j, N) {

            if (blue[i].first > red[j].first && blue[i].second > red[j].second) {

                if (red_y < red[j].second) {

                    red_y = red[j].second;

                    red_idx = j;

                }

            }

        }



        if (red_y != -1) {

            red.erase(red.begin() + red_idx);

            cnt++;

        }

    }

    cout << cnt << endl;

}