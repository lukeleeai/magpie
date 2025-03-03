#include <iostream>

#define rep(a,b,c) for(int a=b;a<c;a++)

#define rep_(a,b,c) for(int a=c-1;a>=b;a--)

using namespace std;



int main()

{

	cin.sync_with_stdio(false);

	cout.sync_with_stdio(false);

	string s;

	int ans=0;

	getline(cin,s);

	rep(i,1,s.length())

		if (s[i-1]!=s[i]) ans++;

	cout << ans << endl;

}