#include <iostream>

#include <vector>

#include <string>

#include <sstream>

#include <utility>

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <algorithm>

#include <istream>

#include <ostream>



#include <cstdlib>

#include <cmath>

#include <cstdio>



using namespace std;



#define fi first

#define se second

#define mkp make_pair

#define all(x) (x).begin(), (x).end()

#define pb push_back

#define rep(i,n) for(ll i=0; i < (n); ++i)

#define rrep(i,n) for(ll i=((n)-1); i >= 0; --i)



#define OPLT(T) bool operator<(const T & lop_, const T & rop_)

#define OPEQ(T) bool operator==(const T & lop_, const T & rop_)



typedef long long ll;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



istream& operator>>(istream& istr, __float128& obj) { double d; istr >> d; obj = d; return istr; };

ostream& operator<<(ostream& ostr, __float128& obj) { ostr << static_cast<double>(obj); return ostr; };



ll res[510][510];



const ll absmx = 1e9;



int main() {

	ll H, W, h, w;

	cin >> H >> W >> h >> w;

	bool flg = false;

	for(int k = 0; k < 2; k++) {

		if(h*w == 1) break;

		ll d;

		if(k == 0) {

			d = (absmx-1) / (h*w-1);

		}

		else {

			d = (absmx+1) / (h*w-1);

		}



		rep(i,510) {

			rep(j,510) {

				if(k == 0)

					res[i][j] = 1*d;

				else

					res[i][j] = -1*d;

			}

		}



		if(k == 0) {

			for(int i = h-1; i < H; i += h) {

				for(int j = w-1; j < W; j += w) {

					res[i][j] = - ((h*w-1)*d +1);

				}

			}

		}

		else {

			for(int i = 0; i < H; i += h) {

				for(int j = 0; j < W; j += w) {

					res[i][j] = (h*w-1)*d-1;

				}

			}

		}



		ll sum = 0;

		rep(i,H) {

			rep(j,W) {

				sum += res[i][j];

			}

		}

		if(sum > 0) {

			flg = true;

			break;

		}

	}



	if(flg) {

		cout << "Yes" << endl;

		rep(i,H) {

			rep(j,W) {

				if(j) cout << " ";

				cout << res[i][j];

			}

			cout << endl;

		}

	}

	else {

		cout << "No" << endl;

	}



	return 0;

}
