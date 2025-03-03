#include<iostream>



using namespace std;



int main()

{

    long long n,i,x,ans=0;

    long long a[100005];

    cin>>n>>x;

    for(i=0;i<n;i++)

    {

        cin>>a[i];

    }

    for(i=1;i<n;i++)

    {

        if(a[i-1]+a[i]>=x)

        {

            ans=ans+(a[i-1]+a[i]-x);

            if(a[i-1]<=x)

            {

                a[i]=x-a[i-1];

            }

            else

            {

                a[i]=0;

                a[i-1]=x;

            }

        }

    }

    cout<<ans<<endl;

    return 0;

}