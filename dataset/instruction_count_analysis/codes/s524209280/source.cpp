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

	int n, m; scanf("%d%d", &n, &m); std::vector<int> h(n, 0);

	for(int i = 0; i < m; i++) {

		int a, b; scanf("%d%d", &a, &b); a--; b--;



		h[a]++; h[b]++;

	}

	

	for(auto v: h) {

		if(v & 1) {

			printf("NO\n");

			return 0;

		}

	}

	printf("YES\n");

	return 0;

}
