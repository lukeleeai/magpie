#include<iostream>

using namespace std;

int main() {

	string s;

	int a,b;

	cin>>a>>b>>s;

	for (int i=0,len=s.size();i<len;++i) {

		if (i!=a&&(s[i]>'9'||s[i]<'0')) return cout<<"No"<<endl,0;

		if (i==a&&s[i]!='-') return cout<<"No"<<endl,0;

	}

	cout<<"Yes"<<endl;

	return 0;

}