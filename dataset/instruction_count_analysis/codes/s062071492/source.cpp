#include "stdc++.h"

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)

#define rev1(i, n) for(int i = (int)(n); i > 0; i--)

#define pb push_back

#define all(v) (v).begin(), (v).end()

#define resort(v) sort((v).rbegin(), (v).rend())

#define vi vector<int>

#define vvi vector<vector<int>>

using ll = long long;

using P = pair<int, int>;

/* ------------------------------------------------ */

ll fact(int i) {       //階乗(i <= 20 まで)

    if (i == 0) return 1;

    return (fact(i - 1)) * i;

}

ll gcd(ll a, ll b) {        //最大公約数

    if(b == 0) return a;

    return gcd(b, a % b); 

}

ll lcm(ll a, ll b) {      //最小公倍数

    return a * b / gcd(a, b);

}

int keta(ll n) {        //桁数を求める

    if(n == 0) return 1;

    int count = 0;

    while(n != 0) {

        n /= 10;

        count++;

    }

    return count;

}

ll ketasum(ll n) {    //各桁の和

    ll sum = 0;

    while(n != 0) {

        sum += n % 10;

        n /= 10;

    }

    return sum;

}

/* ------------------------------------------------ */



int main() {

    int h, w, k;

    cin >> h >> w >> k;

    vector<vector<char>> mp(h, vector<char> (w));

    vvi ans(h,vi(w,-1));

    int x = 1;

    rep(i, h) {

        rep(j, w) {

            cin >> mp[i][j];

            if(mp[i][j] == '#') {

                ans[i][j] = x;

                x++;

            }

        }

    }

    

    rep(q, 1000){

        rep(i, h) {

            rep(j, w) {

                if(ans[i][j] == -1) {

                    if(j>0&&ans[i][j-1] != -1) ans[i][j] = ans[i][j-1];

                    else if(j<w-1&&ans[i][j+1] != -1) ans[i][j] = ans[i][j+1];

                }

            }

        }

    }

    rep(q,1000){

        rep(i, h) {

            rep(j, w) {

                if(ans[i][j]==-1) {

                   if(i>0&&ans[i-1][j]!=-1) ans[i][j]=ans[i-1][j];

                   else if(i<h-1&&ans[i+1][j]!=-1)ans[i][j] = ans[i+1][j];

                }

            }

        }

    }

    rep(i, h) {

        rep(j, w) {

            cout << ans[i][j];

            if(j==w-1)cout << endl;

            else cout << ' ';

        }

    } // 確認済

    return 0;

}