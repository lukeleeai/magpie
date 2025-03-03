#include<iostream>

#include<algorithm>

#include<string>

using namespace std;

int n,i,s;

string a[200001];

int main(){

	cin>>n;

	for(i=0;i<n;i++) cin>>a[i];

	sort(a,a+n);

	s=1;

	for(i=1;i<n;i++){

		if(a[i]!=a[i-1]) s++;

	}

	cout<<s<<endl;

	return 0;

}