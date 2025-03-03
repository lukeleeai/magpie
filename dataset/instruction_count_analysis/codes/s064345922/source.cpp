#include <iostream>

#include <string>

using namespace std;



string s;

int a[26];



int main()

{

	cin>>s;

	int l=s.length();

	for(int i=0;i<l;i++) a[s[i]-'a']=1;

	for(int i=0;i<26;i++)

		if(a[i]==0) { cout<<(char)(i+'a')<<endl; return 0; }

	cout<<"None"<<endl;

	return 0;

}