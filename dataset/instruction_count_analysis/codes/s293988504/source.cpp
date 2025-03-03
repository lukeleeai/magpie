#include <iostream>

#include <algorithm>

using namespace std;



int main()

{

    int n;

    int a[100010]={};

    cin>>n;

    long long ans=0;

    for(int i=0;i<n;i++)

    {

        cin>>a[i];

    }

    sort(a,a+n);

    ans-=a[0];

    for(int i=1;i<n-1;i++)

    {

        ans+=abs(a[i]);

    }

    ans+=a[n-1];

    cout<<ans<<endl;

    int cnt=0;

    for(int i=1;i<n-1;i++)

    {

        if(a[i]<0) cnt++;

        else

        {

            cout<<a[0]<<" "<<a[i]<<endl;

            a[0]-=a[i];

        }



    }



    cout<<a[n-1]<<" "<<a[0]<<endl;

    a[n-1]-=a[0];



    for(int i=1;i<=cnt;i++)

    {

        cout<<a[n-1]<<" "<<a[i]<<endl;

        a[n-1]-=a[i];

    }

    return 0;

}
