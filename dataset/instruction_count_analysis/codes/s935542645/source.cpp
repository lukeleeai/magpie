#include"stdc++.h"

using namespace std;

	string A[100001];

int main()

{

	long long N,total=0;

	cin>>N;

	map<string,bool>number;

	for(int i=0;i<N;i++)

	{

		cin>>A[i];

		number[A[i]]=false;

	}

	for(int i=0;i<N;i++)

	{

		if(number[A[i]]==false)

		{

			number[A[i]]=true;

			total+=1;

		}

		else

		{

			number[A[i]]=false;

			total-=1;

		}

	}

	cout<<total<<endl;

}