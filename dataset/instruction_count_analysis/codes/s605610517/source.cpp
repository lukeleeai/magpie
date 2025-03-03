#include"stdc++.h"

using namespace std;

int n,a[100010];

bool cmp(int a,int b)

{

    return a>b;

}

int main()

{

    cin>>n;

    for(int i=1;i<=n;i++)

    	cin>>a[i];

    sort(a+1,a+n+1,cmp);

    for(int i=1;i<=n;i++)

	{

        if(a[i+1]<i+1)

		{

            int ans=0;

            for(int j=i+1;;j++)

            {

                if(a[j]!=i)

                    break;

                ans^=1;

            }

				

            ans|=(a[i]-i)&1;

            if(ans)

				cout<<"First"<<endl;

            else 

				cout<<"Second"<<endl;

            return 0;

        }

    }

}