#include<iostream>

#include<string>

using namespace std;

int main(){

	string s;

	int k;

	cin>>k>>s;

	if(s.length()>k){

		for(int i=0;i<k;i++){

			cout<<s[i];

		}

		cout<<"..."<<endl;

	}

	else cout<<s<<endl;

}