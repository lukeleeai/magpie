#include"stdc++.h"

using namespace std;

int n;

string s;

int main() {

	scanf("%d",&n);

	cin>>s;

	if((s.size())>n) {

		for(int i=0;i<n;i++)

		    printf("%c",s[i]);

		printf("...");

	}

	else

	    cout<<s;

}