#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/rope>

 

#define ll long long

#define ll128 __uint128_t

#define ld long double

#define pll pair <ll, ll>

 

#define vll vector <ll>

#define vld vector<ld>

#define vpll vector<pll>

 

#define vvll vector <vll>

 

#define rep(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)

#define per(i, a, b) for(ll i = (ll)a - 1; i >= (ll)b; --i)

 

#define endl "\n"

#define pb push_back

#define pf push_front

 

#define all(v) (v).begin(), (v).end()

#define rall(v) (v).rbegin(), (v).rend()

 

#define sorta(v) sort(all(v))

#define sortd(v) sort(rall(v))

 

#define debug if (1)

#define log(val) debug {cout << "\n" << #val << ": " << val << "\n";}

 

#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define file(name) freopen(name".in", "r", stdin); freopen(name".out", "w", stdout);

#define FILE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

 

#define mod (ll)(1e9 + 7)

#define inf (mod * mod)

 

using namespace std;

using namespace __gnu_cxx;

using namespace __gnu_pbds;

 

ostream & operator << (ostream & out, vll & a) {

    for(auto i : a) out << i << " ";

    return out;

}

 

istream & operator >> (istream & in, vll & a) {

    for(auto &i : a) in >> i;

    return in;

}

 

int main() {

    ll q;

    cin >> q;

    ll curt, cura, cursum;

    cin >> curt >> cura >> cursum;

 

    set<pll> cur;

    cur.insert(make_pair(cura, 0));

    auto it = cur.begin();

    ll sum1 = 0, sum2 = cura, cnt1 = 0, cnt2 = 1;

    q--;

    ll num = 1;

    while(q--) {

        ll type, a, b;

        cin >> type;

        if (type == 1) {

            cin >> a >> b;

            cursum += b;

            pll newEl = make_pair(a, num);

            cur.insert(newEl);



            if (newEl < *it) {

                sum1 += newEl.first;

                cnt1++;

            } else {

                sum2 += newEl.first;

                cnt2++;

            }



            if (cur.size() % 2 == 0) {

                if (newEl < *it) {

                    it--;

                    cnt2++;

                    sum2 += it -> first;

                    cnt1--;

                    sum1 -= it -> first;

                }

            } else {

                if (*it < newEl) {

                    cnt2--;

                    sum2 -= it -> first;

                    cnt1++;

                    sum1 += it -> first;

                    ++it;

                }

            }

        } else {

            ll med = it -> first;

            ll sum = (cnt1 * med - sum1);

            sum += (sum2 - cnt2 * med);

            sum += cursum;

            cout << med << " " << sum << endl;

        }

        num++;

    }

    return 0;

}