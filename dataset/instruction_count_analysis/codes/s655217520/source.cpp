#include<iostream>

#include<string>

#include<algorithm>

using namespace std;

string s[1001];

bool  cmp(string s1, string s2){

     return (s1 + s2) < (s2 + s1)? true : false;

}

int main(){

	int n,m,count=0,i,j;

	cin>>n>>m;

	

	for( i=0;i<n;i++){

		cin>>s[i];

		count++;

	}

	sort(s,s+n,cmp);

	for(i=0;i<n;i++){

		cout<<s[i];

	}

	cout<<endl; 

	return 0;

}  