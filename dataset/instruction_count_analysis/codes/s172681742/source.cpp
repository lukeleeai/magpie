#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

int main(){

	string c;

	cin>>c;

	for(int i=0;i<c.length();i++){

		if(c[i]==c[i+1]&&c[i+1]==c[i+2]) {

			cout<<"Yes"<<endl;

			return 0;

		}

	}

	cout<<"No"<<endl;

	return 0;

}