#include "stdc++.h"

using namespace std;

// #define int long long   // <-----!!!!!!!!!!!!!!!!!!!



#define rep(i,n) for (int i=0;i<(n);++i)

#define rep2(i,a,b) for (int i=(a);i<(b);++i)

#define rrep(i,n) for (int i=(n)-1;i>=0;--i)

#define rrep2(i,a,b) for (int i=(a)-1;i>=b;--i)

#define chmin(a,b) (a)=min((a),(b));

#define chmax(a,b) (a)=max((a),(b));

#define all(a) (a).begin(),(a).end()

#define rall(a) (a).rbegin(),(a).rend()

#define printV(v) cout<<(#v)<<":";for(auto(x):(v)){cout<<" "<<(x);}cout<<endl;

#define printVS(vs) cout<<(#vs)<<":"<<endl;for(auto(s):(vs)){cout<<(s)<< endl;}

#define printVV(vv) cout<<(#vv)<<":"<<endl;for(auto(v):(vv)){for(auto(x):(v)){cout<<" "<<(x);}cout<<endl;}

#define printP(p) cout<<(#p)<<(p).first<<" "<<(p).second<<endl;

#define printVP(vp) cout<<(#vp)<<":"<<endl;for(auto(p):(vp)){cout<<(p).first<<" "<<(p).second<<endl;}



inline void output(){ cout << endl; }

template<typename First, typename... Rest>

inline void output(const First& first, const Rest&... rest) {

    cout << first << " "; output(rest...);

}



using ll = long long;

using Pii = pair<int, int>;

using TUPLE = tuple<int, int, int>;

using vi = vector<int>;

using vvi = vector<vi>;

using vvvi = vector<vvi>;

const int inf = 1e9;

const int mod = 1e9 + 7;

using Graph = vector<vector<int>>;



int n;

const int MAX = 1e6;

bool a[MAX];



main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(0);



    int n;

    cin >> n;

    int l = 0;

    a[0] = 1;



    rep(q, n) {

        int x;

        cin >> x;



        if (x < l) {

            cout << "No" << endl;

            continue;

        }



        cout << "Yes" << endl;

        if (x >= MAX) continue;

        for (int i = x; l <= i; --i) {

            if (a[i] == 1) {

                a[i] = 0;

                for (int j = i + 1; j <= x; ++j) {

                    a[j] = 1;

                }

                while (l < MAX && !a[l]) {

                    l++;

                }

                break;

            }

        }

    }

}