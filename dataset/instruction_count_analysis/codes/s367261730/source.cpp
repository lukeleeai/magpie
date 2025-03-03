#include <cstdlib>

#include <iostream>

using namespace std;



bool comp(int h1, int w1, int h2, int w2) {

	const double d1 = h1 * h1 + w1 * w1, d2 = h2 * h2 + w2 * w2;

	if(d1 != d2)

		return d1 > d2;

	else

		return h1 > h2;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	for(int h, w; cin >> h >> w, h;) {

		int ans_h = 200, ans_w = 200;

		for(int i = 1; i <= 150; ++i) {

			for(int j = i + 1; j <= 150; ++j) {

				if(comp(i, j, h, w)) {

					if(comp(ans_h, ans_w, i, j)) {

						ans_h = i;

						ans_w = j;

					}

					break;

				}

			}

		}



		cout << ans_h << " " << ans_w << endl;

	}



	return EXIT_SUCCESS;

}