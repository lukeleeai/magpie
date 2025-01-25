#include <iostream>

#include <cstdio>

#include <algorithm>

#include <string>

#include <sstream>

#include <cstdlib>



using namespace std;



#define FOR(i,a,b) for(int i=(a);i<(b);i++)

#define REP(i,n) FOR(i,0,n)





string sum(string a, string b) {

	if (a.size() > b.size()) swap(a, b);

	int c = 0;

	

	string res = "";

	REP(i, a.size()) {

		int x = a[a.size() - 1 - i] - '0' + b[b.size() - 1 - i] - '0' + c;

		res.push_back(x % 10 + '0');

		c = x / 10;

	}

	FOR(i, a.size(), b.size()) {

		int x = b[b.size() - 1 - i] - '0' + c;

		res.push_back(x % 10 + '0');

		c = x / 10;

	}

	if (c > 0) res.push_back(c + '0');

	

	reverse(res.begin(), res.end());

	return res;

}



string kake(string a, string b) {

	if (a == "0" || b == "0") return "0";

	string res = "";

	if (a.size() > b.size()) swap(a, b);

	

	string s = "0";

	REP(i, b.size()) {

		REP(j, a.size()) {

			int tmp = (a[a.size() - j - 1] - '0') * (b[b.size() - i - 1] - '0');

			if (tmp > 0) {

				stringstream ss;

				ss << tmp;

				REP(k, j) ss << "0";

				s = sum(s, ss.str());

			}

		}

		res.push_back(s[s.size() - 1]);

		s.erase(s.end() - 1);

		if (s.empty()) s = "0";

	}

	

	while (s != "0") {

		res.push_back(s[s.size() - 1]);

		

		s.erase(s.end() - 1);

		if (s.empty()) s = "0";

	}

	reverse(res.begin(), res.end());

	return res;

}



string pow(string x, int n) {

	if (n == 0) return "1";

	string res = pow(kake(x, x), n / 2);

	if (n & 1) res = kake(res, x);

	return res;

}



string jin[19] = {

	"", "Man","Oku","Cho","Kei","Gai","Jo","Jou","Ko","Kan","Sei","Sai","Gok","Ggs","Asg","Nyt","Fks","Mts"

};



int main() {

	string m;

	int n;

	

	while (cin >> m >> n, m != "0" || n) {

		string num = pow(m, n);

		int pos = (num.size() - 1) / 4 ;

		cout << num.substr(0, (num.size() - 1) % 4 + 1) << jin[pos];

		while (--pos >= 0) {

			string out = num.substr((num.size() - 1) % 4 + 1 + ((num.size() - 1) / 4 - pos - 1) * 4, 4);

			if (atoi(out.c_str()) > 0) cout << atoi(out.c_str()) << jin[pos];

		}

		puts("");

	}

}