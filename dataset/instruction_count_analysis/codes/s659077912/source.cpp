#include "stdc++.h"

using namespace std;



#define getn int n; cin >> n

#define fori(n) for (int i = 0; i < (n); i++)

#define forj(n) for (int j = 0; j < (n); j++)

#define forifill(n,x) for (int i = 0; i < (n); i++) cin >> x[i]

#define foriprint(n,x) for (int i = 0; i < (n); i++) cout << x[i] << " "

#define all(x) (x).begin(), (x).end()

#define allr(x) (x).rbegin(), (x).rend()

#define unsync cin.sync_with_stdio(false), cin.tie(0)

#define inoutfile freopen("d:\\testcase.txt", "r", stdin);freopen("d:\\output.txt", "w", stdout)



typedef unsigned long long lng;





int main()

{

	unsync;



	int x[3];

	cin >> x[0] >> x[1] >> x[2];

	sort(x, x + 3);

	cout << ((x[0] == x[1] && x[0] == 5 && x[2] == 7) ? "YES\n" : "NO\n");

}