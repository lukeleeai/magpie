#include "stdc++.h"

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;



int main(){

	fast_io;

	int t;

	cin>>t;	

	int r=0;

	int *num=new int[t];

	for(int i=0;i<t;i++){

		cin>>num[i];

		if(i>=2 && ((num[i-1]>num[i-2] && num[i-1]<num[i])||(num[i-1]<num[i-2] && num[i-1]>num[i]))){

			r++;

		}

	}

	cout<<r;

	system("pause>0");

	return 0;

}