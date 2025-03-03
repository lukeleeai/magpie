#include"stdc++.h"

using namespace std;

long long a,b;

int main()

{

	cin>>a>>b;

	if(a==1)a=14;

	if(b==1)b=14;

	if(a>b)cout<<"Alice";

	if(a<b)cout<<"Bob";

	if(a==b)cout<<"Draw";

	cout<<endl;

    return 0;

}