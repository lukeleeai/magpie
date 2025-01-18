#include "stdc++.h"

#include <math.h>

using namespace std;



int a,b,c,d,gede;

int main(){

cin>>a>>b;

d=0;

for(int i=1;i<=a;i++){

	cin>>c;

	if(c>=b){

		d++;

	}

}

cout<<d;

}