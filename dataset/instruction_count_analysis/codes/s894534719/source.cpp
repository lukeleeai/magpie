#include<cstdio>

#include<iostream>

#include<algorithm>



using namespace std;



int main(){

	int n;

	cin>>n;

	int a[100001]={};

	for(int i=0;i<n;i++){

		cin>>a[i];

	}

	sort(a,a+n);

	int count=0,m=1;

	for(int i=0;i<n-1;i++){

		if(a[i]!=a[i+1]){

			if(m%2==1) count++;

			m=1;

		}

		if(a[i]==a[i+1]){

			m++;

		}

	}

	if(m%2==1) count++;

	cout<<count;

	

	return 0;

}