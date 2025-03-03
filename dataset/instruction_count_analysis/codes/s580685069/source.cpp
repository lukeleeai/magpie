#include"stdc++.h"



using namespace std;



string s;

int v = 1;



int main()

{

	cin >> s;

	if(s[s.size() - 1] == '1' || s[0] == '0')

		return cout << -1 , 0;

	for(int i = 0 ; i < s.size() - 1 ; i++)

		if(s[i] != s[s.size() - 2 - i])

			return cout << -1 , 0;

	for(int i = 0 ; i < s.size() - 1 ; i++)

	{

		cout << v << " " << i + 2 << endl;

		if(s[i] == '1')

			v = i + 2;

	}

	/*

	if(s[0] == '1' && s[1] == '1')

	{

		for(int i = 1 ; i < s.size() ; i++)

			cout << i << " " << i + 1 << endl;

	}

	else

	{

		for(int i = 2 ; i <= s.size() ; i++)

			cout << 1 << " " << i << endl;

	}*/

}