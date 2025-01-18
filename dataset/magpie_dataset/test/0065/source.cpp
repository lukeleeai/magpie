#include<iostream>

#include<cstdio>

#include<string>

using namespace std;



int main(){

	string s;

	int k;

	cin>>k>>s;

	if(s.size()<=k) cout<<s;

	else{

		for(int i=0;i<k;i++){

			cout<<s[i];

		}

		cout<<"...";

	}

	return 0;

} 