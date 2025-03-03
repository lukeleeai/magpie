#include"stdc++.h"

using namespace std;

int main()

{

    int n,i,j,k,l,x,c=0;

    cin>>n;

    int ar[n];

    for(i=0;i<n;i++)

    {

        cin>>ar[i];

        if(ar[i]==1)

        {

            c=1;

        }

    }

    if(c==0)

    {

        cout<<"-1"<<endl;

        return 0;

    }

    else

    {

        x=1;

        for(i=0;i<n;i++)

        {

            if(ar[i]==x)

                x++;

        }

        cout<<n-x+1<<endl;

    }

}
