#include<iostream>

#include<cstring>

#include<cstdio>

using namespace std;

char s[105],ans[105];

int main()

{

	cin>>s;

	int len=strlen(s),tot=0;

	for(int i=0;i<len;i++)

	{

		if(s[i]=='0')	ans[++tot]='0';

		if(s[i]=='B'&&tot>0)	tot--;

		if(s[i]=='1')	ans[++tot]='1';

	}

	for(int i=1;i<=tot;i++)

	{

		cout<<ans[i];

	}

	return 0;

}