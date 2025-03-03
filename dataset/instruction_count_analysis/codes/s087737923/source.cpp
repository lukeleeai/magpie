#include "stdc++.h"



#define ll long long

#define ull unsigned long long

#define met(a, x) memset(a,x,sizeof(a));

#define inf 0x3f3f3f3f

#define mp make_pair;



using namespace std;

const int mod = 1e9 + 7;

const int N = 1e6 + 10;

const int M = 1e5 + 10;

int a[M + 10];



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int n;

    while (cin >> n) {

        for (int i = 1; i <= n; i++) {

            cin >> a[i];

        }

        sort(a + 1, a + 1 + n);

        if (a[n] - a[1] > 1||a[n]>=n) {

            cout << "No" << endl;

        } else {

            int cnt1 = 0, cnt2 = 0;

            for (int i = 1; i <= n; i++) {

                if (a[i] == a[n]) {

                    cnt2++;

                } else if (a[n] == a[i] + 1){

                    cnt1++;

                }

            }

            int cnt = cnt1 + cnt2 / 2;

            if (cnt1 == 0) {

                if (a[n] == n - 1 || 2*a[n]<=n) {

                    cout << "Yes" << endl;

                } else {

                    cout << "No" << endl;

                }

            } else {

                if (cnt >= a[n] && cnt2 != 1&&cnt1<a[n])

                    cout << "Yes" << endl;

                else

                    cout << "No" << endl;

            }

        }

    }

    return 0;

}


