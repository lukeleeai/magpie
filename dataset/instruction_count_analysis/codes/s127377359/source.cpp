#include<iostream>

#include<iomanip>

using namespace std;

int main()

{

	double a,b,c,d;

	cin>>a>>b>>c>>d;

	cout<<fixed<<setprecision(6)<<a*b/2.0<<" ";

	if(c==a/2.0&&d==b/2.0) cout<<"1"<<endl;

	else cout<<"0"<<endl;

	return 0;

}