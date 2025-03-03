#include <iostream>

#include <sstream>

#include <fstream>

#include <string>

#include <vector>

#include <deque>

#include <queue>

#include <stack>

#include <set>

#include <map>

#include <algorithm>

#include <functional>

#include <utility>

#include <bitset>

#include <cmath>

#include <cstdlib>

#include <ctime>

#include <cstdio> 

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)

#define rangeRep(i, n, m) for(int (i) = (n); (i) < (m); (i)++)



int canGo[100001] = {0};



class Solve {

public:

	Solve() {};

	~Solve() {};



	void solver() {

		int ans = 0;

		int n;

		std::cin >> n;

		std::vector<std::pair<int, int>> friends(n, std::make_pair(0, 0));

		rep(i, n) {

			std::cin >> friends[i].first >> friends[i].second;

			//Exclude myself

			friends[i].first--; friends[i].second--;

		}

		//Record the number of people who can go.

		for (auto& x : friends) {

			rangeRep(i, x.first, x.second+1) {

				canGo[i]++;

			}

		}

		int max = 0;

		rep(i, n+1) {

			if (canGo[i] >= i) {

				max = i;

			}

		}

		std::cout << max << std::endl;

	}

private:



};



int main() {

	Solve solve;

	solve.solver();

	return 0;

}