#include"stdc++.h"

using namespace std;

long long n,s[233]={2,1};

int main(){

	for (int i=2;i<=87;i++) s[i]=s[i-1]+s[i-2];

	cin>>n;

	cout<<s[n]<<endl;

	return 0;

}
