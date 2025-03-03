#include<iostream>

#include<cstdlib>

using namespace std;

int a,b,c,d;

int main(){

	cin>>a>>b>>c>>d;

	while(a>0&&c>0){

		c-=b;

		if(c<=0) {cout<<"Yes"<<endl; exit(0);} 

		a-=d;

		if(a<=0) {cout<<"No"<<endl;exit(0);}	

	}

	return 0;

}