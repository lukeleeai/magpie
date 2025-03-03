#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<string>

#include<iostream>

#include<cmath>

#include<algorithm>

#define debug(x) cout<<"***"<<x<<"***"<<endl;

using namespace std;

int main()

{

	int n,a[100005],light[100005],tmp=1,cnt=0;

	memset(light,0,sizeof(light));

	cin>>n;light[1]=1;

	for (int i=1;i<=n;i++)

		cin>>a[i];

	while (light[2]==0 && cnt<=n)//3 3 1 2

	{

		light[tmp]=0;

		tmp=a[tmp];

		light[tmp]=1;

		cnt++;

	}

	if (light[2]==1) cout<<cnt;

	else cout<<-1;



	return 0;

}