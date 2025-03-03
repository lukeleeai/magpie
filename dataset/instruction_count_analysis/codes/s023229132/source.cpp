#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)



int main(void){

	string s;

	cin>>s;

	int N=(int)s.size(),cnt=0;

	rep(i,N){

		if(i<=(N-1)/2){

			if(s[i]=='p')cnt--;

		}else if(s[i]=='g')cnt++;

	}

	cout<<cnt<<endl;

	return 0;

}
