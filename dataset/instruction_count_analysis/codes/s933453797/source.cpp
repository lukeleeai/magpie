#include "stdc++.h"



#define all(c) c.begin(), c.end()

#define rall(c) c.rbegin(), c.rend()



using namespace std;



typedef long long ll;



int main(){

    int n; ll ans = 0;

    cin >> n;

    vector<int> l(n+1, 0), r(n+1, 0);

    for(int i=0;i<n;i++)

        cin >> l[i] >> r[i];

    sort(rall(l));

    sort(all(r));

    for(int i=0;i<n;i++)

    {

        if(l[i] - r[i] <= 0)

            break;

        ans += l[i] - r[i];

    }

    cout << 2*ans << endl;

}
