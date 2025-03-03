#include<iostream>

#include<cstring> 

using namespace std;

int main()

{

	char a[20];

	int n,A=0,B=0,C=0,ans=0;

	cin>>n;

	while(n--)

	{

		cin>>a;

		int len = strlen(a);

		if(a[0]=='B')

		B++;

		if(a[len-1]=='A')

		A++;

		if(a[0]=='B'&&a[len-1]=='A')

		C++;

		for(int i=0;i<len;i++)

		{

			if(a[i]=='A'&&a[i+1]=='B')

			ans++;

		}

	}

	int t;

	if(A>B) t = B;

	else

	t = A;

	if(A == C&&B == C&&C!=0)

		ans--;

	cout<<ans+t<<endl;

	return 0;

}