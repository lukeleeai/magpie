#include "stdc++.h"

using namespace std;

using ll=long long;

using vi = vector<int>;

using vvi = vector<vector<int>>;

using vl = vector<ll>;

using vvl = vector<vector<ll>>;

using pl = pair<ll,ll>;

using pi = pair<int,int>;

#define all(x) x.begin(),x.end()

#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)

#define _GLIBCXX_DEBUG

const ll MOD = 1000000007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//(a+b-1)/b

//priority_queue<ll, vector<ll>, greater<ll>> q;

vector<pl> vec(0);



class SegmentTree

{

public:

    vector<ll> seg;

    ll len;

   SegmentTree(ll n){

       len = n;

       seg.resize(2 * n);

   }

    void add(ll ind,ll x){//1indexed

        ind += len;

        seg[ind] += x;

        while(true){

            ind /= 2;

            if(ind == 0)break;

            seg[ind] = seg[ind*2] + seg[ind*2+1];

			seg[ind] %= 998244353;

        }

	}

    ll get_sum(ll l,ll r){//1indexed

        ll ans=0;

        l += len; r += len;

        while(l < r){

            if(l%2 == 1){

                ans += seg[l];

                l++;

            }

            l /= 2;

            if(r%2 == 1){

                ans += seg[r-1];

                --r;

            }

            r /= 2;

        }

        return ans;

    }    

};





signed main(){

	//cout << fixed << setprecision(10);

    ll n,k; cin >> n >> k;

	SegmentTree s(200200);

	s.add(1 , 1);

	rep(i,0,k){

		ll a,b; cin >> a >> b;

		vec.push_back(pl(a,b));

	}

	rep(i,1,n+1){

		ll sum = 0;

		rep(j,0,k){

			if(i - vec[j].first < 1)continue;

			ll l = max((ll)1 , i - vec[j].second);

			ll r = i - vec[j].first + 1;

			sum += s.get_sum(l , r);

			sum %= 998244353;

		}

		s.add(i , sum);

	}

	cout << s.get_sum(n , n+1) << endl;



	return 0;

}