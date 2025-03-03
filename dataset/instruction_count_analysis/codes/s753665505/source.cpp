#include <cstdio>

#include <vector>

#include <bitset>

using namespace std;





inline bool in(int a, int b, int c){

	return a <= b && b < c;

}





int main(){

	int m, n, d, s;

	while( scanf("%d%d%d", &m, &n, &d), m != 0 ){

		int sz = m * n;

		vector<bitset<626> > v(sz);

		bitset<625> used;



		int p = 0;

		for(int i = 0; i < n; ++i){

			for(int j = 0; j < m; ++j, ++p){

				v[p][p] = true;

				

				for(int k = 0; k < d; ++k){

					if( in(0, i - d + k, n) && in(0, j + k, m) ){

						v[p][(i - d + k) * m + (j + k)] = true;

					}

					if( in(0, i + k, n) && in(0, j + d - k, m) ){

						v[p][(i + k) * m + (j + d - k)] = true;

					}

					if( in(0, i + d - k, n) && in(0, j - k, m) ){

						v[p][(i + d - k) * m + (j - k)] = true;

					}

					if( in(0, i - k, n) && in(0, j - d + k, m) ){

						v[p][(i - k) * m + (j - d + k)] = true;

					}

				}



				scanf("%d", &s);

				if( s != 0 ){

					v[p][sz] = true;

				}

			}

		}



		for(int i = 0; i < sz; ++i){

			int index = -1;



			for(int j = 0; j < sz; ++j){

				if( !used[j] && v[j][i] ){

					index = j;

					used[j] = true;

					break;

				}

			}



			if( index >= 0 ){

				for(int j = 0; j < sz; ++j){

					if( j != index && v[j][i] ){

						v[j] ^= v[index];

					}

				}

			}

		}





		int ans = 1;

		for(int i = 0; i < sz; ++i){

			if( v[i][sz] && v[i].count() == 1 ){

				ans = 0;

				break;

			}

		}

		

		printf("%d\n", ans);

	}

}