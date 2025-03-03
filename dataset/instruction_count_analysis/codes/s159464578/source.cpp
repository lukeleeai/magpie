#include<iostream>

#include<string>

#include<algorithm>

using namespace std;

int k,L,l;

string S,s[100005];

int main()

{

	cin>>S>>k; 

	L=S.size();

	for(int i=1;i<=5;i++)

	  for(int j=0;j<=L-i;j++)

		s[l++]=S.substr(j,i);

	sort(s,s+l);

	l=unique(s,s+l)-s;

	cout<<s[k-1];

	return 0;

}