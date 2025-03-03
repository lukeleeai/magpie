#include<iostream>

#include<cmath>

#include<cstring>

using namespace std;

typedef long long ll;

const int mode=1000000007;

int n;

int a[100005];

int main()

{

    ios::sync_with_stdio(false);

    int flag=0,x;

    ll sum=1;

    memset(a,0,sizeof(a));

    cin>>n;

    for(int i=0;i<n;++i)

    {

        cin>>x;

        a[x]++;

    }

    if(n&1)

    {



        for(int i=0;i<n;i+=2)

        {

            if(i==0)

            {

                if(a[0]!=1)

                {

                    flag=1;

                    break;

                }

            }else

            if(a[i]!=2)

            {

                flag=1;

                break;

            }

        }

        for(int i=1;i<=n/2;i++)

        {

            sum=((sum%mode)*2)%mode;

        }

        if(flag==1)

        {

            cout<<0<<endl;

        }else

        cout<<sum<<endl;

    }else

    {

        for(int i=1;i<n;i+=2)

        {

            if(a[i]!=2)

            {

                flag=1;

                break;

            }

        }

        for(int i=1;i<=n/2;i++)

        {

            sum=((sum%mode)*2)%mode;

        }

        if(flag==1)

        {

            cout<<0<<endl;

        }else

        cout<<sum<<endl;

    }

    return 0;

}
