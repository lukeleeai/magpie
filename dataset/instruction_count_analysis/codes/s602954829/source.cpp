#include"stdc++.h"

using namespace std;

int main(){

	double a,b,c,d;

	cin>>a>>b>>c>>d;

	int x=ceil(a/d);

	int y=ceil(c/b);

	if(y>x)cout<<"No"<<endl;

	else cout<<"Yes"<<endl;

}