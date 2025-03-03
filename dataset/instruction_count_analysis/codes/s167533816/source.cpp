#pragma region _head



#include<iostream>

#include<fstream>

#include<bitset>

#include<string>

#include<vector>

#include<algorithm>

#include<cmath>

#include<map>

#include<set>

#include<iomanip>

#include<queue>

#include<stack>

#include<numeric>

#include<utility>

#include<regex>

#include<climits>



void Init() {

    std::cin.tie(0); std::ios::sync_with_stdio(false);

    struct Init_caller { Init_caller() { Init(); } }caller;

}



#pragma region _define



#define int LL

#define rep(i,n) for(LL (i)=0;(i)<(n);(i)++)

#define all(a) (a).begin(),(a).end()

#define size(s) ((LL)s.size())

#define F first

#define S second

#define check() cout<<"! ! !"

#define endl "\n"

#define _y() cout<<"Yes"<<endl

#define _Y() cout<<"YES"<<endl

#define _n() cout<<"No"<<endl

#define _N() cout<<"NO"<<endl

#define INT_INF INT_MAX

#define INF LLONG_MAX

#define MOD ((int)pow(10,9)+7)



#pragma endregion











#pragma region _using



using namespace std;



using LL = long long;

using st = string;

using vi = vector<int>;

using vvi = vector<vi>;

using vvvi = vector<vvi>;

using vd = vector<double>;

using vvd = vector<vd>;

using vvvd = vector<vvd>;

using vc = vector<char>;

using vvc = vector<vc>;

using vs = vector<st>;

using vb = vector<bool>;

using vvb = vector<vb>;

using vvvb = vector<vvb>;

using qi = queue<int>;

using qc = queue<char>;

using qs = queue<st>;

using si = stack<int>;

using sc = stack<char>;

using ss = stack<st>;

using pi = pair<int, int>;

using ppi = pair<pi, int>;

using mii = map<int, int>;

using mpii = map<pi, int>;

using mib = map<int, bool>;

using mci = map<char, int>;

using msb = map<st, bool>;

using vpi = vector<pi>;

using vppi = vector<ppi>;

using spi = stack<pi>;

using qpi = queue<pi>;



#pragma endregion



//4,2,8,6,1,7,3,9

int dx[] = { -1,0,0,1,-1,-1,1,1 };

int dy[] = { 0,1,-1,0,1,-1,1,-1 };





void y_n(bool p) {

    p ? _y() : _n();

}



void Y_N(bool p) {

    p ? _Y() : _N();

}



LL vmax(vi v) {

    int n = size(v);

    int MAX = 0;

    rep(i, n) {

        MAX = max(MAX, v[i]);

    }

    return MAX;

}



LL vmin(vi v) {

    int n = size(v);

    int MIN = INF;

    rep(i, n) {

        MIN = min(MIN, v[i]);

    }

    return MIN;

}



LL vsum(vi v) {

    int n = size(v);

    int sum = 0;

    rep(i, n) {

        sum += v[i];

    }

    return sum;

}



LL gcd(LL a, LL b) {

    if (b == 0) {

        swap(a, b);

    }

    LL r;

    while ((r = a % b) != 0) {

        a = b;

        b = r;

    }

    return b;

}

LL lcm(LL a, LL b) {

    return (a / gcd(a, b) * b);

}



bool is_square(int n) {

    if ((int)sqrt(n)*(int)sqrt(n) == n) {

        return true;

    }

    else {

        return false;

    }

}





bool is_prime(int n) {

    if (n == 1) {

        return false;

    }

    else {

        for (int i = 2; i*i <= n; i++) {

            if (n % i == 0) {

                return false;

            }

        }

    }

    return true;

}



void dec_num(int n, vi &v) {

    int a = 2;

    v.push_back(1);

    v.push_back(n);

    while (a*a <= n) {

        if (n%a == 0) {

            v.push_back(a);

            v.push_back(n / a);



        }

        a++;

    }

    sort(all(v));

}





void dec_prime(int n, vi &v) {

    int a = 2;

    while (a*a <= n) {

        if (n % a == 0) {

            v.push_back(a);

            n /= a;

        }

        else {

            a++;

        }

    }

    v.push_back(n);

}





int sieve_prime(LL a, LL b) {

    if (a > b)swap(a, b);

    vb s(b + 1, true);

    int cnt_a = 0, cnt_b = 0;

    for (int i = 2; i <= b; i++) {

        for (int j = 2; i*j <= b; j++) {

            s[i*j] = false;

        }

    }

    for (int i = 2; i <= b; i++) {

        if (s[i]) {

            //cout << i << " ";

            if (i < a) {

                cnt_a++;

            }

            cnt_b++;

        }

    }

    return cnt_b - cnt_a;

}





LL factorial(LL n) {

    LL a = 1, ret = 1;

    while (a < n) {

        a++;

        ret *= a;

        //ret %= MOD;

    }

    return ret;

}



vvi comb;

const int COMBMAX = 100;

void init_comb() {

    comb.resize(COMBMAX+5, vi(COMBMAX+5));

    comb[0][0] = 1;

    rep(i, COMBMAX) {

        rep(j, i + 1) {

            comb[i + 1][j] += comb[i][j];

            //comb[i + 1][j] %= MOD;

            comb[i + 1][j + 1] += comb[i][j];

            //comb[i + 1][j + 1] %= MOD;

        }

    }

}



int combination(int n, int r) {

    if (r<0 || r>n)return 0;

    else return comb[n][r];

}



#pragma endregion



vi par;



int root(int x) {

    if (par[x] == x) {

        return x;

    }

    else {

        return par[x] = root(par[x]);

    }

}



void unite(int x, int y) {

    if (root(x) == root(y)) {

        return;

    }

    else {

        par[root(x)] = root(y);

        return;

    }

}



bool same(int x, int y) {

    return root(x) == root(y);

}



struct edge {

    int to;

    int cost;

};





using ve = vector<edge>;

using vve = vector<ve>;



/*****************************************************************************/

signed main() {





    int n, m, s, t;

    cin >> n >> m >> s >> t;

    s--; t--;

    vve tree_yen(n),tree_snuke(n);

    rep(i, m) {

        int a, b, c, d;

        cin >> a >> b >> c >> d;

        a--; b--;

        tree_yen[a].push_back({ b,c });

        tree_yen[b].push_back({ a,c });

        tree_snuke[a].push_back({ b,d });

        tree_snuke[b].push_back({ a,d });

    }

    int have = 1000000000000000;

    priority_queue<pi, vpi, greater<pi>> q_yen;

    vi d_yen(n, LLONG_MAX);

    //dの初期化

    d_yen[s] = 0;

    q_yen.push({ 0,s });

    while (!q_yen.empty()) {

        pi p = q_yen.top(); q_yen.pop();

        int v = p.second;

        if (d_yen[v] < p.first)continue;

        rep(i, size(tree_yen[v])) {

            edge e = tree_yen[v][i];

            if (d_yen[e.to] > d_yen[v] + e.cost) {

                d_yen[e.to] = d_yen[v] + e.cost;

                q_yen.push({ d_yen[e.to],e.to });

            }

        }

    }

    priority_queue<pi, vpi, greater<pi>> q_snuke;

    vi d_snuke(n,LLONG_MAX);

    //dの初期化

    d_snuke[t] = 0;

    q_snuke.push({ 0,t});

    while (!q_snuke.empty()) {

        pi p = q_snuke.top(); q_snuke.pop();

        int v = p.second;

        if (d_snuke[v] < p.first)continue;

        rep(i, size(tree_snuke[v])) {

            edge e = tree_snuke[v][i];

            if (d_snuke[e.to] > d_snuke[v] + e.cost) {

                d_snuke[e.to] = d_snuke[v] + e.cost;

                q_snuke.push({ d_snuke[e.to],e.to });

            }

        }

    }

    /*rep(i, n) {

        cout << i+1 << ": yen " << d_yen[i] << " snuke " << d_snuke[i] << endl;

    }*/



    vi ans(n, INF);

    int mm = INF;

    for (int i = n - 1; i >= 0; i--) {

        mm = min(mm, d_yen[i] + d_snuke[i]);

        ans[i] = mm;

    }

    rep(i, n) {

        cout << have - ans[i] << endl;

    }

    return 0;

}
