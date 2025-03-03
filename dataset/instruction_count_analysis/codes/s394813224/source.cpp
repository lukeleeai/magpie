#include"stdc++.h"

using namespace std;

int main()

{

	int a[4];

	for(int i=1;i<=3;i++)

	cin>>a[i];

	sort(a+1,a+3+1);

	cout<<a[1]+a[2]; 

	return 0;

}