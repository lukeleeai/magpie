// in the name of Allah ;

#include"stdc++.h"

using namespace std ;

const int maxn = 1e5 + 10 ;

string s ;

vector < pair < int , int > > ans ;

int n ;

bool valid () 

{

	for ( int i = 0 ; i < n-1 ; i++ ) 

	{

		if ( s[i] != s[n-2-i] ) 

			return false ;

	}

	if ( s[0] != '1' || s[n-1]!= '0' ) 

		return false ; 

	return true ;

}

int main () 

{

	cin>> s ;

	n = s.size() ;

	if ( !valid () ) 

	{

		cout << -1 << endl;

		return 0 ;

	}

	int p = 0 ; 

	for ( int i = 0 ; i < n-1 ; i++ ) 

		if ( s[i] == '1' ) 

			ans.push_back ( { p , i+1 } ) , p = i+1  ;

		else

			 ans.push_back ( { p , i+1} )   ;

	for ( auto tmp : ans ) 

		cout << tmp.first+1 << " " << tmp.second+1 << endl;

}