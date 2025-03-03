#include<iostream>

#include<algorithm>

#include<vector>

using lint=int64_t;

using namespace std;



int main()

{

	int N,M;

	lint A[100010]={};

	lint sum=0;



	cin >> N >> M;

	for(int i=0;i<N;i++)

	{

		cin >> A[i];

		sum+=A[i];

	}



	vector<int> v;

	for(int i=0;i<N;i++)

	{

		while(A[i]>0)

		{

			v.push_back(A[i]-A[i]/2);

			A[i]/=2;

		}

	}



	sort(v.begin(),v.end(),greater<int>());



	lint ans=0;

	for(int i=0;i<(int)v.size() && i<M;i++)

		ans+=v[i];



	cout << max((lint)0,sum-ans) << endl;

	return 0;

}
