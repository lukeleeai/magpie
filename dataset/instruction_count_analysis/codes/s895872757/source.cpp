#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

#include <sstream>

#include <fstream>

#include <set>

#include <map>



using namespace std;



class AffineCipher

{

public:

	string decode (string, vector <int> );

	vector<int> make_alpha (void);

private:

	int gcd (int, int );

	bool decide_variable (int, int, string );

	bool check_code (string );

};



int AffineCipher::gcd (int a, int b )

{

	if (a > b){

		swap(a,b);

	} // end if

	while (b % a != 0 ){

		b = b % a;

		if (a > b ){

			swap(a, b );

		} // end if

	} // end while



	return a;

}

bool AffineCipher::decide_variable (int a, int b, string str )

{

	set <char> code; 

	set <char> source;

	int i;



	for (i = 0; i < str.length(); ++i ){

		if (isalpha(str[i]) ){

			source.insert (str[i] );

		} // end if

	} // end for

	set <char>::iterator it = source.begin();



	for (; it != source.end(); ++it ){

		char c = (a*((*it) - 'a' ) + b ) % 26 + 'a';

		if (code.count (c) ){

			return false;

		}else{

			code.insert (c);

		} // end if

	} // end for



	return true;

}

bool AffineCipher::check_code (string str )

{

	const string keyword[] = { "this", "that" };



	for (int i = 0; i < sizeof(keyword)/sizeof(keyword[0]); ++i){

		if (str.find(keyword[i] ) != string::npos ){

			return true;

		} // end if

	} // end for



	return false;

}

string AffineCipher::decode (string str, vector <int> alpha )

{

	int len = str.length();

	int a, b;

	multimap <int, int> table;

 	int i;



	for (i = 0; i < alpha.size(); ++i){		

		a = alpha[i];

		for (b = 0; b < 26; ++b){

			if (!decide_variable (a, b, str ) ){

				continue;

			}else{

				table.insert (make_pair (a, b ) );

			} // end if

		} // end for

	} // end for



	string res = "";

	multimap <int, int>::iterator it = table.begin();

	for (; it != table.end(); ++it){

		a = (*it).first;

		b = (*it).second;

		res = "";

		for (i = 0; i < len; ++i){

			char c = 0;

			if (isalpha(str[i] ) ){

				c = (a*(str[i] - 'a' ) + b ) % 26 + 'a';

			}else{

				c = str[i];

			} // end if

			res += c;

		} // end for

		if (!check_code (res ) ){

			continue;

		}else{

			break;

		} // end if

	} // end for



	return res;

}

vector <int> AffineCipher::make_alpha (void)

{

	vector <int> alpha;

	int i;



	for (i = 1; i < 26; ++i){

		if (gcd(i, 26 ) == 1 ){

			alpha.push_back(i);

		} // end if

	} // end for



	return alpha;

}

	

int main()

{

	AffineCipher AC;

//	cut here before submit 

//	freopen("testcase.ac", "r", stdin);

	string str = "";

	int n;



	getline (cin, str );

	stringstream ssn(str);

	ssn >> n;

	

	vector <int> alpha = AC.make_alpha();

	int i;



	for (i = 0; i < n; ++i){

		string res = "";

		getline (cin, str );

		res = AC.decode (str, alpha );

		cout << res << endl;

	} // end for

		

	return 0;

}