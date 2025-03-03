#include <iostream>

#include <sstream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <ctime>

#include <cstring>

#include <string>

#include <vector>

#include <stack>

#include <queue>

#include <deque>

#include <map>

#include <set>

#include <bitset>

#include <numeric>

#include <utility>

#include <iomanip>

#include <algorithm>

#include <functional>

#include <unordered_map>

using namespace std;



#define REP(i, s) for (int i = 0; i < s; ++i)

#define ALL(v) (v.begin(), v.end())

#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)



template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)

{ return s << '<' << P.first << ", " << P.second << '>'; }

template<class T> ostream& operator << (ostream &s, vector<T> P)

{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }

template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)

{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }

template<class T> ostream& operator << (ostream &s, set<T> P)

{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }

template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)

{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }





template <class Abel> struct BIT {

    vector<Abel> dat;

    Abel UNITY_SUM = 0;						// to be set

    

    /* [1, n] */

    BIT(int n) { init(n); }

    void init(int n) {

        dat.resize(n + 1);

        for (int i = 0; i < (int)dat.size(); ++i) dat[i] = UNITY_SUM;

    }

    

    /* a is 1-indexed */

    inline void add(int a, Abel x) {

        for (int i = a; i < (int)dat.size(); i += i & -i)

            dat[i] = dat[i] + x;

    }

    

    /* [1, a], a is 1-indexed */

    inline Abel sum(int a) {

        Abel res = UNITY_SUM;

        for (int i = a; i > 0; i -= i & -i)

            res = res + dat[i];

        return res;

    }

    

    /* [a, b), a and b are 1-indexed */

    inline Abel sum(int a, int b) {

        return sum(b - 1) - sum(a - 1);

    }

    

    /* k-th number (k is 0-indexed) */

    int get(long long k) {

        ++k;

        int res = 0;

        int N = 1; while (N < (int)dat.size()) N *= 2;

        for (int i = N / 2; i > 0; i /= 2) {

            if (res + i < (int)dat.size() && dat[res + i] < k) {

                k = k - dat[res + i];

                res = res + i;

            }

        }

        return res + 1;

    }

    

    void print() {

        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";

        cout << endl;

    }

};





const int geta = 110000;



typedef pair<long long, long long> pll;



int N;

vector<pll> val;



long long solve() {

    sort(val.begin(), val.end(), greater<pll>());

    

    BIT<int> bit1(220000), bit2(220000);

    for (auto p : val) {

        bit1.add(p.first + geta, 1);

        bit2.add(p.second + geta, 1);

    }

    

    long long res = 0;

    long long tmp = 0;

    for (int iter = 0; iter < N; ++iter) {

        long long left = bit1.get(N - 1 - iter) - geta;

        long long right = bit2.get(iter) - geta;

        

        //cout << iter << ": " << left << ", " << right << endl;

        

        tmp += left;

        chmax(res, tmp);

        if (right < left) tmp -= right;

        else {

            if (right < 0) tmp -= right;

            chmax(res, tmp);

            break;

        }

        chmax(res, tmp);

    }

    return res * 2;

}



int main() {

    while (cin >> N) {

        val.resize(N);

        for (int i = 0; i < N; ++i) {

            cin >> val[i].first >> val[i].second;

        }

        

        long long res1 = solve();

        for (int i = 0; i < N; ++i) {

            val[i] = make_pair(-val[i].second, -val[i].first);

        }

        long long res2 = solve();

        long long res = max(res1, res2);

        cout << res << endl;

    }

}






















































