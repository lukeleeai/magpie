#include "stdc++.h"



using namespace std;



int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);



    int n, t=0;

    pair<int,int> v[200001];

    cin >> n;



    for (int i=1; i<=n; i++) {

        cin >> v[i].second >> v[i].first;

    }



    sort(v+1, v+1+n);



    bool ok = true;

    for (int i=1; i<=n; i++) {

        if (t+v[i].second > v[i].first) {

            ok = false;

            break;

        } else t += v[i].second;

    }



    if (ok) cout << "Yes" << endl;

    else cout << "No" << endl;

}
