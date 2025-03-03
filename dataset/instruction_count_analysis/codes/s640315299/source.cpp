#include<iostream>

#include<cmath>

using namespace std;

int c[2]={0,1};

 

int main()

{

	int n,i=0,k,t;

	int s[3000]={0};

	cin>>n;

	if(n==0)

	{

		cout<<"0"<<endl;

		return 0;

	}

	while(n!=0)

	{

		k=n%(-2);

		t=n/(-2);

		if(k<0)

		{

			k=k-(-2);

			t++;

		}	

		i++;

		n=t;

		s[i]=c[k];	

	}

	for(;i>=1;i--)

		cout<<s[i]; 

	return 0; 

}