#include"stdc++.h"

using namespace std;

string s,a="dream",b="dreamer",c="erase",d="eraser";

int check(int x)

{

	bool flag=1;

	for(int i=0;i<a.length();i++)

	{

		if(s[x+i]!=a[i])flag=0;

	}

	if(flag)return x+a.length();

	

	flag=1;

	for(int i=0;i<b.length();i++)

	{

		if(s[x+i]!=b[i])flag=0;

	}

	if(flag)return x+b.length();

	

	flag=1;

	for(int i=0;i<c.length();i++)

	{

		if(s[x+i]!=c[i])flag=0;

	}

	if(flag)return x+c.length();

	

	flag=1;

	for(int i=0;i<d.length();i++)

	{

		if(s[x+i]!=d[i])flag=0;

	}

	if(flag)return x+d.length();

	return -1;

}

int main()

{

	cin>>s;

	reverse(s.begin(),s.end());

	reverse(a.begin(),a.end());

	reverse(b.begin(),b.end());

	reverse(c.begin(),c.end());

	reverse(d.begin(),d.end());

	for(int i=0;i<s.length();)

	{

		int nx=check(i);

		if(nx==-1){return puts("NO"),0;}

		else i=nx;

		if(i==s.length()-1)break;

	}

	puts("YES");

}