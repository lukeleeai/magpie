#include"stdc++.h"

using namespace std;

int main() 

{

	string s;

	cin>>s;

	long long res=0;

	for(int t=0; t<(1<<(s.size()-1)); t++)

	{

		long long tmp=s[0]-'0';

		for(int i=0; i<s.size()-1; i++)

		{

			if(t&(1<<i))

				res+=tmp, tmp=0;

			tmp*=10, tmp+=s[i+1]-'0';

		}

		res+=tmp;

	}

	cout<<res;

	return 0;

}
