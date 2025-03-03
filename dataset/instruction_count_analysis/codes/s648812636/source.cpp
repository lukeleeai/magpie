#include"stdc++.h"

#define sci(a) scanf("%d", &a)

#define fto(i, a, b) for (int i = a; i <= b; ++i)

#define fdto(i, a, b) for (int i = a; i >= b; --i)

#define scii(a, b) scanf("%d %d", &a, &b)

#define ll long long

#define ff first

#define ss second

#define vi vector<int>

#define pi pair<int, int>

#define maxN 100005

#define oo 1000000007

#define mp make_pair

#define pb push_back

#define bug(a) cout << #a << "= " << a << endl;

#define bugarr(a, x, y) cout << #a << "[" << x << ", " << y << "]= "; for (int i = x; i <= y; ++i) cout << a[i] << ", "; cout << endl;

#define sz(a) (int)a.size()

#define vii vector<pi>

#define db double

#define forit(var, it) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)



using namespace std;



int n, m, a[1005], b[1005], c[1005], f[maxN];



int main() {

    //#ifndef ONLINE_JUDGE

     //   freopen("GetEverything.inp", "r", stdin);

      //  freopen("GetEverything.out", "w", stdout);

   // #endif // ONLINE_JUDGE



    scii(n, m);

    fto(i, 1, m) {

        scii(a[i], b[i]);

        fto(j, 1, b[i]) {

            int x; sci(x); x-=1;

            c[i] += (1 << x);

        }

        //cout << c[i] << "\n";

    }

    int doangioi = (1 << (n));

    fto(i, 0, doangioi) f[i] = -1;

   // cout << doangioi << "\n";

    f[0] = 0;

    fto(i, 1, m) {

        fto(j, 0, doangioi) {

            if (f[j] != -1) {

                int y = j | c[i];

                if (y != j) {

                    if (f[y] == -1) f[y] = f[j] + a[i];

                    else f[y] = min(f[y], f[j] + a[i]);

                }

            }

        }

    }

    printf("%d\n", f[doangioi-1]);



    return 0;

}
