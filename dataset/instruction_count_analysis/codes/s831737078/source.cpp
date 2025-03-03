#include <iostream>

#include <cstdio>

#include <cmath>

using namespace std;

int a[100005];

int main()

{

		int n;

		scanf("%d",&n);

		for(int i=1;i<=n;i++)

		{

	//		cout<<pow(2,i)<<endl;

			if(pow(2,i)>n)

			{

//				cout<<"$";

				cout<<pow(2,i-1)<<endl;

				break;

			}

		}

	

	return 0;

 } 