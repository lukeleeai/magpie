#include "stdc++.h"

using namespace std;



int main()

{

	int n; 

	cin>>n;

	string s[n];

	for(int i=0; i<n; i++)

	{

		cin>>s[i];

		sort(s[i].begin(), s[i].end());

	}

	sort(s, s+n);

	long long cnt=0, ans=0;

	string last=s[0];

	for(int i=1; i<n; i++)

	{

		if(s[i]==last) cnt++;

		else ans+=(cnt+1)*cnt/2, last=s[i], cnt=0;

	}

	ans+=(cnt+1)*cnt/2;

	cout<<ans;

}
