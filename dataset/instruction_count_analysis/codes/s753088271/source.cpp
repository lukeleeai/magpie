#include "stdc++.h"

using namespace std::literals::string_literals;

using i64 = long long;

using std::cout;

using std::endl;

using std::cin;



template<typename T>

std::vector<T> make_v(size_t a){return std::vector<T>(a);}



template<typename T,typename... Ts>

auto make_v(size_t a,Ts... ts){

  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));

}



int main() {

	std::string s; cin >> s;

	int x, y; scanf("%d%d", &x, &y);



	std::vector<std::pair<char, int>> vec;

	for(int i = 0; i < s.size(); i++) {

		if(vec.empty() or vec.back().first == 'T' or vec.back().first != s[i]) vec.push_back({s[i], 1});

		else vec.back().second++;

	}



	const int pot = s.size();

	auto dp = make_v<bool>(2, 2 * s.size() + 1);

	if(vec.front().first == 'F') dp[0][pot + vec.front().second] = dp[1][pot] = true;

	else dp[0][pot] = dp[1][pot] = true;

	for(int i = (vec.front().first == 'F'), d = 0; i < vec.size(); i++) {

		if(vec[i].first == 'T') {

			d = (d + 1) % 2;

			continue;

		}



		int val = vec[i].second;

		auto to = make_v<bool>(2, dp[0].size());



		to[1 - d].swap(dp[1 - d]);

		for(int j = 0; j < dp[d].size(); j++) {

			if(!dp[d][j]) continue;

			int A = j + val, B = j - val;

			to[d][A] = to[d][B] = true;

		}

		dp.swap(to);

	}

	

	if(dp[0][pot + x] and dp[1][pot + y]) printf("Yes\n");

	else printf("No\n");

	return 0;

}
