#include "stdc++.h"



using namespace std;



typedef long long ll;



// esdgfjasgdfasjdlf

//fasdkjfajsdgfjkasdf

//flaskjdgfkjasdgfjkas

//fasdlkfgsljdf



#define MAXN 100010



ll x[MAXN], dif[MAXN], dag[MAXN], d[MAXN], cc[MAXN];

vector<ll> dor[MAXN];

ll answer[MAXN];

ll n, m, k;



int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)

		cin >> x[i];

	cin >> m >> k;

	for (int i = 1; i < n; i++)

		dif[i] = i;

	for (int i = 0; i < m; i++) {

		int z; cin >> z;

		swap(dif[z], dif[z - 1]);

	}

	for (int i = 1; i < n; i++)

		dag[dif[i]] = i;

	for (int i = 1; i < n; i++) {

		int v = i, cnt = 0;

		while (!d[v]) {

			d[v] = i; cc[v] = cnt++;

			dor[i].push_back(v);

			v = dag[v];

		}

	}

	for (int i = 1; i < n; i++) 

		answer[dor[d[i]][(k + cc[i]) % (int)dor[d[i]].size()]] = i;

	answer[0] = x[0];

	for (int i = 1; i < n; i++)

		answer[i] = answer[i - 1] - x[answer[i] - 1] + x[answer[i]];

	for (int i = 0; i < n; i++)

		cout << answer[i] << '\n';

	//system("pause");

	return 0;

}