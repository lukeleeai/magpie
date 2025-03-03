#include "stdc++.h"

using namespace std;

string s;

int ans=1<<30;

int main()

{

	cin>>s;

	for(int i=1;i<s.length();i++)

		if(s[i]!=s[i-1])

			ans=min(ans,max(i,int(s.length())-i));

	cout<<min(ans,int(s.length()))<<endl;

	return 0;

}