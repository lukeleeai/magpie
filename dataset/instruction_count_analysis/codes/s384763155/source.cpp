#include<iostream>

#include<cstring>

using namespace std;

int main()

{

	//freopen("xx.in","r",stdin);

	string s;

	cin>>s;

	int len=s.length();

	if(s[0]^s[len-1])

	{

		if(len&1) cout<<"First"<<endl;

		else cout<<"Second"<<endl;

	}

	else

	{

		if(len&1) cout<<"Second"<<endl;

		else cout<<"First"<<endl;

	}

	return 0;

}