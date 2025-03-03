	#include <iostream>

	#include <vector>

	#include <set>

	#include <cmath>



	using namespace std;



	int main() {

		long long int realt = 1, reala = 1;

		int n;

		cin >> n;

		for(int i = 0; i < n; i++) {

			long long int t, a;

			cin >> t >> a;

			if(reala > a || realt > t) {

				long double mula = ((long double)reala)/a;

				long double mult = ((long double)realt)/t;

				if(mula > mult) {

					long long int increase = (long long int)ceil(mula);

					realt = t*increase;

					reala = a*increase;

				}

				else {

					long long int increase = (long long int)ceil(mult);

					realt = t*increase;

					reala = a*increase;

				}

			}

			else {

				realt = t;

				reala = a;

			}

		}

		long long int ans = realt + reala;

		cout << ans << endl;

	}