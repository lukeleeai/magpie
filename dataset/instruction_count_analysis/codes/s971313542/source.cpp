#include "stdc++.h"

#define MAX 11000

#define ll long int

using namespace std;

 

 

int main() {

 

	map<string,int> mp;

	string s ;

	ll i,j,n,count=0,sum=0;

	

	cin >> n;

	

	for(i=0;i<n;i++)

	{

		cin >> s;

		sort(s.rbegin(), s.rend(), greater<char>());

		count += mp[s]++;

	

	}

	

	cout << count;





	

 

}