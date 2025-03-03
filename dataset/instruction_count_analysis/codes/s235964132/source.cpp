#include "bits/stdc++.h"

using namespace std;

typedef long long ll; 

#define rep(i,x,y) for(int i=x;i<y;i++)

#define rel(i,x,y) for(int i=x-1;i>=y;i--)

#define all(x) x.begin(),x.end()

int main()

{

    cin.tie(nullptr);

    ios::sync_with_stdio(false);

    cout << fixed << setprecision(15);

    int n, m; cin >> n >> m;

    int a[1000];

    int sum = 0;

    rep(i, 0, n) { cin >> a[i]; sum += a[i]; }

    int cnt = 0;

    rep(i, 0, n) {

        if (a[i] >= (sum+4*m-1) / (4 * m)) cnt++;

        //if (a[i] >= (sum + 3) / (4 * m)) cnt++;

    }

    if (cnt >= m) cout << "Yes" << endl;

    else cout << "No" << endl;

}