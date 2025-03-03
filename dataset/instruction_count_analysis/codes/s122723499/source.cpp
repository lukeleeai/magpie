// In the name of God



#include "stdc++.h"



using namespace std;



int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(0);

	

	int n, m, k;

	cin >> n >> m >> k;



	int total = 0;



	vector<vector<char>> v(n, vector<char>(m));

	

	for(int i = 0; i < n; i++) {

		for(int j = 0; j < m; j++) {

			cin >> v[i][j];

			if(v[i][j] == '#') total++;

		}

	}



	function<int(int, int)> process = [&](int row, int col) {

		int ret = total;



		for(int i = 0; i < n; i++) {

			for(int j = 0; j < m; j++) {

				if(v[i][j] == '.') continue;

				bool f = false, g = false;

				if(row >> i & 1) f = true;

				if(col >> j & 1) g = true;



				ret -= (f || g);

			}

		}

		return ret;

	};



	int ans = 0;



	for(int i = 0; i < (1<<n); i++) {

		for(int j = 0; j < (1<<m); j++) {

			if(process(i, j) == k) ans++;

		}

	}



	cout << ans;





	return 0;

}
