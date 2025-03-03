#include "iostream"

#include "climits"

#include "list"

#include "queue"

#include "stack"

#include "set"

#include "functional"

#include "algorithm"

#include "string"

#include "map"

#include "iomanip"



using namespace std;



const long long int MOD = 1000000007;



long long int N, M, K, H, W, L, R;





int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);



	int h, w;

	cin >> H >> W >> h >> w;

	if (H%h == 0 && W%w == 0) {

		cout << "No\n";

		return 0;

	}

	cout << "Yes\n";

	for (int i = 1; i <= H; i++) {

		for (int j = 1; j <= W; j++) {

			if (i%h == 0 && j%w == 0) {

				cout << -(4000 * (h*w - 1))-1 << " ";

			}

			else {

				cout << "4000 ";

			}

		}

		cout << endl;

	}

	return 0;

}