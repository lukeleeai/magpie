#include <iostream>

#include <algorithm>

using namespace std;

struct a

{

	int num;

	int sum;

	bool operator < (const a &s)const

	{

		return sum<s.sum;

	}

	a(){num=0;sum=0;

	}

};

a s[100050];

int main()

{

	int N;

	cin>>N;

	for(int i=0;i<N;i++)

	{

		cin>>s[i].sum;

		s[i].num=i+1;

	}

	sort(s,s+N);

	for(int i=0;i<N;i++)

	{

		cout<<s[i].num<<" ";

	}

} 