#include "stdc++.h"



#define forn(i, n) for (int i = 0; i < int(n); ++i)

#define for1(i, n) for (int i = 1; i <= int(n); ++i)

#define ms(a, x) memset(a, x, sizeof(a))

#define F first

#define S second

#define all(x) (x).begin(),(x).end()



using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

mt19937 gen(random_device{}());



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    string st;

    cin>>st;

    if(st.find('7')!=st.npos) cout<<"Yes";

    else cout<<"No";

    return 0;

}


