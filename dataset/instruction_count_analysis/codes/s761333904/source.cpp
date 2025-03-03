#include<cstdio> 

#include<cmath>

#include<iostream>

using namespace std;

long long n,ans; 

int s;

int main()

{

    cin>>n;

    for(int i=sqrt(n);i>0;--i) 

    if(n%i==0)

	{

        ans=n/i;

        break;

    }

    while(ans>0)

	{

        ++s;

        ans/=10;

    }

    cout<<s<<endl;

    return 0;

}