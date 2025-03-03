#include "stdc++.h"

using namespace std;

typedef long long  ll;

#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)

#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)

#define rep(i,n) FOR(i,0,n)

#define rrep(i,n) RFOR(i,0,n)

#define ALL(v) v.begin(), v.end()

#define bra(first,second) '(' << first << ',' << second << ')'

ll MOD = 1000000007;

//ll INF = 21474836470000000;

ll INF = 100100100100100100;

long double EPS = 1e-11;

long double PI = 3.141592653589793238;

template<typename T>

void remove(std::vector<T>& vector, unsigned int index){

    vector.erase(vector.begin() + index);

}



using Graph = vector<vector<ll>>;



int main(){

    ll N;

    cin >> N;

    vector<ll> A(N);

    vector<ll> index(N);

    rep(i,N){

        cin >> A[i];

        A[i]--;

        index[A[i]] = i;

    }

    set<ll> st;

    ll ans = 0;

    rrep(i,N){

        ll x = index[i];

        st.insert(x);

        vector<ll> L(2),R(2);

        L[0] = -1;L[1] = -1;R[0] = N;R[1] = N;

        auto itr = st.find(x);

        rep(j,2){

            if(itr == st.begin())break;

            itr--;

            L[j] = *itr;

        }

        itr = st.find(x);

        rep(j,2){

            itr++;

            if(itr == st.end())break;

            R[j] = *itr;

        }

        ans += (i+1) * ((R[1] - R[0])*(x - L[0]) + (R[0] - x)*(L[0] - L[1]));

    }

    cout << ans << endl;

}
