#include "stdc++.h"

using namespace std;



int main () {

    bool d = true;

    int n;

    int a[300000];

    cin>>n;

    map <int, int> c;

    for (int i = 0; i < n; i++) {

        cin>>a[i];

        c[a[i]]++;

        if (c[a[i]] == 2) {

            d = false;

        }

    }

    if (d == false) {

        cout<<"NO";

    }

    else cout<<"YES";

    return 0;

}
