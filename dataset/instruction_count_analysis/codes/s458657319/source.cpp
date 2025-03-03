#include <iostream>

#include <stack>

using namespace std;

int max(int a,int b)

{

    if (a>b)

    {

        return a;

    }

    else

    {

        return b;

    }

}

int main()

{

    int n=0;

    cin>>n;

    int a[n];

    for(int i=0;i!=n;i++)

    {

        cin>>a[i];

    }

    int max=a[0];

    int sum=0;

    for(int i=1;i!=n;i++)

    {

        if(a[i]>max)

        {

            sum+=max;

            max=a[i];

        }

        else

        {

            sum+=a[i];

        }

    }

    if(max>=sum)

    {

        cout<<"No"<<endl;

    }

    else{

        cout<<"Yes"<<endl;

    }

}


