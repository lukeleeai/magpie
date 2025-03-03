#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>



#define pb push_back

#define F first

#define S second

#define all(x) x.begin(), x.end()

#define debug(x) cerr << #x << " : " << x << '\n'



using namespace std;

using namespace __gnu_pbds;



typedef long long ll;

typedef long double ld;

typedef string str;

typedef pair<ll, ll> pll;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;



const ll Mod = 998244353;

const int Maxn = 1e2 + 10;

const ll Inf = 2242545357980376863LL;

const ll Log = 30;



ll n, m, a[Maxn][Maxn];



ll match[Maxn];



vector<ll> G[Maxn];



ll mk[Maxn];

bool DFS(ll u){

	if(mk[u]) return false;

	mk[u] = 1;

	for(auto adj : G[u]){

		if((match[adj] == -1) || DFS(match[adj])){

			match[adj] = u;

			return true;

		}

	}

	return false;

}



int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];

	

	for(int k = m; k > 1; k--){

		memset(match, -1, sizeof match);

		for(int i = 0; i < n; i++) G[i].clear();

		

		for(int i = 0; i < n; i++)

			for(int j = 0; j < k; j++)

				G[i].pb( (a[i][j] - 1) / m );

		for(int i = 0; i < n; i++){

			memset(mk, 0, sizeof mk);

			DFS(i);

		}

		for(int i = 0; i < n; i++)

			for(int j = 0; j < k - 1; j++)

				if( ((a[match[i]][j] - 1) / m) == i)

					swap(a[match[i]][j], a[match[i]][k - 1]);

	}

	for(int i = 0; i < n; i++){

		for(int j = 0; j < m; j++) cout << a[i][j] << ' ';

		cout << '\n';

	}

	for(int j = 0; j < m; j++)

		for(int k = 0; k < n; k++)

			for(int i = 0; i < n - 1; i++)

				if(a[i][j] > a[i + 1][j])

					swap(a[i][j], a[i + 1][j]);

	for(int i = 0; i < n; i++){

		for(int j = 0; j < m; j++) cout << a[i][j] << ' ';

		cout << '\n';

	}

	return 0;

}



/*



                                 ____              ,----..               ,----..

   ,---,                       ,'  , `.           /   /   \             /   /   \

  '  .' \                   ,-+-,.' _ |          /   .     :           /   .     :

 /  ;    '.              ,-+-. ;   , ||         .   /   ;.  \         .   /   ;.  \

:  :       \            ,--.'|'   |  ;|        .   ;   /  ` ;        .   ;   /  ` ;

:  |   /\   \          |   |  ,', |  ':        ;   |  ; \ ; |        ;   |  ; \ ; |

|  :  ' ;.   :         |   | /  | |  ||        |   :  | ; | '        |   :  | ; | '

|  |  ;/  \   \        '   | :  | :  |,        .   |  ' ' ' :        .   |  ' ' ' :

'  :  | \  \ ,'        ;   . |  ; |--'         '   ;  \; /  |        '   ;  \; /  |

|  |  '  '--'          |   : |  | ,             \   \  ',  /          \   \  ',  /

|  :  :                |   : '  |/               ;   :    /            ;   :    /

|  | ,'                ;   | |`-'                 \   \ .'              \   \ .'

`--''                  |   ;/                      `---`                 `---`

                       '---'



*/