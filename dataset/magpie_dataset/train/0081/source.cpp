#include <cstdio>

#include <sstream>

#include <string>

#include <algorithm>

using namespace std;



template <class F, class T>

void convert(const F &f, T &t){

	stringstream ss;

	ss << f;

	ss >> t;

}



int main(){

	int x, a, b;

	string s;

	while(scanf("%d", &x), x){

		if(x % 1111 == 0){

			puts("NA");

		}

		else{

			int ans;

			for(ans = 0; x != 6174; ++ans){

				convert(x, s);

				s.resize(4, '0');

				sort(s.begin(), s.end());

				convert(s, a);

				reverse(s.begin(), s.end());

				convert(s, b);

				x = b - a;

			}

			printf("%d\n", ans);

		}

	}

}