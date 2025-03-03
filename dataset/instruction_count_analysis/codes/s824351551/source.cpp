#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

using namespace std;



int main()

{

	// cinはscanfより基本的に遅い

	// sync_with_studio()を事前に書いておくとcinでも速度向上が期待出来る！



	bool flg = false;

	int n, p, cur;

	int curP;

	vector<int> s; 

	

	while (cin >> n >> p) {

		if (n == 0 && p == 0) {

			break;

		}

		// 初期化処理

		cur = 0;

		curP = p;

		s.clear();

		s.resize(n);



		// 現在の候補者が碗から石を取り出す

		// 番号が降ってあるわけではない！

		while (true) {

			// 現在ターンである候補者が1つ取り出す

			if (curP > 0) {

				s[cur]++;

				curP--;

			} else if (curP == 0 && s[cur] > 0) {// 手元に小石があれば全て碗の中に入れる

				curP += s[cur];

				s[cur] = 0;

			}

			

			// 条件を満たして入れば終了

			if (curP == 0) {

				flg = true;

				for (int i = 0; i < s.size(); i++) {

					if (s[i] > 0 && i != cur) {

						flg = false;// 条件満たさず

						break;

					}

				}

				if (flg) {

					cout << cur << endl;

					break;

				}

			}



			// 次の候補者へ

			cur++;

			if (cur == n) cur = 0;

		}

	}



	return 0;

}