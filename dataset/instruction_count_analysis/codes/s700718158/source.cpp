#include "bits/stdc++.h"

using namespace std;

#define ll long long int

#define rep(i,n) for( int i = 0; i < n; i++ )

#define rrep(i,n) for( int i = n; i >= 0; i-- )

#define REP(i,s,t) for( int i = s; i <= t; i++ )

#define RREP(i,s,t) for( int i = s; i >= t; i-- )

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define INF 2000000000

#define mod 1000000007

#define INF2 1000000000000000000





int main(void)

{

    cin.tie(0);

    ios::sync_with_stdio(false);

    int N; cin >> N;

    multiset<int> st;

    int a[100010];

    set<int> st2;

    rep(i, N) {

        cin >> a[i];

        st.insert(a[i]);

        st2.insert(a[i]);

    }

    if (st2.size() > 3) {

        cout << "No" << endl;

        return 0;

    }

    int num0 = a[0];

    int num1 = a[1];

    if (st2.size() > 1) {

        auto itr = st2.begin();

        num0 = *itr;

        itr++;

        num1 = *itr;

    }

    int s = num0;

    //dump(num0);

    //dump(num1);

    int t = num0 ^ num1;

    st.erase(st.find(num0));

    st.erase(st.find(num1));

    rep(i, N - 1) {

        if (i == N - 2) {

            if (t != s) {

                cout << "No" << endl;

                return 0;

            }

            break;

        }

        auto itr = st.find(t);

        if (itr == st.end()) {

            cout << "No" << endl;

            return 0;

        }

        

        st.erase(itr);

        num0 = num1;

        num1 = t;

        t = num0 ^ num1;

        //cout << t << endl;

    }

    cout << "Yes" << endl;



    return 0;

}
