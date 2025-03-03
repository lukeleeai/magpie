#include<cstdio>

#include<iostream>

#include<cmath>

using namespace std;

int main()

{

	long long x,y,g=1,i,N=1000000000000000000;

	int flag=0;

	cin>>x>>y;

	if (x%y==0) flag=0;

	else for (i=2;g<N;i++) {

		g=i*x;

		if (g%y!=0) {

			flag=1;

			break;

		}

	} 

	if (flag)	cout<<g<<endl;

	else		cout<<"-1"<<endl;

	return 0;

 } 