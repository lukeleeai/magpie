#include<iostream>

#include<cstring>

#include<algorithm>

#include<cmath>

using namespace std;

int main()

{

	long long sx,sy,tx,ty,stx,sty;

	while(cin>>sx)

	{

		cin>>sy>>tx>>ty;

		stx=tx-sx;

		sty=ty-sy;

		for(int i=0;i<sty;i++)

		{

			cout<<'U';

		}

		for(int i=0;i<stx;i++)

		{

			cout<<'R';

		}

		for(int i=0;i<sty;i++)

		{

			cout<<'D';

		}

		for(int i=0;i<stx;i++)

		{

			cout<<'L';

		}

		cout<<'L';

		for(int i=0;i<=sty;i++)

		{

			cout<<'U';

		}

		for(int i=0;i<=stx;i++)

		{

			cout<<'R';

		}

		cout<<'D';

		cout<<'R';

		for(int i=0;i<=sty;i++)

		{

			cout<<'D';

		}

		for(int i=0;i<=stx;i++)

		{

			cout<<'L';

		}

		cout<<'U';

		cout<<endl;

	}

	return 0;

}
