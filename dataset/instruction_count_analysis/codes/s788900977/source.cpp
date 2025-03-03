#include <iostream>

#include <string>



const int maxn = 5e5+7;



std::string s;

long long a[maxn];



int main(int argc, char *argv[]) {  

	std::ios::sync_with_stdio(false);

	std::cin.tie(0); 

	std::cin >> s;

	std::fill(a, a+maxn, 0);

	for (int i = 0; i < s.length(); i++) {

//		std::cout << s[i] << " \n"[i==s.length()-1];

		if (s[i] == '<') {

			a[i+1] = a[i]+1;

		}

	}

	for (int i = s.length(); i >= 0; i--) {

		if (s[i] == '>') {

			a[i] = std::max(a[i], a[i+1]+1);

		}

	}

	long long ans = 0;

	for (int i = 0; i <= s.length(); i++) {

//		std::cout << a[i] << " \n"[i==s.length()-1];

		ans += a[i];

	}

	std::cout << ans << '\n';

}