#include"stdc++.h"

using namespace std;

int main(){

	int n,h[111111]={};

	cin>>n;

	int a,b;

	for(int i=0;i<n;i++){

		cin>>a>>b;

		h[a]++;

		h[b+1]--;

	}

	int ma=0;

	for(int i=1;i<=n+1;i++){

		h[i]+=h[i-1];

		if(i<=h[i]+1)ma=max(ma,i-1);

	}

	cout<<ma<<endl;

	return 0;

}


