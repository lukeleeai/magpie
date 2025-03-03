#include "stdc++.h"

using namespace std;



int n;

vector<pair<int, int>> v(3, make_pair(-1, 0));



int main()

{

	scanf("%d", &n);

	for (int i = 0; i < n; i++){

		int a;

		scanf("%d", &a), a ^= i & 1;

		if (v.empty() || v.back().first != a){

			v.emplace_back(a, 1);

		}

		else v.back().second++;

	}

	int res = 0;

	for (int i = 0; i + 2 < v.size(); i++){

		res = max(res, v[i].second + v[i + 1].second + v[i + 2].second);

	}

	printf("%d\n", res);

}