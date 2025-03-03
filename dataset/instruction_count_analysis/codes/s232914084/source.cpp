#include"stdc++.h"

using namespace std;

int main(){

	ios::sync_with_stdio(0);

	string str;

	string tmp;

	while(cin>>str){

		cin>>tmp;

		reverse(str.begin(),str.end());

		if(str==tmp) cout<<"YES"<<endl;

		else cout<<"NO"<<endl;

	}

}