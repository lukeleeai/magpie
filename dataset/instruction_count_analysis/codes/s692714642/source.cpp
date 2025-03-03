  #include <iostream>

#include <cstdio>

#include <cmath>

#include <string>

#include <algorithm>

#include <iomanip>

#include <cstdlib>

#include <cctype>

#define ll long long

#define PI 3.14159265358979323846

using namespace std;



int main(){

	ll x=0;

	int n,T;

	cin>>n>>T;

	ll *a=new ll[n];

	for(int i=0;i<n;i++){

		cin>>a[i];

	}

	for(int i=1;i<n;i++){

		if(abs(a[i-1]-a[i])<T){

			x+=abs(a[i-1]-a[i]);

		}

		else if(abs(a[i-1]-a[i])>=T){

			x+=T;

		}

	}

	x+=T;

	cout<<x<<endl;

	return 0;

}
