#include<iostream>

using namespace std;

long cnt;

string s;

main()

{

	cin>>s;

	long now=0;

	for(int i=0;i<s.size();i++)

	{

		if(s[i]=='B')now++;

		else cnt+=now;

	}

	cout<<cnt<<endl;

}