#include"stdc++.h"

using namespace std;

int main()

{

	double w,h,x,y;

	cin>>w>>h>>x>>y;

	cout<<(w*h)/2.0;

	if(x*2==w&&y*2==h)

	{

		cout<<" "<<1;

	}

	else cout<<" "<<0;

	return 0;

}