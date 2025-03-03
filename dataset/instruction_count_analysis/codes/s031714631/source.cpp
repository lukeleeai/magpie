#include <cstdio>

#include <string>

#include <iostream>

using namespace std;

inline int m_min(int x,int y)

{ return x<y ? x : y; }

const int Mn(100050);

int ans[Mn];

int main()

{

	int n,m;

	string s;

	cin >>n>>m>> s;

	int cnt(0),p(n);

	while(p)

	{

		bool flag(true);

		for(int i(m_min(p,m));i>=1;--i)

			if(s[p-i]=='0')

			{

				p = p-i;

				ans[++cnt] = i;

				flag = false;

				break;

			}

		if(flag)	break;

	}

	if(p!=0)	printf("-1");

	else

		for(int i(cnt);i;--i)

			printf("%d ",ans[i]);

	return 0;

}
