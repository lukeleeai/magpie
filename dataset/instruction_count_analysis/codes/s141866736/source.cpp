#include "stdc++.h"

using namespace std;

int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	register string st;

	register bool c=false,f=false;

	cin>>st;

	int len=st.length();

	register char ch[len];

	for(int i=0;i<len;i++)ch[i]=st[i];

	for(register int i=0;i<len;i++){

		if(ch[i]=='C')c=true;

		if(c)if(ch[i]=='F')f=true;

		if(c&&f){

			cout<<"Yes\n";

			return 0;

		}

	}

	cout<<"No\n";

	return 0;

}