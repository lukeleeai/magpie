#include<iostream>

#include<algorithm>

#include<queue>

using lint=int64_t;

using namespace std;



int main()

{

	int N,M;

	priority_queue<lint> que;



	cin >> N >> M;

	for(int i=0;i<N;i++)

	{

		lint A;

		cin >> A;

		que.push(A);

	}

	

	for(int i=0;i<M;i++)

	{

		lint tmp=que.top();

		que.pop();

		que.push(tmp/2);

	}



	lint ans=0;

	while(!que.empty())

	{

		ans+=que.top();

		que.pop();

	}



	cout << ans << endl;

	return 0;

}
