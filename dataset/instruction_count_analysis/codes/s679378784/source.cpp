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



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;



struct Pos {

    ll type, a, b;

};



map<ll, ll> mp, obr;



struct Node {

    ll val;

 

    Node() : val(0LL) {}

    Node(ll value) : val(value) {}

};

 

const ll SZ = 2e5;

ll a[SZ];

Node t[4 * SZ];

ll add[4 * SZ];



template <typename T>

class fenwick {

 public:

  vector<T> fenw;

  int n;

 

  fenwick(int _n) : n(_n) {

    fenw.resize(n);

  }

 

  void modify(int x, T v) {

    while (x < n) {

      fenw[x] += v;

      x |= (x + 1);

    }

  }

 

  T get(int x) {

    T v{};

    while (x >= 0) {

      v += fenw[x];

      x = (x & (x + 1)) - 1;

    }

    return v;

  }

 

  T get(int l, int r) {

    return get(r) - (l - 1 >= 0 ? get(l - 1) : 0);

  }

};

 

struct SegTree {

 

    ll n;

    // 1 - if sum lazyOp

    // 2 - if max, min lazyOp

 

    ll passiveEl = 0LL; // getOp(a, passiveEl) = a

 

    SegTree(ll sz) {

        n = sz;

    }

 

    void input() {

        rep(i, 0, n) {

            cin >> a[i];

        }

    }

 

    Node getOp(Node left, Node right) {

        return Node(left.val + right.val);

    }

 

    void pull(ll v) {

        t[v] = getOp(t[v * 2 + 1], t[v * 2 + 2]);

    }



    ll find_kth (ll v, ll l, ll r, ll k) {

        if (k > t[v].val)

            return -1;

        if (l == r)

            return l;

        int tm = (l + r) / 2;

        if (t[v * 2 + 1].val >= k)

            return find_kth (v * 2 + 1, l, tm, k);

        else

            return find_kth (v * 2 + 2, tm+1, r, k - t[v * 2 + 1].val);

    }



    ll findKth(ll pos) {

        // cout << "Pos : " << pos << endl;

        return find_kth(0, 0, n - 1, pos + 1);

    }

 

    void build(ll v, ll l, ll r) {

        if(l == r) {

            t[v] = Node(a[l]);

            return;

        }

 

        ll m = (l + r) / 2;

        build(v * 2 + 1, l, m);

        build(v * 2 + 2, m + 1, r);

 

        pull(v);

    }

 

    void updateEl(ll v, ll tl, ll tr, ll pos, Node val) {

        if(tl == tr) {

            t[v].val += val.val;

            return;

        }

 

        ll tm = (tl + tr) / 2;

 

        if(pos <= tm) {

            updateEl(v * 2 + 1, tl, tm, pos, val);

        } else {

            updateEl(v * 2 + 2, tm + 1, tr, pos, val);

        }

 

        pull(v);

    }

 

    Node get(ll v, ll tl, ll tr, ll l, ll r) {

 

        if(l > r) return passiveEl;

        if(tl == l && r == tr) return t[v];

 

        ll tm = (tl + tr) / 2;

 

        return getOp(get(v * 2 + 1, tl, tm, l, min(tm, r)),

                        get(v * 2 + 2, tm + 1, tr, max(tm + 1, l), r));

    }



    void updateEl(ll pos, ll val) {

        updateEl(0, 0, n - 1, pos, val);

    }

 

    Node get(ll l, ll r) {

        return get(0, 0, n - 1, l, r);

    }

 

    void build() {

        build(0, 0, n - 1);

    }

};



int main() {

    

    ll q;

    cin >> q;

    vector<Pos> inp(q);



    vll as;

    rep(i, 0, q) {

        cin >> inp[i].type;

        if (inp[i].type == 1) {

            cin >> inp[i].a >> inp[i].b;

            as.pb(inp[i].a);

        }

    }

    sort(all(as));

    rep(i, 0, as.size()) {

        mp[as[i]] = i;

        obr[i] = as[i];

    }



    fenwick<ll> fsum((ll)as.size());

    SegTree tr = SegTree(as.size());

    tr.build();



    multiset<ll> cur;

    ll cursum = 0;

    ll cnt = 0;

    for (auto i : inp) {

        if (i.type == 1) {

            cnt++;

            cursum += i.b;

            fsum.modify(mp[i.a], i.a);

            // cout << "updateEl : " << mp[i.a] << endl;

            tr.updateEl(mp[i.a], 1);

            // cout << "here sm : " << (ll)(fsum.get(0, as.size() - 1)) << endl;

        } else {

            ll med = obr[tr.findKth((cnt - 1) / 2)];

            ll ans = -fsum.get(0, mp[med]) + med * tr.get(0, mp[med]).val;

            // cout << "first part : " << -fsum.get(0, mp[med]) + med * tr.get(0, mp[med]).val << endl;

            ans += (ll)(fsum.get(0, as.size() - 1) - fsum.get(0, mp[med])) - med * ((ll)cnt - tr.get(0, mp[med]).val);

            //cout << "get : " << (ll)(fsum.get(0, as.size() - 1)) << endl;

            /// cout << "second part : " << (ll)(fsum.get(0, as.size() - 1) - fsum.get(0, mp[med])) - med * ((ll)cnt - tr.get(0, mp[med]).val) << endl;

            ans += cursum;

            cout << med << " " << ans << endl;

        }

    }







    return 0;

}