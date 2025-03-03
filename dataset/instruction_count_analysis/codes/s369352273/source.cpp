#include <iostream>

#include <string>

#include <algorithm>

using namespace std;



int eval(const string& s, int& k){

	if( s[k] == '0' || s[k] =='1' || s[k] == '2' ){

		int r = s[k] - '0';

		k++;

		return r;

	}else if( s[k] == '-' ){

		++k;

		int r = eval(s, k);

		r = 2 - r;

		return r;

	}else if( s[k] == '(' ){

		++k;

		int a = eval(s, k);

		char op = s[k++];

		int b = eval(s, k);

		++k;

		int r;

		if( op == '+' ){

			r = max(a, b);

		}else if( op == '*' ){

			r = (a * b + 1) / 2;

		}

		return r;

	}

}



int main(){

	string s;

	while( cin >> s ){

		if( s == "." ) break;

		

		int ans=0;

		for(char p='0' ; p <= '2' ; p++ ){

			for(char q='0' ; q <= '2' ; q++ ){

				for(char r='0' ; r <= '2' ; r++ ){

					string ex = s;

					for(int i=0 ; i < ex.size() ; i++ ){

						if( ex[i] == 'P' ) ex[i] = p; 

						if( ex[i] == 'Q' ) ex[i] = q;

						if( ex[i] == 'R' ) ex[i] = r;

					}

					int t=0;

					int res = eval(ex, t);

					if( res == 2 ) ans++;

				}

			}

		}

		cout << ans << endl;

	}

}