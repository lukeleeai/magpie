#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <complex>

#include <cstdio>

#include <cstring>

#include <ctime>

#include <string>

#include <vector>

#include <algorithm>

#include <cmath>

#include <sstream>

#include <utility>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef pair<int,int> pii;

#define all(c) (c).begin(), (c).end()

#define loop(i,a,b) for(ll i=a; i<ll(b); i++)

#define rep(i,b) loop(i,0,b)

#define each(e,c) for(auto&e:c)

#define pb push_back

#define eb emplace_back

#define mp make_pair

#define mt make_tuple

#define lb lower_bound

#define ub upper_bound

#ifdef DEBUG

#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<(DUMP(),__VA_ARGS__).str()<<" ["<<__LINE__<<"]"<<endl)

struct DUMP:ostringstream{template<class T>DUMP &operator,(const T&t){if(this->tellp())*this<<", ";*this<<t;return *this;}};

#else

#define dump(...)

#endif

template<class T> ostream& operator<<(ostream& os, vector<T> const& v){

    rep(i,v.size()) os << v[i] << (i+1==v.size()?"":" ");

    return os;

}



typedef double R;

typedef complex<R> P;

R const eps = 1e-8;

R const pi = acos(-1);



int main(){

    int n;

    while(cin>>n && n){

        vector<P> ps(n);

        rep(i,n){

            R x,y; cin >> x >> y;

            ps[i] = P(x,y);

        }

        int ans = 1;

        rep(i,n)rep(j,i){

            P & p = ps[i];

            P & q = ps[j];

            R d = abs(p-q)/2;

            if(d+eps > 1.0) continue;

            P m = (p+q)/R(2);

            R l = sqrt(1-d*d);

            P c = m + (p-m)/d*l*P(0,1);

            int cnt = 0;

            rep(k,n){

                if(abs(c-ps[k]) < 1.0+eps) cnt++;

                if(n-k+cnt+1 < ans) break;

            }

            ans = max(ans,cnt);

            if(ans==n) goto END;

        }

    END:;

        cout << ans << endl;

    }

}