#include "stdc++.h"

using namespace std;



int main(){

	int n;

	scanf("%d",&n);

	string str;

	cin>>str;

	string s="";

	for(int i=0;i<str.length();i++){

		if(s=="") s+=str[i];

		else{

			if(s[s.length()-1]!=str[i]){

				s+=str[i];

			}

		}

	}

	cout<<s.size()<<endl;

}
