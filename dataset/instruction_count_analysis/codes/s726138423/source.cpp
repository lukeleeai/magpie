#include "stdc++.h"

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

#define trav(a, x) for(auto& a : x)

#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()

typedef long long ll;

typedef pair<int, int> pii;

typedef vector<int> vi;

int main( ) {

    //freopen("A.01.in","r",stdin);

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int a, b, d;

    cin >> a >> b >> d;

    cout<< ((b-a)/d + ((a%d==0 || b%d==0)?1:0)) <<endl;

    return 0;

}