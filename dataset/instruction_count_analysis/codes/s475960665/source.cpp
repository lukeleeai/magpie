#include<iostream>

#include<cmath>

using namespace std;

int main()

{

    double n,d,x,i,s=0,a,b;

    cin>>n>>d;

    for(i=0;i<n;i++)

    {

        cin>>a>>b;

        x=sqrt((a*a)+(b*b));

        if(x<=d)

            s++;

    }

    cout<<s<<endl;

}
