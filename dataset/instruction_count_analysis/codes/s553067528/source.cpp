#include"stdc++.h"

using namespace std;

char a[100005];

int x,y,ans;

int main()

{

    cin>>a;

    for (int i=0;i<sizeof(a);i++)

    {

    	if (x==y)

		{

		   x++;

		   if (a[i]=='p')

		     ans--;

		}

		else

		{

		    y++;

			if(a[i]=='g')

			ans++;

		}

    }

    cout<<ans<<endl;

    return 0;

}