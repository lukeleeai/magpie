#include<iostream>

#include<cstdio>

#include<cmath>

#include<algorithm>

#include<cstring>

#include <vector>

#include <map>

using namespace std;

long long Read() {

	long long x=0,f=1;

	char c=getchar();

	while(c<'0'||c>'9') {

		if(c=='-')f=-1;

		c=getchar();

	}

	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();

	return x*f;

}

int main() {

	int n,a,b,s=0;

	a=Read(),b=Read();

	n=b;

	while(b) {

		s++;

		b/=10;

	}

	for(int i=1; i<=s; i++) {

		a*=10;

		

	}

	n+=a;

	for(int i=1; i<=100000; i++) {

		if(i*i==n) {

			cout<<"Yes";

			return 0;

		}

	}

	cout<<"No";

	return 0;

}