#include "stdc++.h"



#define fr first

#define sc second

#define OK puts("OK");

#define pb push_back

#define mk make_pair

#define ll long long

using namespace std;





const int inf = (int)1e9 + 7;

const int N = (int)3e5 + 7;



int n,a,b;

vector <int> v;

int cnt,cnt1;



 main () {

    cin >> n >> a >> b;



    if (n + 1 < a + b || n < a || n < b) {

        cout << "-1";

        return 0;

    }

    else {

        for (int i = n - a + 1; i <= n; i ++)

            v.pb(i);



        int o = b - 1;

        if (o == 0 && a != n) {

            cout << -1 << endl;

            return 0;

        }

        if (o > 0) {

            int k = int((n - a) / o) * o + 1;



            if (((n - a + o - 1) / o) > a) {

                cout << "-1";

                return 0;

            }

            for (int j = 1; j <= ((n - a + o - 1) / o); j ++) {

                for (int i = min(n - a,(o * j)); i >= o * (j - 1) + 1; i --) {

                    v.pb(i);

                    if (i == k)

                        break;

                }

            }

        }

//

//        for (int i = a; i < v.size(); i ++) {

//            if (v[i] > v[i - 1])

//                cnt ++;

//        }

//        for (int i = 1; i < v.size(); i ++) {

//            if (v[i] < v[i - 1])

//                cnt1 ++;

//        }

//        if (cnt + 1 > a || cnt1 + 1 != b) {

//            cout << -1;

//            return 0;

//        }

        for (int i = 0; i < v.size(); i ++)

            cout << v[i] << " ";

    }

}