#include <iostream>

#include <cstdio>

#include <cstring>

using namespace std;



long long int gcd(long long int a, long long int b){

	if(b == 0)return a;

	return gcd(b,a % b);

}



long long int lcm(long long int a, long long int b){

	return a * b / gcd(a,b);

}



int main(){

	long long int a[3], m[3], p[3] = {1,1,1}, c[3] = {0};

	while(1){

		memset(c,0,sizeof(c));

		cin >> a[0] >> m[0] >> a[1] >> m[1] >> a[2] >> m[2];

		if(!a[0])break;

		for(int i=0;i<3;i++){

			do{

			p[i] = (a[i] * p[i]) % m[i];

			//cout << "Turn " << c[i] << ": " << p[i] << endl;

			c[i] += 1;

			}while(p[i] != 1);

		}

		//cout << c[0] << c[1] << c[2] << endl;

		//int gcd = rec(c[0],rec(c[1],c[2])),

		//lcm = rec(c[0],gcd) * rec(c[1],gcd) * rec(c[2],gcd) * gcd;

			//cout << gcd << " " << lcm << endl;

		cout << lcm(lcm(c[0],c[1]),c[2]) << endl;

	}

	return 0;

}