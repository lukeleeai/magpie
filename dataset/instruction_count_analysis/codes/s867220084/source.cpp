#include"stdc++.h"

using namespace std;

int main() {

	int a,b;

	cin>>a>>b;

	if(a==1)

		a=123123;

	if(b==1)

		b=123123;

	if(a>b)

		printf("Alice");

	if(a<b)

		printf("Bob");

	if(a==b)

		printf("Draw");

	return 0;

}