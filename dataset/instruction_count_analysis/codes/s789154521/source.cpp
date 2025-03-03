#include <iostream>

#include <algorithm>

#include <cmath>

#include <vector>

using namespace std;

#define debug(x) std::cerr << #x << " = " << (x) << std::endl

typedef long long LL;

const int MAXN = 2e5+17;

char mp[100][100];

int main(int argc ,char const *argv[])

{

	#ifdef noob

	freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);

	#endif	

	int n,m;

	cin>>n>>m;

	int dap = 0;

	int k1 = ceil(1.0*n/50),k2;

	if(n>1) m-=1;

	k2 = k2=ceil(1.0*m/50);

	if(m>0) n--;

	k1 = ceil(1.0*n/50);

	while(k1--) 

	{

		n-=50;

		for (int i = 0; i < 100; ++i)

		{

			for (int j = 0; j < 3; ++j)

			{

				int tj= j+dap*3;

				if(((tj-1)%3==0)&&i&1) mp[i][tj]='.';

				else mp[i][tj]='#';

			}

		}

		if(n<0)

		{

			int tms = -1*n;

			for (int i = 0; i < 100; ++i)

			{

				for (int j = 0; j < 3; ++j)

				{

					int tj=j+dap*3;

					if(mp[i][tj]=='.'&&tms>0) 

					{

						mp[i][tj] = '#'; 

						tms--;

					}

				}

			}

			dap++;

			break;

		}

		dap++;

	}

	while(k2--) 

	{

		m-=50;

		for (int i = 0; i < 100; ++i)

		{

			for (int j = 0; j < 3; ++j)

			{

				int tj= j+dap*3;

				if(((tj-1)%3==0)&&i&1) mp[i][tj]='#';

				else mp[i][tj]='.';

			}

		}

		if(m<0)

		{

			int tms = -1*m;

			for (int i = 0; i < 100; ++i)

			{

				for (int j = 0; j < 3; ++j)

				{

					int tj=j+dap*3;

					if(mp[i][tj]=='#'&&tms>0) 

					{

						mp[i][tj] = '.'; 

						tms--;

					}

				}

			}

			dap++;

			break;

		}

		dap++;

	}

	cout<<100<<" "<<dap*3<<endl;

	for (int i = 0; i < 100; ++i)

		cout<<mp[i]<<endl;

	return 0;	

}