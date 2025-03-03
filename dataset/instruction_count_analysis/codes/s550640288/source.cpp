#include<iostream>

using namespace std;

int main()

{

    long long int numlist[100000]={},sum=0,sum1,a;

    int n=0,i=0,j=0;

    cin>>n;

    for(i=0;i<n;i++)

    {

        cin>>numlist[i];

        sum+=numlist[i];

    }

    sum1=sum;

    for(i=1;i<n-1;i+=2)

    {

        sum1=sum1-2*numlist[i];

    }

    a=sum1;

    for(i=0;i<n;i++)

    {

        cout<<a<<" ";

        a=2*numlist[i]-a;

    }

    return 0;

}
