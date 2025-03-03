#include "stdc++.h"

using namespace std;

#define ll long long

int a[200100];

int b[100100],c[100100];

int main()

{

    std::ios::sync_with_stdio(false);

    std::cin.tie(0);

    int i,j,k,m,n;

    int bb=0,cc=0;

    cin>>n;

    for(i=1; i<=n; i++)

        cin>>a[i];

    if(n%2==0)

    {

        for(i=2; i<=n; i++)

        {

            if(i%2==0)

            {

                b[++bb]=a[i];

            }

            else

                c[++cc]=a[i];

        }

    }

    else

    {

        for(i=2; i<=n; i++)

        {

            if(i%2!=0)

            {

                b[++bb]=a[i];

            }

            else

                c[++cc]=a[i];

        }

    }

    for(i=bb; i>=1; i--)

        cout<<b[i]<<' ';

    cout<<a[1]<<' ';

    for(i=1; i<cc; i++)

        cout<<c[i]<<' ';

    if(cc)

        cout<<c[cc]<<endl;

    return 0;

}
